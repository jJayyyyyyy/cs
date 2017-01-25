//  循环队列，避免 '虚满'
//  先入队，队尾再加1.先出队，队首再加1，与wiki-zh-cn相同
//  MAX = n，按n个空格来算最多只能用到n-1个空格
//  如果不出队，最后一个格子无法使用

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
    //初始化时先把不能用到的这个归零，防止意外读到乱码
    //只有这个没有被自动初始化为0
    queue->data[QUEUEMAX-1].id[0] = 0;
    queue->data[QUEUEMAX-1].name[0] = 0;
    queue->data[QUEUEMAX-1].age = 0;

    printf("\nInput data (id  name  age). Quit when id=0. \n");
    while(1){
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
    //i is a temp_front
    int i = queue->front;

    //判断是否为空(为空表示遍历完成)
    while((i)%QUEUEMAX != queue->rear){
        printf("(%s, %s, %d)\n", queue->data[i].id, queue->data[i].name, queue->data[i].age);
        i = (i + 1) % QUEUEMAX;
    }
}

//push new element to the rear of queue
QueueType *Push_Queue(QueueType *queue, DATA data)
{
    if(Is_Full_Queue(queue)){
        printf("\nFailed! Queue is full!\n");
    }else{
        queue->data[queue->rear] = data;
        queue->rear = (queue->rear + 1) % QUEUEMAX;
    }

    return queue;
}

//pop element from the front of queue
DATA Pop_Queue(QueueType *queue)
{
    DATA data;

    if(Is_Empty_Queue(queue)){
        printf("Failed! Queue is empty!\n");
        exit(0);
    }else{
        data = queue->data[queue->front];
        queue->front = (queue->front + 1) % QUEUEMAX;
    }

    return data;
}

DATA Get_Front_Queue(QueueType *queue)
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
    return ((queue->rear+1)%QUEUEMAX == queue->front);
}

int Get_Length_Queue(QueueType *queue)
{
    return (queue->rear - queue->front + QUEUEMAX) % QUEUEMAX;
}

int Free_Queue(QueueType *queue)
{
    if(NULL != queue)
        free(queue);
    return 1;
}
