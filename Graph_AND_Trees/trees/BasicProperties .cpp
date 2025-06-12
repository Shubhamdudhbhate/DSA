#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree using level order input (iterative)
Node* buildTreeLevelOrder() {
    int val;
    cout << "Enter root node value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

// Recursive versions
int sizeRecursive(Node* root) {
    if (!root) return 0;
    return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
}

int sumRecursive(Node* root) {
    if (!root) return 0;
    return root->data + sumRecursive(root->left) + sumRecursive(root->right);
}

int maxValue(Node* root) {
    if (!root) return INT_MIN;
    return max(root->data, max(maxValue(root->left), maxValue(root->right)));
}

int minValue(Node* root) {
    if (!root) return INT_MAX;
    return min(root->data, min(minValue(root->left), minValue(root->right)));
}

int heightRecursive(Node* root) {
    if (!root) return 0;
    return 1 + max(heightRecursive(root->left), heightRecursive(root->right));
}

int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Iterative versions using level order traversal
int sizeIterative(Node* root) {
    if (!root) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        count++;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return count;
}

int sumIterative(Node* root) {
    if (!root) return 0;
    int total = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        total += curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return total;
}

int maxValueIterative(Node* root) {
    if (!root) return INT_MIN;
    int maxVal = INT_MIN;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->data > maxVal) maxVal = curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return maxVal;
}

int minValueIterative(Node* root) {
    if (!root) return INT_MAX;
    int minVal = INT_MAX;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->data < minVal) minVal = curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return minVal;
}

int countLeafNodesIterative(Node* root) {
    if (!root) return 0;
    int leafCount = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (!curr->left && !curr->right)
            leafCount++;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return leafCount;
}

int countNonLeafNodesIterative(Node* root) {
    if (!root) return 0;
    int nonLeafCount = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->left || curr->right)
            nonLeafCount++;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return nonLeafCount;
}

// Height iterative (level order)
int heightIterative(Node* root) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        height++;
    }
    return height;
}

int main() {
    Node* root = buildTreeLevelOrder();

    cout << "\nSize (recursive): " << sizeRecursive(root) << "\n";
    cout << "Size (iterative): " << sizeIterative(root) << "\n";

    cout << "Sum (recursive): " << sumRecursive(root) << "\n";
    cout << "Sum (iterative): " << sumIterative(root) << "\n";

    cout << "Max (recursive): " << maxValue(root) << "\n";
    cout << "Max (iterative): " << maxValueIterative(root) << "\n";

    cout << "Min (recursive): " << minValue(root) << "\n";
    cout << "Min (iterative): " << minValueIterative(root) << "\n";

    cout << "Height (recursive): " << heightRecursive(root) << "\n";
    cout << "Height (iterative): " << heightIterative(root) << "\n";

    cout << "Leaf nodes (recursive): " << countLeafNodes(root) << "\n";
    cout << "Leaf nodes (iterative): " << countLeafNodesIterative(root) << "\n";

    cout << "Non-leaf nodes (recursive): " << countNonLeafNodes(root) << "\n";
    cout << "Non-leaf nodes (iterative): " << countNonLeafNodesIterative(root) << "\n";

    return 0;
}
