#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;

        if (head) head->prev = newNode;  // ✅ Safe update
        else tail = newNode;             // ✅ First node becomes tail

        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (!tail) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;    // ✅ No need for temp
        newNode->prev = tail;
        tail = newNode;          // ✅ Update tail
    }

    void insertAtPosition(int pos, int val) {
        if (pos == 0) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next) temp->next->prev = newNode;
        else tail = newNode;    // ✅ Update tail if inserting at end

        temp->next = newNode;
    }

    void deleteAtHead() {
        if (!head) return;

        Node* toDelete = head;
        head = head->next;

        if (head) head->prev = nullptr;
        else tail = nullptr;    // ✅ If list is empty, tail = nullptr

        delete toDelete;
    }

    void deleteAtTail() {
        if (!tail) return;

        Node* toDelete = tail;
        tail = tail->prev;

        if (tail) tail->next = nullptr;
        else head = nullptr;    // ✅ If list is empty, head = nullptr

        delete toDelete;
    }

    void deleteAtPosition(int pos) {
        if (!head) return;

        Node* temp = head;
        for (int i = 0; i < pos && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;     // ✅ Update head if deleting first

        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;     // ✅ Update tail if deleting last

        delete temp;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Optional: destructor to clean memory
    ~DoublyLinkedList() {
        while (head) deleteAtHead();
    }
};

// Test
int main() {
    DoublyLinkedList dll;

    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.display();

    dll.insertAtHead(5);
    dll.insertAtPosition(2, 15);
    dll.display();

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtPosition(1);
    dll.display();

    return 0;
}
