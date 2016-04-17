typedef struct{
    char id[15];
    char name[20];
    int age;
}DATA;

typedef struct Node{
    DATA data;
    struct Node *next;
}ListType;

ListType *Add_after_End(ListType *head, DATA data);

ListType *Add_after_Head(ListType *head, DATA data);

ListType *Find_Node_with_ID(ListType *head, char id[]);

ListType *Insert_after_ID(ListType *head, char id[]);

ListType *Delete_Node_with_ID(ListType *head, char id[]);

int Length_of_List(ListType *head);


ListType *Init_List();

int Free_List(ListType *head);

void Traverse_List(ListType *head);
