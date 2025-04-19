#include <stdio.h>
#include <stdlib.h>

struct node {
    char v;
    struct node *left, *right;
};

struct node* root = NULL;
struct node* nodes[26];

struct node* findNode(struct node* r, char v) {
    if (r == NULL) return NULL;
    if (r->v == v) return r;

    struct node* found = findNode(r->left, v);
    if (found) return found;
    return findNode(r->right, v);
}

void addtree(char a, char b, char c) {
    if (!nodes[a - 'A']) {
        nodes[a - 'A'] = (struct node*)malloc(sizeof(struct node));
        nodes[a - 'A']->v = a;
        nodes[a - 'A']->left = NULL;
        nodes[a - 'A']->right = NULL;
    }

    if (root == NULL) {
        root = nodes[a - 'A'];
    }

    if (b != '.' && !nodes[b - 'A']) {
        nodes[b - 'A'] = (struct node*)malloc(sizeof(struct node));
        nodes[b - 'A']->v = b;
        nodes[b - 'A']->left = NULL;
        nodes[b - 'A']->right = NULL;
    }

    if (c != '.' && !nodes[c - 'A']) {
        nodes[c - 'A'] = (struct node*)malloc(sizeof(struct node));
        nodes[c - 'A']->v = c;
        nodes[c - 'A']->left = NULL;
        nodes[c - 'A']->right = NULL;
    }

    struct node* parent = findNode(root, a);
    if (parent) {
        parent->left = (b != '.') ? nodes[b - 'A'] : NULL;
        parent->right = (c != '.') ? nodes[c - 'A'] : NULL;
    }
}

void preorder(struct node* r) {
    if (r == NULL) return;
    printf("%c", r->v);
    preorder(r->left);
    preorder(r->right);
}

void inorder(struct node* r) {
    if (r == NULL) return;
    inorder(r->left);
    printf("%c", r->v);
    inorder(r->right);
}

void postorder(struct node* r) {
    if (r == NULL) return;
    postorder(r->left);
    postorder(r->right);
    printf("%c", r->v);
}

void freetree(struct node* r) {
    if (r == NULL) return;
    freetree(r->left);
    freetree(r->right);
    free(r);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        addtree(a, b, c);
    }

    preorder(root); printf("\n");
    inorder(root);  printf("\n");
    postorder(root);printf("\n");

    freetree(root); // optional
    return 0;
}

// 항상 새로운 노드를 만들면서 찾을려고 했지만, 시간초과.
// 알파벳만 다루기 때문에 미리 만들고 사용.