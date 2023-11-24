
#include <stdio.h>
#include <stdlib.h>



// Function to append a new node to the end of a doubly linked list
void append(Item** head, int value) {
    Item* new_node = (Item*)malloc(sizeof(Item));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
    }
    else {
        Item* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

// Function to print the doubly linked list forwards
void printForward(Item* head) {
    Item* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list backwards
void printBackward(Item* tail) {
    Item* current = tail;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    Item* list1 = NULL;
    Item* list2 = NULL;

    // Appending elements to the doubly linked list 1
    append(&list1, 10);
    append(&list1, 20);
    append(&list1, 30);

    // Appending elements to the doubly linked list 2
    append(&list2, 5);
    append(&list2, 15);
    append(&list2, 25);

    // Printing the doubly linked list 1 forwards
    printf("Doubly linked list 1 (forward): ");
    printForward(list1);

    // Printing the doubly linked list 1 backwards
    Item* current1 = list1;
    while (current1->next != NULL) {
        current1 = current1->next;
    }
    printf("Doubly linked list 1 (backward): ");
    printBackward(current1);

    // Printing the doubly linked list 2 forwards
    printf("Doubly linked list 2 (forward): ");
    printForward(list2);

    // Printing the doubly linked list 2 backwards
    Item* current2 = list2;
    while (current2->next != NULL) {
        current2 = current2->next;
    }
    printf("Doubly linked list 2 (backward): ");
    printBackward(current2);


    // Free memory for list1
    current1 = list1;
    while (current1 != NULL) {
        Item* temp = current1;
        current1 = current1->next;
        free(temp);
    }

    // Free memory for list2
    current2 = list2;
    while (current2 != NULL) {
        Item* temp = current2;
        current2 = current2->next;
        free(temp);
    }

    return 0;
}
