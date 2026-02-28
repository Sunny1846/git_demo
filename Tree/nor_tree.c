#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* child;        // con đầu tiên
    struct Node* rightsibling; // anh em bên phải
} Node;

Node* root = NULL;
/* giả sử id trong phạm vi 0..10000; nếu id có thể lớn hơn, đổi cách lưu (hash/map) */
#define MAXID 10001
Node* nodes[MAXID];

Node* makeNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->child = NULL;
    p->rightsibling = NULL;
    if (id >= 0 && id < MAXID) nodes[id] = p;
    return p;
}

void MakeRoot(int u) {
    root = makeNode(u);
}

void Insert(int u, int v) {
    /* tạo node u và chèn vào cuối danh sách con của v */
    if (v < 0 || v >= MAXID || nodes[v] == NULL) return; /* phòng ngừa */
    Node* parent = nodes[v];
    Node* q = makeNode(u);

    if (parent->child == NULL) {
        parent->child = q;
    } else {
        Node* cur = parent->child;
        while (cur->rightsibling != NULL)
            cur = cur->rightsibling;
        cur->rightsibling = q;
    }
}

/* PreOrder: node -> all children (left-to-right) */
void PreOrder(Node* x) {
    if (x == NULL) return;
    printf("%d ", x->id);
    /* duyệt danh sách con: bắt đầu từ x->child, qua rightsibling */
    Node* c = x->child;
    while (c) {
        PreOrder(c);
        c = c->rightsibling;
    }
}

/* InOrder (theo quy ước đề bài):
   - duyệt con đầu tiên (nếu có)
   - visit node
   - duyệt các con còn lại (anh em của con đầu tiên) lần lượt
*/
void InOrder(Node* x) {
    if (x == NULL) return;
    if (x->child) {
        /* duyệt con đầu tiên */
        InOrder(x->child);
    }
    printf("%d ", x->id);
    /* duyệt các con còn lại (nếu có) */
    Node* c = (x->child) ? x->child->rightsibling : NULL;
    while (c) {
        InOrder(c);
        c = c->rightsibling;
    }
}

/* PostOrder: duyệt tất cả con (left-to-right) rồi visit node */
void PostOrder(Node* x) {
    if (x == NULL) return;
    Node* c = x->child;
    while (c) {
        PostOrder(c);
        c = c->rightsibling;
    }
    printf("%d ", x->id);
}

int main() {
    char cmd[32];
    int u, v;
    /* khởi tạo bảng */
    for (int i = 0; i < MAXID; ++i) nodes[i] = NULL;

    while (1) {
        if (scanf("%s", cmd) != 1) break;

        if (strcmp(cmd, "*") == 0)
            break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            if (scanf("%d", &u) != 1) break;
            MakeRoot(u);
        }
        else if (strcmp(cmd, "Insert") == 0) {
            if (scanf("%d %d", &u, &v) != 2) break;
            Insert(u, v);
        }
        else if (strcmp(cmd, "PreOrder") == 0) {
            PreOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "InOrder") == 0) {
            InOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0) {
            PostOrder(root);
            printf("\n");
        }
        else {
            /* bỏ qua dòng không hợp lệ */
            char rest[256];
            fgets(rest, sizeof(rest), stdin);
        }
    }

    return 0;
}
