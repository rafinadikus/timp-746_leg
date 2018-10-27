#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

typedef node* list;

// инициализация списка
int init(list *root){
    *root = NULL;
    return 1;
}

// удаление списка
int destroy(list *root){
    list tmp;
    while(*root != NULL){
        tmp = *root;
        *root = (*root)->next;
        free(tmp);
    }
    return 1;
}

// проверка списка на пустоту
bool isEmpty(list root){
    if(root != NULL){
        return 1;
    }else{
        return 0;
    }
}

// поиск элемента по значению, вернуть NULL, если элемент не найден
list find(list root, int value){
    while(root->value != value){
        if(root == NULL){
            return NULL;
        }
        root = root->next;
    }
    return root;
}

// вставка элемента после текущего
int append(list *lst, int value){
    if(((*lst) == NULL)){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *lst = tmp;
        return 1;
    }else if((*lst)->next == NULL){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = *lst;
        (*lst)->next = tmp;
        return 1;
    }else{
        list tmp = (list)malloc(sizeof(node));
        tmp->next = (*lst)->next;
        tmp->value = value;
        tmp->prev = *lst;
        (*lst)->next->prev = tmp;
        (*lst)->next = tmp;
        return 1;
    }
}

// вставка элемента перед текущим
int prepend(list *lst, int value){
    if(((*lst) == NULL)){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *lst = tmp;
        return 1;
    }else if((*lst)->prev == NULL){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = *lst;
        tmp->prev = NULL;
        (*lst)->prev = tmp;
        (*lst) = (*lst)->prev;
        return 1;
    }else{
        list tmp = (list)malloc(sizeof(node));
        tmp->prev = (*lst)->prev;
        tmp->value = value;
        tmp->next = *lst;
        (*lst)->prev->next = tmp;
        (*lst)->prev = tmp;
        return 1;
    }
}

// удаление текущего элемента
int remove1(list *lst){
    if (*lst != NULL) {
        list tmp = *lst;
        if (((*lst)->next != NULL) && ((*lst)->prev != NULL)) {
            (*lst)->prev->next = (*lst)->next;
            (*lst)->next->prev = (*lst)->prev;
        }
        if (((*lst)->next != NULL) && ((*lst)->prev == NULL)) {
            (*lst)->next->prev = NULL;
            (*lst) = (*lst)->next;
        }
        if (((*lst)->next == NULL) && ((*lst)->prev != NULL)) {
            (*lst)->prev->next = NULL;
        }
        free(tmp);
    }
    return 1;
}

// вывод списка
int print(list *lst){
    list tmp = *lst;
    do{
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    while( tmp != NULL);

    printf("\n");

    return 1;
}

int main()
{
    list root, tmp;
    init(&root);

    int n, i, k, m, a, c, x, b, d;
    scanf("%d", &n);
    while(n<0){
        printf("Error\n");
        scanf("%d", &n);
    }
    scanf("%d", &x);
    append(&root, x);

    tmp = root;
    for(i = 1; i<n; i++){
        scanf("%d", &x);
        append(&tmp, x);
        tmp = tmp->next;
    }
    print(&root);

    scanf("%d", &k);

    while(n<k){
        printf("Error\n");
        scanf("%d", &k);
    }

    if(k==1){
        remove1(&root);
    }else{
        tmp = root;
        for(i=1; i<k; i++){
            tmp = tmp->next;
        }
        remove1(&tmp);
    }
    print(&root);

    scanf("%d", &m);

    tmp = find(root, m);

    if(tmp == root){
        remove1(&root);
    }else{
        remove1(&tmp);
    }
    print(&root);

    scanf("%d%d", &a, &b);
    tmp = root;
    for(i=1; i<a; i++){
        tmp=tmp->next;
    }
    append(&tmp, b);

    print(&root);

    scanf("%d%d", &c, &d);
    if(c==1){
        prepend(&root, d);
    }else{
        tmp = root;
        for(i=1; i<c; i++){
            tmp=tmp->next;
        }
        prepend(&tmp, d);
    }

    print(&root);

    return 0;
}

