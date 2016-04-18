#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackType *Init_Stack()
{
    DATA data = {"0", "0", 0};
    StackType *stack;
    stack = (StackType *)malloc(sizeof(StackType));

    if(NULL == stack){
        printf("Fail to allocate memory for a new Node!\n");
        return NULL;
    }

    stack->data[0] = data;
    stack->top = 0;
    printf("\nInput data (id  name  age). Quit when id=0. \n");
    while(1){
        fflush(stdin);
        scanf("%s", data.id);
        if(data.id[0]=='0' && data.id[1]=='\0')
            break;
        scanf("%s%d", data.name, &data.age);
        stack = Push_Stack(stack, data);
    }

    if(!Is_Empty_Stack(stack))
        printf("\nStack generated!\n");
    else
        printf("\nStack empty!\n");

    return stack;
}

//先把栈顶上移, 再压入数据
StackType *Push_Stack(StackType *stack, DATA data)
{
    if(Is_Full_Stack(stack)){
        printf("Failed! Stack is full!\n");
    }else{
        //++stack->top;
        stack->data[++stack->top] = data;
    }
    return stack;
}

DATA Pop_Stack(StackType *stack)
{
    if(Is_Empty_Stack(stack)){
        printf("Failed! Stack is empty!\n\n");
        exit(0);
    }
    return stack->data[stack->top--];
}

DATA Get_Top_Stack(StackType *stack)
{
    if(Is_Empty_Stack(stack)){
        printf("Failed! Stack is empty!\n\n");
        exit(0);
    }
    return stack->data[stack->top];
}

int Is_Empty_Stack(StackType *stack)
{
    return (EMPTY == stack->top);
}

int Is_Full_Stack(StackType *stack)
{
    return (STACKSIZE == stack->top);
}

int Get_Length_Stack(StackType *stack)
{
    return stack->top;
}

int Clear_Stack(StackType *stack)
{
    stack->top = 0;
    return 1;
}

int Free_Stack(StackType *stack)
{
    if(NULL != stack){
        Clear_Stack(stack);
        free(stack);
    }
    return 1;
}

void Traverse_Stack(StackType *stack)
{
    int index;
    for(index=stack->top; index>0; index--){
        printf("index %d:\t(%s, %s, %d)\n", index, stack->data[index].id, stack->data[index].name, stack->data[index].age);
    }
}
