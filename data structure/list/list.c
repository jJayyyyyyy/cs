#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*----------------------------------------------*/
//
ListType *Init_List(ListType *head)
{
    DATA data;
    head = NULL;

    printf("Please input List Data with format (id  name  age), quit when id=0. \n");
    while (1) {
        fflush(stdin);
        scanf("%s", data.id);
        if(data.id[0]=='0' && data.id[1]=='\0')
            break;

        scanf("%s%d", data.name, &data.age);
        head = Add_after_End(head, data);
    }

    if(NULL != head)
        printf("\nList generated!\n");

    return head;
}

int Free_List(ListType *head)
{
    ListType *p, *q;

    p = head;
    while(NULL != p){
        q = p->next;
        free(p);
        p = q;
    }

    return 1;
}

void Traverse_List(ListType *head)
{
    ListType *pTraverse;
    DATA data;

    pTraverse = head;
    if(NULL == pTraverse){
        printf("\nList empty!\n");
    }else{
        printf("\nAll the data are as follows.\n");
        while(NULL != pTraverse){
            data = pTraverse->data;
            printf("(%s, %s, %d)\n", data.id, data.name, data.age);
            pTraverse = pTraverse->next;
        }
    }
}


/*----------------------------------------------*/
//
ListType *Add_after_End(ListType *head, DATA data)
{
    ListType *node, *pFind;

    node = (ListType *)malloc(sizeof(ListType));
    if(NULL == node){
        printf("Fail to allocate memory for a new Node!");
        return head;
    }

    node->data = data;
    node->next = NULL;
    if(NULL == head){
        head = node;
        return head;
    }

    pFind = head;
    while(NULL != pFind->next){
        pFind = pFind->next;
    }
    pFind->next = node;

    return head;
}

ListType *Add_after_Head(ListType *head, DATA data)
{
    ListType *node;

    node = (ListType *)malloc(sizeof(ListType));
    if(NULL == node){
        printf("Fail to allocate memory for a new Node!");
        return head;
    }

    node->data = data;
    node->next = head;
    head = node;

    return head;
}

ListType *Find_Node_with_ID(ListType *head, char id[])
{
    ListType *pFind;

    pFind = head;
    while(NULL != pFind){
        if(0 == strcmp(pFind->data.id, id)){
            printf("Node found: %s, %s, %d\n", id, pFind->data.name, pFind->data.age);
            return pFind;
        }
        pFind = pFind->next;
    }

    printf("No matching ID!\n");
    return NULL;
}

ListType *Insert_after_ID(ListType *head, char id[])
{
    ListType *node, *pFind;

    node = (ListType *)malloc(sizeof(ListType));
    if(NULL == node){
        printf("Fail to allocate memory for a new Node!");
        return head;
    }

    pFind = Find_Node_with_ID(head, id);
    if(NULL == pFind){
        free(node);
        return head;
    }

    printf("\nInput the Data of Node (id  name  age): ");
    scanf("%s%s%d", node->data.id, node->data.name, &node->data.age);

    node->next = pFind->next;
    pFind->next = node;
    printf("Node inserted!\n");

    return head;
}

//Delete the first ID-matching Node
ListType *Delete_Node_with_ID(ListType *head, char id[])
{
    ListType *pID_Node, *pFind;

    pID_Node = head;
    pFind = head;

    if(0 == strcmp(pFind->data.id, id)){
        head = head->next;
        free(pFind);
        printf("\nHead deleted\n");
        return head;
    }

    while(NULL != pFind){
        pFind = pFind->next;
        if(NULL == pFind)   break;

        if(0 == strcmp(pFind->data.id, id)){
            pID_Node->next = pFind->next;
            free(pFind);
            printf("\nNode deleted\n");
            return head;
        }else{
            pID_Node = pFind;
        }
    }

    printf("\nNode not found, failed to delete\n");
    return head;
}

int Length_of_List(ListType *head)
{
    ListType *pFind;
    int count = 0;

    pFind = head;
    while(NULL != pFind){
        count++;
        pFind = pFind->next;
    }

    return count;
}
