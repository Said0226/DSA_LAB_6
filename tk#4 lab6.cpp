#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node{newData, nullptr}; // Initialize new node
    if (*head == nullptr) {
        *head = newNode; 
        return;
    }

    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next; 
    }
    last->next = newNode; 
}

/
void reverseList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;

    while (current != nullptr) {
        Node* next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    *head = prev; 
}


void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "How many values do you want to insert in this list? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    cout << "Before reversing, the linked list is: ";
    printList(head);

    reverseList(&head);
    cout << "After reversing, the linked list is: ";
    printList(head);

    return 0;
}

