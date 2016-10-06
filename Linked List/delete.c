#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    while(head != NULL) {
        printf("\n%d", head->data);
        head = head->next;
    }
}

void push(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;   
}

void deleteNode(struct node** head, int key) {
    struct node *temp = *head, *target;
    if(temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp->next != NULL) {
        if(temp->next->data == key) {
            break;
        }
        temp = temp->next;
    }
    if(temp->next == NULL) {
        printf("\nCould not find %d in the list", key);
        return;
    }
    target = temp->next;
    temp->next = temp->next->next;
    free(target);
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    push(&head, 100);
    push(&head, 200);
    push(&head, 300);
    
    printList(head);

    printf("\nDeleting 500");
    deleteNode(&head, 500);

    printf("\nDeleting 300");
    deleteNode(&head, 300);

    printList(head);
    return 0;
}
