#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; 

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);

        if (!front) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (!front) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (!front) rear = nullptr; // If queue becomes empty
    }

    int peek() {
        if (!front) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.pop();
    }

    return 0;
}
