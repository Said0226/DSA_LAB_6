#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            deleteFromBeginning();
        }
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printList();
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printList();
    }

    void deleteFromBeginning() {
        if (!head) return; // List is empty
        Node *temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // List becomes empty
        delete temp;
    }

    void deleteFromEnd() {
        if (!tail) return; // List is empty
        Node *temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // List becomes empty
        delete temp;
    }

    void printList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        for (Node *temp = head; temp; temp = temp->next) {
            cout << temp->data << " ";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cout << "Current List: ";
    dll.printList();

    cout << "Deleting from the beginning:\n";
    dll.deleteFromBeginning();
    dll.printList();

    cout << "Deleting from the end:\n";
    dll.deleteFromEnd();
    dll.printList();

    return 0;
}

