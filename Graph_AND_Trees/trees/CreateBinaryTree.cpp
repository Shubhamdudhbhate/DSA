#include <iostream>
#include <queue>
using namespace std;

// ---------------------- Node Structure ---------------------
class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ------------------ 1A: Recursive Construction ------------------
Node* buildTreeRecursive() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    cout << "Enter left child of " << val << ":\n";
    root->left = buildTreeRecursive();

    cout << "Enter right child of " << val << ":\n";
    root->right = buildTreeRecursive();

    return root;
}

// ------------------ 1B: Level-Order Construction ------------------
Node* buildTreeLevelOrder() {
    int val;
    cout << "Enter root node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// ------------------ Preorder Traversal (to check) ------------------
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ------------------ Main Function ------------------
int main() {
    cout << "Choose Tree Construction Method:\n";
    cout << "1. Recursive\n2. Level Order (Iterative)\nEnter choice: ";
    int choice;
    cin >> choice;

    Node* root = NULL;

    if (choice == 1)
        root = buildTreeRecursive();
    else if (choice == 2)
        root = buildTreeLevelOrder();
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << "\nPreorder Traversal of Constructed Tree: ";
    preorder(root);

    return 0;
}
