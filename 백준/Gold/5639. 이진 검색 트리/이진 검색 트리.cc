#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node* left, *right;
};

struct node *root = 0;

void addnode(int v){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->v = v;
    newnode->left = 0;
    newnode->right = 0;

    if (root == 0)
    {
        root = newnode;
        return;
    }

    struct node *cur = root;

    while (1)
    {
        if (cur->v > v)
        {
            if (cur->left == 0)
            {
                cur->left = newnode;
                return;
            }
            cur = cur->left;
        }
        else{
            if (cur->right == 0)
            {
                cur->right = newnode;
                return;
            }
            cur = cur->right;
        }
    }
}

void printtree(struct node* node){
    if (node == 0){
        return;
    }

    printtree(node->left);
    printtree(node->right);
    printf("%d\n", node->v);
}

void treefree(struct node* node){
    if (node == 0){
        return;
    }

    treefree(node->left);
    treefree(node->right);
    free(node);
}

int main(){
    int n = 0;
    
    while (scanf("%d", &n) == 1)
    {
        addnode(n);
    }

    printtree(root);

    treefree(root);

    return 0;
}

// 재귀를 이용한 트리