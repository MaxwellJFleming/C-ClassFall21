#include "linkedlist.h"

int checkForLoop(NodeT *head){
    NodeT *tortoise = head;
    NodeT *hare = head;
    NodeT *tempHare = head;
    while(tempHare->next != NULL && hare->next != NULL){
        tortoise = tortoise->next;
        tempHare = hare->next;
        hare = tempHare->next;
        if (hare == tortoise){
            return 1;
        }
    }
    return -1;
}

int main(void){
    NodeT *head = init(1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    NodeT *loop = init(1);
    loop->next = loop;

    printf("%d\n", checkForLoop(head));
    printf("%d\n", checkForLoop(loop));
}