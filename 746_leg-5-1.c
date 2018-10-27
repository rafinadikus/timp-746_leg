#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    int key;
    struct node *right;
    struct node *left;
} node;

typedef node* tree;
//инициализация
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

int main()
{
    tree root;
    init(&root);
    int i, x, key, cnt, a, n;
    int bol = 1;
    printf("wwedite n \n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("wwedite pari \n");
        scanf("%d", &key);
        scanf("%d", &x);
        addnote(key, x, &root);
    }

    for(i = 0; i<3; i++){
        tree tmp = root;
        printf("wwedite chisla \n");
        scanf("%d", &a);
        cnt = 0;
        bol = 1;

        while(bol != 0)
        {
            if(tmp != NULL)
            {
                if(tmp->key == a)
                {
                    printf("%d ", cnt);
                    printf("%d", tmp->value);
                    bol = 0;
                }
                else
                {
                    if(tmp->key > a) tmp = tmp->left;
                    if(tmp->key < a) tmp = tmp->right;
                    cnt++;
                }
            }
            else
            {
                printf("%d", -1);
                bol = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
