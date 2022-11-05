#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int number;
    struct listNode *next;
} listNode;


listNode *addToListEnd(int value, listNode *list){
    listNode* head = list;

    listNode* newListNode = malloc(sizeof(listNode));
    newListNode->number = value;
    newListNode->next = NULL;

    if(list == NULL){
        return newListNode;
    }

    while(list->next != NULL){
        list = list->next;
    }

    list->next = newListNode;
    return head;
}

listNode *addToListStart(int value, listNode *list){
    listNode* head = list;

    listNode* newListNode = malloc(sizeof(listNode));
    newListNode->number = value;
    
    if(list == NULL){
        return newListNode;
    }

    newListNode->next = list;
    return newListNode;
}

listNode *removeFromListStart(listNode *list){
    if(list->next==NULL){
        free(list);
        return NULL;
    }

    listNode* head = list->next;
    free(list);
    return head;
}

listNode *removeFromListEnd(listNode *list){
    if(list->next == NULL){
        free(list);
        return NULL;
    }

    listNode* head = list;
    listNode* prev = list;
    list = list->next;
    
    while(list->next!=NULL){
        prev = prev->next;
        list = list->next;
    }
    
    free(list);
    prev->next = NULL;
    return head;
}

void printList(listNode* list){
    while(list!=NULL){
        printf("%d\n",list->number);
        list = list->next;
    }
    putchar('\n');
}
void cleanList(listNode* list){
    while(list!=NULL){
        list = removeFromListStart(list);
    }
}

int main(){
    listNode* list = NULL;
    list = addToListEnd(1,list);
    list = addToListEnd(2,list);
    list = addToListEnd(3,list);
    list = addToListEnd(4,list);
    list = addToListStart(81, list);
    list = addToListStart(21, list);
    printList(list);
    list = removeFromListStart(list);    
    printList(list);
    list = removeFromListEnd(list);
    list = removeFromListEnd(list);
    printList(list);
    cleanList(list);
    // eh normal vir um valor nadave no print abaixo, pq eh lixo de sistema agora
    printList(list);
    return 0;
}