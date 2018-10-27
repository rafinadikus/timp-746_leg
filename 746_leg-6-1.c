#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    int key;
    struct node *right;
    struct node *left;
} node;

typedef node* tree;

int init(tree *root){
    *root = NULL;
    return 1;
}

int addnote(int key, int value, tree *root){
    tree tmp = (*root);
    tree tmp2 = (tree)malloc(sizeof(node));
    tmp2->key = key;
    tmp2->value = value;
    tmp2->right = NULL;
    tmp2->left = NULL;

    if((*root) == NULL){
        (*root) = tmp2;
        return 1;
    }

    while (1)
    {
        if(key > tmp->key)
        {
            if(tmp->right == NULL)
            {
                tmp->right = tmp2;
                return 1;
            }
            tmp = tmp->right;
        }
        else if(key < tmp->key)
        {
            if(tmp->left == NULL)
            {
                tmp->left = tmp2;
                return 1;
            }
            tmp = tmp->left;
        }
        else return 1;
    }
}

void treeprint(tree root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->value);
    treeprint(root->left);
    treeprint(root->right);
}

int main()
{
    tree root;
    init(&root);

    int i, x, key, n;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &key);
        scanf("%d", &x);
        addnote(key, x, &root);
    }

    treeprint(root);
    printf("\n");
    return 0;
}
