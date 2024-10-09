#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


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


void deleteAtBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
}


void deleteAtEnding(Node** head) {
    if (*head == NULL) return;

    Node* last = *head;
    if (last->next == NULL) {
        delete last;
        *head = NULL;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->prev->next = NULL;
    delete last;
}


void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) return;

    Node* current = *head;

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    for (int i = 0; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    delete current;
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

    insertAtEnding(&head, 01);
    insertAtEnding(&head, 02);
    insertAtEnding(&head, 04);
    printForward(head);

    deleteAtBeginning(&head);
    printForward(head);

    deleteAtEnding(&head);
    printForward(head);

    deleteAtPosition(&head, 0); 
    printForward(head);

    return 0;
}

