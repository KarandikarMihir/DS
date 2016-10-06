#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* temp) {
    printf("[");
    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void push(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    (*head) = new_node;
}

void length_iterative(struct node *temp) {
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nLength of Linked List (Iterative method): %d\n", count);
}

int length_recursive(struct node *temp) {
    int count = 0;
    if(temp == NULL) {
        return 0;
    }
    return 1 + length_recursive(temp->next);
}

int main() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = NULL;

    push(&head, 2);
    push(&head, 3);
    printList(head);
    length_iterative(head);
    printf("\nLength of Linked List (Recursive method): %d\n", length_recursive(head));

    return 0;
}
