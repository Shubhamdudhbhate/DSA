#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularList
{

    Node *head;
    Node *tail;

public:
    CircularList()
    {

        head = nullptr;
        tail = nullptr;
    }

    void InsertAtHead(int val)
    {

        Node *newNode = new Node(val);

        if (!head)
        {

            head = tail = newNode;
            newNode->next = tail;
        }

        newNode->next = head;

        head = newNode;
        tail->next = newNode;
    }

    void InsertAtTail(int val)
    {

        Node *newNode = new Node(val);

        if (!head)
        {

            head = tail = newNode;
            newNode->next = tail;
        }

        tail->next = newNode;
        newNode->next = head;
    }

    void InsertAtPosition(int pos, int val)
    {

        Node *newNode = new Node(val);

        if (pos == 0)
        {

            InsertAtHead(val);
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp->next != head; i++)
        {

            temp = temp->next;
        }
       newNode->next= temp->next ;
        temp->next = newNode;
    }

    void DeletetAtPosition(int pos)
    {

        if (!head)
            return;

        if (head->next = nullptr)
        {

            delete head, tail;
            head = tail = nullptr;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++)
        {

            temp = temp->next;
        }
        Node *ToDelete = temp->next;
        temp->next = temp->next->next;
        ToDelete->next = nullptr;
        delete ToDelete;
    }

    void DeleteAtTail()
    {

        if (!head)
            return;

        Node *temp = head;
        while (temp->next && temp->next->next != nullptr)

        {
            temp = temp->next;
        }

        Node *ToDelete = temp->next;

        temp->next = head;
        delete ToDelete;
    }

    void DeleteAtHead()
    {

        if (!head)
            return;

        Node *temp = head;

        head = head->next;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

void Display() {
    if (!head) {
        cout << "LinkedList is Empty" << endl;
        return;
    }

    Node* temp = head;
    cout << "Your LinkedList Data is:" << endl;

    do {
        cout << temp->data << "\n";
        temp = temp->next;
    } while (temp != head);
}




};


int main() {
    CircularList cl;

    cl.InsertAtTail(10);
    cl.InsertAtTail(20);
    cl.InsertAtTail(30);

  cl.Display();

    cl.InsertAtHead(5);
    cl.InsertAtHead(2);
cl.Display();

    cl.InsertAtPosition(2, 15); 
cl.Display();
    
    cl.DeleteAtHead();  
    cl.DeleteAtTail();  
    cl.DeletetAtPosition(2); 

cl.Display();

    return 0;
}
