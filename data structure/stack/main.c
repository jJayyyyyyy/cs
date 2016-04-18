#include <stdio.h>
#include "stack.h"

void print_all(StackType *stack)
{
    printf("\nLength: %d. All data:\n", Get_Length_Stack(stack));
    Traverse_Stack(stack);
}

void push(StackType *stack, int n){
    int index;
    DATA data;

    for(index=0; index<n; index++){
        printf("\nInput data (id  name  age): \n");
        scanf("%s%s%d", data.id, data.name, &data.age);
        Push_Stack(stack, data);
    }
    print_all(stack);
}

void pop(StackType *stack, int n){
    int index;
    DATA data;

    printf("\nPop!!!\n");
    for(index=0; index<n; index++){
        data = Pop_Stack(stack);
        printf("(%s, %s, %d)\n", data.id, data.name, data.age);
    }

    print_all(stack);
}

void get_top(StackType *stack){
    DATA data;

    printf("\nGet Top!!!\n");
    data = Get_Top_Stack(stack);
    printf("(%s, %s, %d)\n", data.id, data.name, data.age);
}

int main()
{
    char a[15]={0,0,0,1};

    StackType *stack;
    DATA data;
    int index;

    stack = Init_Stack();
    print_all(stack);

    if(NULL != stack){
        push(stack, 1);

        pop(stack, 2);

        get_top(stack);

        pop(stack, 3);
    }

    return 0;
}
