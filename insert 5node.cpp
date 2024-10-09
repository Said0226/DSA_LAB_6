#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printForward(Node* node) {
    cout << "Forward Traversal: ";
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void printBackward(Node* node) {
    // Move to the last node
    while (node && node->next != NULL) {
        node = node->next;
    }

    cout << "Backward Traversal: ";
    while (node != NULL) {
        cout << node->data << "->";
        node = node->prev;
    }
    cout << "NULL" << endl;
}

void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    // Inserting five nodes
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printForward(head);
    printBackward(head);

    freeList(head); // Free allocated memory
    return 0;
}

