#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node in the sorted linked list
struct Node* sortedInsert(struct Node* sorted, struct Node* newNode) {
    // If the sorted list is empty or the new node should be the first
    if (sorted == NULL || sorted->data >= newNode->data) {
        newNode->next = sorted;
        return newNode;
    }
    // Locate the node after which the new node is to be inserted
    struct Node* current = sorted;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return sorted;
}

// Function to sort the linked list using insertion sort
void insertionSort(struct Node** headRef) {
    struct Node* sorted = NULL;  // Initialize sorted linked list
    struct Node* current = *headRef;

    // Traverse the original list
    while (current != NULL) {
        struct Node* next = current->next; // Store the next node
        // Insert the current node into the sorted list
        sorted = sortedInsert(sorted, current);
        current = next; // Move to the next node
    }
    *headRef = sorted; // Update the head pointer to the sorted list
}

// Driver code
int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);

    printf("Original list:\n");
    printList(head);

    // Sort the linked list
    insertionSort(&head);

    printf("\nSorted list:\n");
    printList(head);

    return 0;
}
