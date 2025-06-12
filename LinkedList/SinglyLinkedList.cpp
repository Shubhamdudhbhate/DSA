#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Singly Linked List class

class SinglyLinkedList
{

private:
    Node *head;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Insert at head
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position (0-based index)
    void insertAtPosition(int pos, int val)
    {
        if (pos == 0)
        {
            insertAtHead(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from head
    void deleteAtHead()
    {
        if (!head)
            return;

        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Delete from tail
    void deleteAtTail()
    {

        if (!head)
            return;

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->next)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at a specific position (0-based index)
    void deleteAtPosition(int pos)
    {
        if (!head)
            return;

        if (pos == 0)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++)
        {
            temp = temp->next;
        }

        if (!temp->next)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Display the list
    void display()
    {
        Node *temp = head;
        cout << "Linked List: ";
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void ReverseLinkedList()
    {
        Node *prev = nullptr;
        Node *next = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev; // Update head to the new front of the list
    }

    void Nth_NodeFromEnd(int n)
    {
        Node *Fast = head;
        Node *slow = head;
        for (int i = 0; i < n; i++)
        {
            Fast = Fast->next;
        }

        while (Fast->next)
        {

            Fast = Fast->next;
            slow = slow->next;
        }

        cout << n << "_th Node from end is:" << slow->next->data << endl;
    }

    void Middle_Node()
    {
        Node *Fast = head;
        Node *slow = head;

        while (Fast->next)
        {

            Fast = Fast->next->next;
            slow = slow->next;
        }

        cout << "Middle  Node of the LinledList is:" << slow->data << endl;
    }

    bool Search(int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // bool Search(Node* head, int key) {
    //     Node* temp = head;
    //     while (temp) { // loop while temp is NOT NULL
    //         if (temp->data == key) {
    //             return true;
    //         }
    //         temp = temp->next;
    //     }
    //     return false;
    // }
};

// Main function to test
int main()
{
    SinglyLinkedList sll;

    sll.insertAtTail(10);
    sll.insertAtTail(20);
    sll.insertAtTail(30);
    sll.insertAtTail(40);
    sll.insertAtTail(50);
    // sll.insertAtTail(60);

    sll.display();
    sll.Nth_NodeFromEnd(2);
    sll.Middle_Node();

    if (sll.Search(20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    sll.insertAtHead(5);
    sll.insertAtPosition(2, 15);
    sll.display();

    sll.deleteAtHead();
    sll.deleteAtTail();
    sll.deleteAtPosition(1);
    sll.display();

    cout << "REVERSE:" << endl;
    sll.ReverseLinkedList();
    sll.display();

    return 0;
}
