#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* child;        // con đầu tiên
    struct Node* rightsibling; // anh em bên phải
    struct Node* parent;       // thêm để tính Depth nhanh
} Node;

#define MAXID 10001
Node* nodes[MAXID];
Node* root = NULL;

Node* makeNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->child = NULL;
    p->rightsibling = NULL;
    p->parent = NULL;
    nodes[id] = p;
    return p;
}

void MakeRoot(int u) {
    root = makeNode(u);
    root->parent = NULL;
}

void Insert(int u, int v) {
    if (u < 0 || u >= MAXID || v < 0 || v >= MAXID)
        return;

    if (nodes[u] != NULL) return;     // u đã tồn tại
    if (nodes[v] == NULL) return;     // v không tồn tại

    Node* parent = nodes[v];
    Node* q = makeNode(u);
    q->parent = parent;

    if (parent->child == NULL) {
        parent->child = q;
    } else {
        Node* cur = parent->child;
        while (cur->rightsibling != NULL)
            cur = cur->rightsibling;
        cur->rightsibling = q;
    }
}

/* -------- HEIGHT -------- */

int calcHeight(Node* x) {
    if (x == NULL) return 0;

    Node* c = x->child;
    if (c == NULL) return 1;  // lá

    int maxh = 0;
    while (c) {
        int h = calcHeight(c);
        if (h > maxh) maxh = h;
        c = c->rightsibling;
    }
    return maxh + 1;
}

/* -------- DEPTH -------- */

int calcDepth(Node* x) {
    int d = 1;
    while (x->parent != NULL) {
        d++;
        x = x->parent;
    }
    return d;
}

/* main */

int main() {
    char cmd[32];
    int u, v;

    for (int i = 0; i < MAXID; i++) nodes[i] = NULL;

    while (1) {
        if (scanf("%s", cmd) != 1) break;

        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            MakeRoot(u);
        }
        else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            Insert(u, v);
        }
        else if (strcmp(cmd, "Height") == 0) {
            scanf("%d", &u);
            if (nodes[u] == NULL) {
                printf("0\n");
            } else {
                printf("%d\n", calcHeight(nodes[u]));
            }
        }
        else if (strcmp(cmd, "Depth") == 0) {
            scanf("%d", &u);
            if (nodes[u] == NULL) {
                printf("0\n");
            } else {
                printf("%d\n", calcDepth(nodes[u]));
            }
        }
        else {
            char rest[256];
            fgets(rest, sizeof(rest), stdin);
        }
    }

    return 0;
}
