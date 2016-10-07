#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *temp) {
    printf("\n[");
    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void push(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

struct node* getPreviousNode(struct node *head, struct node *target) {
    struct node *temp = head;
    while(temp->next != target) {
        temp = temp->next;
    }
    return temp;
}

void swap(struct node **head, int a, int b) {
    struct node *temp = *head, *w = NULL, *x = NULL, *y = NULL, *z = NULL;
    if(a == b) {
        printf("\nInvalid arguments");
        return;
    }
    while(temp != NULL) {
        if(temp->data == a || temp->data == b) {
            if(x == NULL) {
                x = temp;
            } else {
                y = temp;
            }
        }
        temp = temp->next;
    }
    if(x == NULL || y == NULL) {
        printf("\nInvalid arguments");
        return;
    }
    
    if(x == *head) {
        if(x->next == y) {
            x->next = y->next;
            y->next = x;
            *head = y;
        } else if(y->next == NULL) {
            z = getPreviousNode(*head, y);
            y->next = x->next;
            z->next = x;
            x->next = NULL;
            *head = y;
        }
    } else {
        if(x->next == y) {
            z = getPreviousNode(*head, x);
            x->next = y->next;
            z->next = y;
            y->next = x;
        } else {
            w = getPreviousNode(*head, x);
            z = getPreviousNode(*head, y);
            temp = x->next;
            z->next = x;
            x->next = y->next;
            w->next = y;
            y->next = temp;
        }
    }
}

int main() {
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = -1;
    head->next = NULL;

    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printList(head);
    swap(&head, 1, 3);
    printList(head);
    return 0;  
}
