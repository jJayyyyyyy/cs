#include <stdio.h>
#include "list.h"

//Single-linked List
int main(){
    ListType *head;
    char id[15]={0};

    //generate and init a list
    head = Init_List();

    //output the list, for test-use
    Traverse_List(head);

    if(NULL != head){
        printf("\nFind Node with ID: ");
        scanf("%s", id);
        Find_Node_with_ID(head, id);

        printf("\nInsert Node after the input ID: ");
        scanf("%s", id);
        head = Insert_after_ID(head, id);
        Traverse_List(head);


        printf("\nDelete Node ID: ");
        scanf("%s", id);
        head = Delete_Node_with_ID(head, id);
        Traverse_List(head);
    }

    if(Free_List(head)){
        printf("\nMemory freed!\n\n");
    }

    return 0;
}
