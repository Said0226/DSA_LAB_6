#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertatBegining(Node** head, int newData) {
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

int main() {
    Node* head = NULL;
    insertatBegining(&head, 10);
    insertatBegining(&head, 20);
    insertatBegining(&head, 30);

    printForward(head);
    printBackward(head);

    return 0;
}
