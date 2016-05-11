#include <stdio.h>
#include <string.h>
#include <unistd.h> /* for close() */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 9000/* Port that will be opened */
#define MAXDATASIZE 100 /* Max number of bytes of data */

main()
{
    int sockfd; /* socket descriptors */
    struct sockaddr_in server; /* server's address information */
    struct sockaddr_in client; /* client's address information */
    socklen_t sin_size;
    int num;
    char recvmsg[MAXDATASIZE]; /* buffer for message */
    char sendmsg[MAXDATASIZE];
    char condition[] = "quit";

    /* Creating UDP socket */
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        /* handle exception */
        perror("Creating socket failed.");
        exit(1);
    }

    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        /* handle exception */
        perror("Bind error.");
        exit(1);
    }

    sin_size=sizeof(struct sockaddr_in);
    while (1) {
        num = recvfrom(sockfd,recvmsg,MAXDATASIZE,0,(struct sockaddr *)&client,&sin_size);

        if (num < 0){
            perror("recvfrom error\n");
            exit(1);
        }

        recvmsg[num] = '\0';
        if(recvmsg[0]=='q' && recvmsg[1]=='\0'){
            printf("Client Quit!\n");
            break;
        }
        printf("You got a message <%s> from %s\n", recvmsg, inet_ntoa(client.sin_addr) ); /* prints client's IP */
    }

    close(sockfd); /* close listenfd */
}
