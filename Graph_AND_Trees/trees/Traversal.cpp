#include <iostream>
#include <queue>
#include <stack>
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

// Build tree using level order input
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

// Recursive traversals
void preorderRecursive(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void inorderRecursive(Node* root) {
    if (!root) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void postorderRecursive(Node* root) {
    if (!root) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

// Iterative traversals
void preorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);

    cout << "Preorder (Iterative): ";
    while (!st.empty()) {


        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";



        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    cout << "\n";
}

void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    cout << "Inorder (Iterative): ";
    while (curr || !st.empty()) {
        
        
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }


        curr = st.top(); st.pop();
        cout << curr->data << " ";


        curr = curr->right;
    }
    cout << "\n";
}

void postorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> st1, st2;
    st1.push(root);

    cout << "Postorder (Iterative): ";
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

   
   
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << "\n";
}

// Level order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    cout << "Level Order: ";
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << "\n";
}

// ZigZag traversal
void zigZagTraversal(Node* root) {
    if (!root) return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;
    currLevel.push(root);

    cout << "ZigZag Order: ";
    while (!currLevel.empty()) {
        Node* temp = currLevel.top();
        currLevel.pop();

        cout << temp->data << " ";

        if (leftToRight) {
            if (temp->left) nextLevel.push(temp->left);
            if (temp->right) nextLevel.push(temp->right);
        } else {
            if (temp->right) nextLevel.push(temp->right);
            if (temp->left) nextLevel.push(temp->left);
        }




        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);               // imp
        }


    }
    cout << "\n";
}

int main() {
    Node* root = buildTreeLevelOrder();

    cout << "\nPreorder (Recursive): ";
    preorderRecursive(root);
    cout << "\nInorder (Recursive): ";
    inorderRecursive(root);
    cout << "\nPostorder (Recursive): ";
    postorderRecursive(root);
    cout << "\n";

    preorderIterative(root);
    inorderIterative(root);
    postorderIterative(root);

    levelOrderTraversal(root);
    zigZagTraversal(root);

    return 0;
}
