/* Designed to test a doubly queue.
 * QUEUEMAX is 5, so Maxsize is 4.
*/
#include <stdio.h>
#include "queue.h"

void print_all(QueueType *queue)
{
    printf("\nLength: %d. All data:\n", Get_Length_Queue(queue));
    Traverse_Queue(queue);
}

void push(QueueType *queue, int n){
    int index;
    DATA data;

    for(index=0; index<n; index++){
        printf("\nInput data (id  name  age): \n");
        scanf("%s%s%d", data.id, data.name, &data.age);
        Push_Queue(queue, data);
    }

    print_all(queue);
}

void pop(QueueType *queue, int n){
    int index;
    DATA data;

    printf("\nPop!!!\n");
    for(index=0; index<n; index++){
        data = Pop_Queue(queue);
        printf("(%s, %s, %d)\n", data.id, data.name, data.age);
    }

    print_all(queue);
}

void get_front(QueueType *queue){
    DATA data;

    printf("\nGet Front!!!\n");
    data = Get_Front_Queue(queue);
    printf("(%s, %s, %d)\n", data.id, data.name, data.age);
}

int main()
{
    DATA data;
    QueueType *queue;
    int index;

    queue = Init_Queue();
    print_all(queue);

    if(NULL != queue){
        pop(queue, 2);

        push(queue, 3);

        get_front(queue);

        printf("\nTest for <Is_Empty_Queue()>.\n");
        for(index=0; index<2; index++){
            Pop_Queue(queue);
        }

        printf("\nTest for <Is_Full_Queue()>.");
        push(queue, 3);
    }
    printf("\n");

    Free_Queue(queue);
    return 0;
}
