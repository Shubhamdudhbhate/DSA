#include <iostream>
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

// Stack class
class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (!head) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (!head) {
            cout << "Stack is empty\n";
            return -1;
        }
        return head->data;
    }

    void display() {
        if (!head) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();    

    cout << "Top: " << s.top() << "\n"; 

    s.pop();
    s.display();      

    return 0;
}
