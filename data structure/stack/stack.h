#define STACKSIZE 5
#define EMPTY 0

typedef struct{
    char id[15];
    char name[15];
    int age;
}DATA;

typedef struct stack{
    DATA data[STACKSIZE+1];
    int top;
}StackType;

StackType *Init_Stack();

StackType *Push_Stack(StackType *stack, DATA data);

DATA Pop_Stack(StackType *stack);

DATA Get_Top_Stack(StackType *stack);

int Is_Empty_Stack(StackType *stack);

int Is_Full_Stack(StackType *stack);

int Get_Length_Stack(StackType *stack);

int Clear_Stack(StackType *stack);

int Free_Stack(StackType *stack);

void Traverse_Stack(StackType *stack);
