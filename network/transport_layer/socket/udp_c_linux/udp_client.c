#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> /* netbd.h is needed for struct hostent =) */

#define PORT 9000 /* Open Port on Remote Host */
#define MAXDATASIZE 100 /* Max number of bytes of data */

int main(int argc, char *argv[])
{
    int fd; /* files descriptors */
    char sendbuf[MAXDATASIZE];
    struct hostent *he; /* structure that will get information about remote host */
    struct sockaddr_in server,client; /* server's address information */

    if (argc !=2) { /* this is used because our program will need two argument (IP address and a message */
        printf("Usage: %s \n",argv[0]);
        exit(1);
    }

    if ((he=gethostbyname(argv[1]))==NULL){ /* calls gethostbyname() */
        printf("gethostbyname() error\n");
        exit(1);
    }

    if ((fd=socket(AF_INET, SOCK_DGRAM, 0))==-1){ /* calls socket() */
        printf("socket() error\n");
        exit(1);
    }

    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT); /* htons() is needed again */
    server.sin_addr = *((struct in_addr *)he->h_addr); /*he->h_addr passes "*he"'s info to "h_addr" */

    socklen_t len;
    len=sizeof(struct sockaddr_in);

    while (1) {
        printf("input message:");
        scanf("%s", sendbuf);
        sendto(fd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *)&server, len);
        if(sendbuf[0]=='q' && sendbuf[1]=='\0')
            break;
    }

    close(fd); /* close fd */
}
