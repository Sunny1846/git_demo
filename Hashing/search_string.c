#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define m 10000

typedef struct Node{
    char key[MAX];
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* T[m];

Node* makeNode(char* k){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->key, k);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

int h(char* k){
    int l = strlen(k);
    int h = 0;
    for(int i = 0; i < l; i++)
        h = (h*256 + k[i]) % m;
    return h;
}

Node* Find_BST(Node* r, char* k){
    if(r == NULL)
        return NULL;
    int c = strcmp(r->key, k);
    if(c == 0)
        return r;
    else if(c > 0)
        return Find_BST(r->leftChild, k);
    else
        return Find_BST(r->rightChild, k);
}

Node* Insert_BST(Node* r, char* k){
    if(r == NULL)
        return makeNode(k);
    int c = strcmp(r->key, k);
    if(c < 0)
        r->rightChild = Insert_BST(r->rightChild, k);
    else if(c > 0)
        r->leftChild = Insert_BST(r->leftChild, k);
    return r;
}

int find(char* k){
    int i = h(k);
    Node* p = Find_BST(T[i], k);
    if(p == NULL)  
        return 0;
    return 1;
}

int insert(char* k){
    int i = h(k);
    Node* p = Find_BST(T[i], k);
    if(p != NULL)
        return 0;
    T[i] = Insert_BST(T[i], k);
    return 1;
}

int main(){
    char k[MAX], cmd[20];
    while(1){
        scanf("%s", k);
        if(strcmp(k, "*") == 0)
            break;
        insert(k);
    }
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0)
            break;
        else if(strcmp(cmd, "find") == 0){
            scanf("%s", k);
            printf("%d\n", find(k));
        } 
        else if(strcmp(cmd, "insert") == 0){
            scanf("%s", k);
            printf("%d\n", insert(k));
        }
    }
}

