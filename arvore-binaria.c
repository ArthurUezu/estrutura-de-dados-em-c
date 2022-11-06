#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int number;
    struct listNode *left;
    struct listNode *right;
} listNode;

listNode* createNode(int value){
    listNode* newListNode = malloc(sizeof(listNode));
    newListNode->number = value;
    newListNode->left = NULL;
    newListNode->right = NULL;
    return newListNode;
}

listNode* insertInTree(int value, listNode* list){
    listNode* head = list;
    if(list == NULL){
        return createNode(value);
    }
    if(list->number > value){
        list->left = insertInTree(value, list->left);
    }
    else{
        list->right = insertInTree(value, list->right);
    }
    return head;
}

void printTree(listNode *list){
    if (list != NULL){
        printTree(list->left);
        printf("%d \n", list->number);
        printTree(list->right);
    }
}

void cleanTree(listNode *list){
    if(list != NULL){
        cleanTree(list->left);
        cleanTree(list->right);
        free(list);
    }
}

int main(){
    listNode* arvore = NULL;
    
    arvore = insertInTree(5, arvore);
    arvore = insertInTree(7, arvore);
    arvore = insertInTree(4, arvore);
    arvore = insertInTree(1, arvore);

    printTree(arvore);
    cleanTree(arvore);
    return 0;
}