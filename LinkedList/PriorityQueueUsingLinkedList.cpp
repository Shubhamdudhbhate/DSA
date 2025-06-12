#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct PriorityQueue {
    Node* head;

    PriorityQueue() {
        head = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (!head || val > head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data >= val) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void popMax() {
        if (!head) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Popped max element: " << head->data << endl;
        head = head->next;
        delete temp;
    }

    void popMin() {
        if (!head) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        if (!head->next) {
            cout << "Popped min element: " << head->data << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        // Traverse to last node (min element)
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        cout << "Popped min element: " << temp->data << endl;
        delete temp;
        prev->next = nullptr;
    }

    void peekMax() {
        if (!head) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        cout << "Max element: " << head->data << endl;
    }

    void peekMin() {
        if (!head) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        cout << "Min element: " << temp->data << endl;
    }

    void display() {
        if (!head) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        cout << "Priority Queue elements: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    pq.display();

    pq.peekMax();
    pq.peekMin();

    pq.popMax();
    pq.display();

    pq.popMin();
    pq.display();

    return 0;
}
