#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ✅ 1. Identical Tree
bool isIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// ✅ 2. Balanced Tree
int checkHeight(Node* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1;
    int rh = checkHeight(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// ✅ 3. Mirror Tree
Node* mirrorTree(Node* root) {
    if (!root) return NULL;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

// ✅ 4. Spiral (Zigzag) Traversal
void spiralOrder(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* temp = s1.top(); s1.pop();
            cout << temp->data << " ";
            if (temp->left) s2.push(temp->left);
            if (temp->right) s2.push(temp->right);
        }
        while (!s2.empty()) {
            Node* temp = s2.top(); s2.pop();
            cout << temp->data << " ";
            if (temp->right) s1.push(temp->right);
            if (temp->left) s1.push(temp->left);
        }
    }
    cout << endl;
}

// ✅ 5. Check if Two Nodes are Cousins
bool find(Node* root, int val, int depth, int& level, Node*& parent, Node* par) {
    if (!root) return false;
    if (root->data == val) {
        level = depth;
        parent = par;
        return true;
    }
    return find(root->left, val, depth + 1, level, parent, root) ||
           find(root->right, val, depth + 1, level, parent, root);
}
bool isCousins(Node* root, int x, int y) {
    int levelX = 0, levelY = 0;
    Node *parX = NULL, *parY = NULL;
    find(root, x, 0, levelX, parX, NULL);
    find(root, y, 0, levelY, parY, NULL);
    return (levelX == levelY) && (parX != parY);
}

// 🔰 Utility: Build a sample tree
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Node* root1 = buildSampleTree();
    Node* root2 = buildSampleTree();

    cout << "\n✅ Identical: " << (isIdentical(root1, root2) ? "Yes" : "No") << endl;
    cout << "✅ Balanced: " << (isBalanced(root1) ? "Yes" : "No") << endl;

    cout << "✅ Spiral Order Traversal: ";
    spiralOrder(root1);

    mirrorTree(root1);
    cout << "✅ After Mirroring, Spiral Order: ";
    spiralOrder(root1);

    cout << "✅ Cousins (4 & 6): " << (isCousins(root2, 4, 6) ? "Yes" : "No") << endl;
    cout << "✅ Cousins (4 & 5): " << (isCousins(root2, 4, 5) ? "Yes" : "No") << endl;

    return 0;
}
