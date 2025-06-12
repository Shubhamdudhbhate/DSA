#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularList {
    Node *head;
    Node *tail;

public:
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtHead(int val) {
        Node *newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }

        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    void InsertAtTail(int val) {
        Node *newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    void InsertAtPosition(int pos, int val) {
        if (pos == 0) {
            InsertAtHead(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        if (temp == tail)
            tail = newNode;
    }

    void DeletetAtPosition(int pos) {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        if (pos == 0) {
            DeleteAtHead();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        Node *ToDelete = temp->next;
        temp->next = ToDelete->next;
        ToDelete->next->prev = temp;

        if (ToDelete == tail)
            tail = temp;

        delete ToDelete;
    }

    void DeleteAtTail() {
        if (!head) return;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node *ToDelete = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete ToDelete;
    }

    void DeleteAtHead() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void Display1() {
        if (!head) {
            cout << "LinkedList is Empty" << endl;
            return;
        }

        Node *temp = head;
        cout << "Your LinkedList Data is:" << endl;
        do {
            cout << temp->data << "\n";
            temp = temp->next;
        } while (temp != head);
    }

    void Display2() {
        if (!tail) {
            cout << "LinkedList is Empty" << endl;
            return;
        }

        Node *temp = tail;
        Node *start = tail;
        cout << "Your LinkedList Data is (Reverse):" << endl;
        do {
            cout << temp->data << "\n";
            temp = temp->prev;
        } while (temp != start);
    }
};

int main() {
    CircularList cl;

    cl.InsertAtTail(10);
    cl.InsertAtTail(20);
    cl.InsertAtTail(30);

    cl.Display1();
    cout << "REVERSE 1" << endl;
    cl.Display2();

    cl.InsertAtHead(5);
    cl.InsertAtHead(2);
    cl.Display1();
    cout << "REVERSE 2" << endl;
    cl.Display2();

    cl.InsertAtPosition(2, 15);
    cl.Display1();

    cl.DeleteAtHead();
    cl.DeleteAtTail();
    cl.DeletetAtPosition(2);

    cl.Display1();
    cout << "REVERSE 3" << endl;
    cl.Display2();

    return 0;
}
