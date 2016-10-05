#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* temp) {
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/**
 * Complexity of push() is O(1), because
 * it does constant amount of work.
 */

void push(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    (*head) = new_node;
}

/**
 * Complexity of insertAfter() is O(1), because
 * it does constant amount of work.
 */

void insertAfter(struct node* previous_node, int data) {
    if(previous_node == NULL) {
        printf("\nPrevious node cannot be NULL\n");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;
}

/**
 * Complexity of append() is O(n), because
 * it iterates through n nodes before it
 * reaches the end of the list.
*/

void append(struct node* head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    while(head->next != NULL) {
        head = head->next;
    }

    head->next = new_node;
}

int main() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    push(&head, 0);
    insertAfter(second, 100);
    append(head, 200);

    printList(head);

    return 0;
}
