#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// --------- 1. Left View (Recursive) ----------
void leftViewRecursiveUtil(Node* root, int level, int &maxLevel) {
    if (!root) return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    // Visit left subtree first
    leftViewRecursiveUtil(root->left, level + 1, maxLevel);
    leftViewRecursiveUtil(root->right, level + 1, maxLevel);
}

void leftViewRecursive(Node* root) {
    int maxLevel = 0;
    leftViewRecursiveUtil(root, 1, maxLevel);
}

// --------- 2. Left View (Iterative) ----------
void leftViewIterative(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            Node* curr = q.front();
            q.pop();

            // Print first node of each level
            if (i == 1) cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

// --------- 3. Right View (Recursive) ----------
void rightViewRecursiveUtil(Node* root, int level, int &maxLevel) {
    if (!root) return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    // Visit right subtree first
    rightViewRecursiveUtil(root->right, level + 1, maxLevel);
    rightViewRecursiveUtil(root->left, level + 1, maxLevel);
}

void rightViewRecursive(Node* root) {
    int maxLevel = 0;
    rightViewRecursiveUtil(root, 1, maxLevel);
}

// --------- 4. Right View (Iterative) ----------
void rightViewIterative(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            Node* curr = q.front();
            q.pop();

            // Print last node of each level
            if (i == n) cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

// --------- 5. Top View (Iterative) ----------
void topView(Node* root) {
    if (!root) return;

    // horizontal distance -> node data
    map<int, int> topNodeMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* curr = front.first;
        int hd = front.second;

        // insert only if hd not seen before
        if (topNodeMap.find(hd) == topNodeMap.end())
            topNodeMap[hd] = curr->data;

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    // print top view from leftmost to rightmost hd
    for (auto it : topNodeMap) {
        cout << it.second << " ";
    }
}

// --------- 6. Bottom View (Iterative) ----------
void bottomView(Node* root) {
    if (!root) return;

    map<int, int> bottomNodeMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* curr = front.first;
        int hd = front.second;

        // overwrite every time, last node at hd remains
        bottomNodeMap[hd] = curr->data;

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto it : bottomNodeMap) {
        cout << it.second << " ";
    }
}

// Simple tree for demo
/*
        1
       / \
      2   3
     / \   \
    4   5   6
           /
          7
*/

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    cout << "Left View Recursive: ";
    leftViewRecursive(root);
    cout << "\nLeft View Iterative: ";
    leftViewIterative(root);

    cout << "\nRight View Recursive: ";
    rightViewRecursive(root);
    cout << "\nRight View Iterative: ";
    rightViewIterative(root);

    cout << "\nTop View: ";
    topView(root);

    cout << "\nBottom View: ";
    bottomView(root);

    cout << "\n";

    return 0;
}
