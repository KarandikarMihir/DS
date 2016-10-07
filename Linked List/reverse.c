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

void reverse_iterative(struct node *head) {
    struct node *temp = head, *reverse = NULL, *current = NULL;
    while(temp != NULL) {
        current = temp;
        temp = temp->next;

        current->next = reverse;
        reverse = current;
    }
    printList(reverse); 
}

struct node* reverse_recursive(struct node *head) {
    struct node *temp = *head, *reverse = NULL;
    if(head == NULL) {
        return;
    }
    return reverse_recursive(head->next);
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
    reverse_iterative(&head);
    return 0;
}
