#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
int a;
int n1,n2;

typedef struct node{
    int k;
    struct node *left;
    struct node *right;
}node;

node *root=NULL;

node *makenode(int k){
    node *neww=(node*)malloc(sizeof(node));
    neww->k=k;
    neww->left=neww->right=NULL;
    return neww;
}

node *insert(node *r,int u){
    if(r==NULL) return makenode(u);
    if(r->k>u) r->left=insert(r->left,u);
    if(r->k<u) r->right=insert(r->right,u);
    return r;
}

node* LCA(node* r){
    if(r == NULL) return NULL;
    if(r->k > n1 && r->k > n2)
        return LCA(r->left);
    if(r->k < n1 && r->k < n2)
        return LCA(r->right);
    return r;
}

int distance(node *r,int x){
    if(r->k==x) return 0;
    if(r->k>x) return 1+ distance(r->left,x);
    return 1+distance(r->right,x);
}

int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        root = insert(root, a);
    }
    scanf("%d%d",&n1,&n2);
    
    printf("%d", distance(LCA(root),n1) + distance(LCA(root),n2));
    return 0;
}