#define QUEUEMAX 5

typedef struct{
    char id[15];
    char name[20];
    int age;
}DATA;

typedef struct{
    DATA data[QUEUEMAX];
    int front;
    int rear;
}QueueType;


QueueType *Init_Queue();

void Traverse_Queue(QueueType *queue);

QueueType *Push_Queue(QueueType *queue, DATA data);

DATA Pop_Queue(QueueType *queue);

DATA Get_Front_Queue(QueueType *queue);

int Get_Length_Queue(QueueType *queue);

int Is_Empty_Queue(QueueType *queue);

int Is_Full_Queue(QueueType *queue);

int Free_Queue(QueueType *queue);
