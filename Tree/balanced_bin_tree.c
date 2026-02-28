#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXID 50005

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* nodes[MAXID];
Node* root = NULL;

/* Tạo node mới */
Node* makeNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->left = p->right = NULL;
    nodes[id] = p;
    return p;
}

/* Hàm kiểm tra cân bằng + tính height
   Trả về height >= 1 nếu cân bằng
   Trả về -1 nếu mất cân bằng */
int checkBalanced(Node* x) {
    if (x == NULL) return 0;

    int lh = checkBalanced(x->left);
    if (lh == -1) return -1;

    int rh = checkBalanced(x->right);
    if (rh == -1) return -1;

    if (lh - rh > 1 || rh - lh > 1)
        return -1;

    return (lh > rh ? lh : rh) + 1;
}

/* Height thật (không xét cân bằng) */
int trueHeight(Node* x) {
    if (x == NULL) return 0;
    int lh = trueHeight(x->left);
    int rh = trueHeight(x->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    char cmd[32];
    int u, v;

    for (int i = 0; i < MAXID; i++) nodes[i] = NULL;

    while (1) {
        if (scanf("%s", cmd) != 1) break;

        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = makeNode(u);
        }
        else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            if (nodes[u] == NULL && nodes[v] != NULL && nodes[v]->left == NULL) {
                Node* p = makeNode(u);
                nodes[v]->left = p;
            }
        }
        else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            if (nodes[u] == NULL && nodes[v] != NULL && nodes[v]->right == NULL) {
                Node* p = makeNode(u);
                nodes[v]->right = p;
            }
        }
    }

    int hb = checkBalanced(root);
    int balanced = (hb == -1 ? 0 : 1);

    int h = trueHeight(root);

    printf("%d %d\n", balanced, h);

    return 0;
}
