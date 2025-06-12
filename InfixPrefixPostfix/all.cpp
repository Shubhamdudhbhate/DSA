#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

// Get precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result;
    for (char ch : s) {
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top(); st.pop();
            }
            st.pop(); // remove '('
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                result += st.top(); st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        result += st.top(); st.pop();
    }
    return result;
}

// Infix to Prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char& ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Postfix Evaluation (Single-digit numbers)
int evalPostfix(string exp) {
    stack<int> st;
    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

// Prefix Evaluation (Single-digit numbers)
int evalPrefix(string exp) {
    stack<int> st;
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

// Infix Evaluation (uses two stacks: operands & operators)
int evalInfix(string exp) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            values.push(ch - '0');
        }
        else if (ch == '(') {
            ops.push(ch);
        }
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                switch (op) {
                    case '+': values.push(a + b); break;
                    case '-': values.push(a - b); break;
                    case '*': values.push(a * b); break;
                    case '/': values.push(a / b); break;
                }
            }
            ops.pop(); // pop '('
        }
        else { // operator
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                switch (op) {
                    case '+': values.push(a + b); break;
                    case '-': values.push(a - b); break;
                    case '*': values.push(a * b); break;
                    case '/': values.push(a / b); break;
                }
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        switch (op) {
            case '+': values.push(a + b); break;
            case '-': values.push(a - b); break;
            case '*': values.push(a * b); break;
            case '/': values.push(a / b); break;
        }
    }

    return values.top();
}

// ---------------- MAIN -----------------
int main() {
    string infix;
    cout << "Enter an infix expression (use single-digit numbers, like (2+3)*4): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "\nInfix:   " << infix;
    cout << "\nPostfix: " << postfix;
    cout << "\nPrefix:  " << prefix;

    cout << "\n\nEvaluations:";
    cout << "\nInfix Eval   = " << evalInfix(infix);
    cout << "\nPostfix Eval = " << evalPostfix(postfix);
    cout << "\nPrefix Eval  = " << evalPrefix(prefix);

    return 0;
}
