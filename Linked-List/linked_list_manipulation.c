#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* next;
}Node;

Node* head = NULL;

Node* find(int k){
    Node* p = head;
    while(p){
        if(p->key == k)
            return p;
        p = p->next;
    }
    return NULL;
}

void addlast(int k){
    if(find(k))
        return;
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = k;
    p->next = NULL;
    if(!head)
        head = p;
    else{
        Node* tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
}

void addfirst(int k){
    if(find(k))
        return;
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = k;
    p->next = head;
    head = p;
}

void addafter(int u, int v){
    if(find(u))
        return;
    Node* to_add = find(v);
    if(!to_add)
        return;
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = u;
    p->next = to_add->next;
    to_add->next = p;
}

void addbefore(int u, int v){
    if(find(u))
        return;
    if(!head)
        return;
    if(head->key == v){
        addfirst(u);
        return;
    }
    Node* p = head;
    while(p->next){
        if(p->next->key == v)
            break;
        p = p->next;
    }
    if(!p->next)
        return;
    Node* t = (Node*)malloc(sizeof(Node));
    t->key = u;
    t->next = p->next;
    p->next = t;
}

void Remove(int k){
    if(!head)
        return;
    if(head->key == k){
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    Node* p = head;
    while(p->next){
        if(p->next->key == k)
            break;
        p = p->next;
    }
    if(!p->next)
        return;
    Node* t = p->next;
    p->next = t->next;
    free(t);
}

void reverse(){
    Node* cur = head;
    Node* prev = NULL;
    Node* next;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main(){
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        addlast(k);
    }
    char cmd[20];
    while(1){
        scanf("%s", cmd);
        if(cmd[0] == '#')
            break;
        if(strcmp(cmd, "addlast") == 0){
            scanf("%d", &k);
            addlast(k);
        }
        else if(strcmp(cmd, "addfirst") == 0){
            scanf("%d", &k);
            addfirst(k);
        }
        else if(strcmp(cmd, "addafter") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            addafter(u, v);
        }
        else if(strcmp(cmd, "addbefore") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            addbefore(u, v);
        }
        else if(strcmp(cmd, "remove") == 0){
            scanf("%d", &k);
            Remove(k);
        }
        else if(strcmp(cmd, "reverse") == 0){
            reverse();
        }
    }
    Node* p = head;
    while(p){
        printf("%d ", p->key);
        p = p->next;
    }
}