#include <iostream>
using namespace std;

const int MAX = 100;

class PriorityQueue {
private:

    int values[MAX];
    int priorities[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void push(int value, int priority) {
        if (size == MAX) {
            cout << "Queue is full!" << endl;
            return;
        }

        int i;
        for (i = size - 1; i >= 0; i--) {
            // Shift elements with lower priority
            if (priorities[i] < priority) {
                values[i + 1] = values[i];
                priorities[i + 1] = priorities[i];
            } else {
                break;
            }
        }

        // Insert new element at correct position
        values[i + 1] = value;
        priorities[i + 1] = priority;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        size--;
    }

    int top() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return values[0]; // Highest priority at front
    }

    bool empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(100, 2);   // value = 100, priority = 2
    pq.push(500, 5);   // higher priority
    pq.push(300, 3);

    cout << "Priority Queue (using array):\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
