#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//FIFO singly queue
QueueType *Init_Queue()
{
    QueueType *queue;
    queue = (QueueType *)malloc(sizeof(QueueType));
    DATA data;

    if(NULL == queue){
        printf("Fail to allocate memory for a new Node!\n");
        return NULL;
    }

    queue->front = 0;
    queue->rear = 0;

    printf("\nInput data (id  name  age). Quit when id=0. \n");
    while(1){
        fflush(stdin);
        scanf("%s", data.id);
        if(data.id[0]=='0' && data.id[1]=='\0')
            break;
        scanf("%s%d", data.name, &data.age);
        queue = Push_Queue(queue, data);
    }

    if(!Is_Empty_Queue(queue))
        printf("\nQueue generated!\n");
    else
        printf("\nQueue empty!\n");

    return queue;
}

void Traverse_Queue(QueueType *queue)
{
    int i;
    for(i=queue->front; i<queue->rear; i++){
        printf("(%s, %s, %d)\n", queue->data[i].id, queue->data[i].name, queue->data[i].age);
    }
}

//push new element to the rear of queue
QueueType *Push_Queue(QueueType *queue, DATA data)
{
    if(Is_Full_Queue(queue)){
        printf("\nFailed! Queue is full!\n");
    }else{
        queue->data[queue->rear++] = data;
    }

    return queue;
}

//pop element from the front of queue
DATA Pop_Queue(QueueType *queue)
{
    if(Is_Empty_Queue(queue)){
        printf("Failed! Queue is empty!\n");
        exit(0);
    }

    return (queue->data[queue->front++]);
}

DATA Check_Back_Queue(QueueType *queue)
{
    if(Is_Full_Queue(queue)){
        printf("Failed! Queue is full!\n");
        exit(0);
    }

    return (queue->data[queue->rear-1]);
}

DATA Check_Front_Queue(QueueType *queue)
{
    if(Is_Empty_Queue(queue)){
        printf("Failed! Queue is empty!\n");
        exit(0);
    }

    return (queue->data[queue->front]);
}

int Is_Empty_Queue(QueueType *queue)
{
    return (queue->front == queue->rear);
}

int Is_Full_Queue(QueueType *queue)
{
    return (QUEUEMAX == queue->rear);
}

int Get_Length_Queue(QueueType *queue)
{
    return (queue->rear - queue->front);
}

int Free_Queue(QueueType *queue)
{
    if(NULL != queue)
        free(queue);
    return 1;
}
