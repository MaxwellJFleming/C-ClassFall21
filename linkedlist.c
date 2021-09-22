#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} NodeT;

NodeT *init(const int n){
    NodeT *node = (NodeT *)malloc(sizeof(NodeT));   //NodeT is roughly 8 bytes large
    node->data = n;
    node->next = NULL;
    return node;
}

NodeT *destroy(NodeT *node){
    NodeT *next = node->next;
    free(node);
    return next;
}

void append(NodeT **head, int new_data){
    NodeT *node = init(new_data);
    NodeT *last = *head;
    if(*head == NULL){
        *head = node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = node;
}

void print(NodeT *head){
    NodeT *tmp = head;
    while(tmp->next != NULL){
        printf("%d", tmp->data);
        tmp = tmp->next;
    }
    printf("%d", tmp->data);
}

int main(void){
    NodeT *head = init(1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    print(head);
}