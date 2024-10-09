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

void insertAtEnding(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void insertAtPosition(Node** head, int newData, int position) {
    if (position == 0) {
        insertAtBeginning(head, newData);
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    Node* current = *head;

    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        insertAtEnding(head, newData);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    newNode->prev = current;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void printForward(Node* node) {
    cout << "Forward Traversal: ";
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printForward(head);
    
    insertAtEnding(&head, 40);
    insertAtEnding(&head, 50);
    printForward(head);

    insertAtPosition(&head, 25, 2);
    printForward(head);
    
    insertAtPosition(&head, 5, 0);
    printForward(head);
    
    insertAtPosition(&head, 60, 100);
    printForward(head);
    
    return 0;
}

