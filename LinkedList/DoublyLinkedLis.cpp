#include<iostream>
using namespace std;


class Node
{

public:

    int data;
    Node*next;
    Node*prev;


    Node(int val)
    {
        data = val;
        next = nullptr;
        prev=nullptr;
    }


};



// Singly Linked List class

class DoublyLinkedList {

private:
    Node* head;
    Node*tail;


public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail=nullptr;
    }


    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;


    if (head){head->prev = newNode; 
    }
        // head->prev=newNode;
        head = newNode;

    }

    // Insert at tail

    void insertAtTail(int val) {

        Node* newNode = new Node(val);

        if (!tail) 
        {
            head=tail = newNode;  
             
            return;
        }


        Node* temp = tail;
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;

    }

    // Insert at a specific position (0-based index)
    void insertAtPosition(int pos, int val) {
        if (pos == 0) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr;  i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev=temp;
        newNode->next->prev=newNode;
        temp->next = newNode;
    }

    // Delete from head
    void deleteAtHead() {
        if (!head) return;

        Node* toDelete = head;
        head = head->next;
        head->prev=nullptr;
        delete toDelete;
    }

    // Delete from tail
    void deleteAtTail() {
        
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
      
         temp->next->prev=nullptr;
        delete temp->next;

        temp->next = nullptr;
    }

    // Delete at a specific position (0-based index)
    void deleteAtPosition(int pos) {
        if (!head) return;

        if (pos == 0) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        toDelete->next->prev=temp;
        toDelete->next=nullptr;
         toDelete->prev=nullptr;
        delete toDelete;
    }

    // Display the list
void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


// Main function to test
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


