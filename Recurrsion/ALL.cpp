#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// 1. Power of Two
bool isPowerOfTwo(int n) {
    if (n == 1) return true;
    if (n <= 0 || n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);
}

// 2. Reverse String using recursion
void reverseString(vector<char>& s, int left, int right) {
    if (left >= right) return;
    swap(s[left], s[right]);
    reverseString(s, left + 1, right - 1);
}

// 3. Reverse Stack using recursion
void insertAtBottom(stack<int>& st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(top);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

// 4. Print Subsequences of a String
void printSubsequences(string input, string output) {
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    // Include first char
    printSubsequences(input.substr(1), output + input[0]);
    // Exclude first char
    printSubsequences(input.substr(1), output);
}

int main() {
    int choice;
    do {
        cout << "\nChoose the recursion problem to run:\n";
        cout << "1. Power of Two\n2. Reverse String\n3. Reverse Stack\n4. Subsequences of String\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            if (isPowerOfTwo(n))
                cout << n << " is a power of two.\n";
            else
                cout << n << " is NOT a power of two.\n";
        }
        else if (choice == 2) {
            string input;
            cout << "Enter string: ";
            cin >> input;
            vector<char> s(input.begin(), input.end());
            reverseString(s, 0, s.size() - 1);
            cout << "Reversed string: ";
            for (char c : s) cout << c;
            cout << endl;
        }
        else if (choice == 3) {
            int n, val;
            stack<int> st;
            cout << "Enter number of elements in stack: ";
            cin >> n;
            cout << "Enter elements (top to bottom): ";
            for (int i = 0; i < n; ++i) {
                cin >> val;
                st.push(val);
            }
            reverseStack(st);
            cout << "Reversed stack (top to bottom): ";
            while (!st.empty()) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
        }
        else if (choice == 4) {
            string s;
            cout << "Enter string: ";
            cin >> s;
            cout << "Subsequences:\n";
            printSubsequences(s, "");
        }
        else if (choice != 0) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    cout << "Program exited.\n";
    return 0;
}
