#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
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

// ---------- 1. Diameter (recursive) ----------
int heightForDiameter(Node* root, int& diameter) {
    if (!root) return 0;
    int lh = heightForDiameter(root->left, diameter);
    int rh = heightForDiameter(root->right, diameter);

    // path through root = lh + rh + 1 nodes
    diameter = max(diameter, lh + rh + 1);
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int diameterVal = 0;
    heightForDiameter(root, diameterVal);
    return diameterVal;
}

// ---------- 2. Check Balanced Tree (recursive) ----------
int checkHeightBalanced(Node* root) {
    if (!root) return 0;
    int lh = checkHeightBalanced(root->left);
    if (lh == -1) return -1; // left subtree not balanced

    int rh = checkHeightBalanced(root->right);
    if (rh == -1) return -1; // right subtree not balanced

    if (abs(lh - rh) > 1) return -1; // current node not balanced
    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return checkHeightBalanced(root) != -1;
}

// ---------- 3. Check Symmetric Tree ----------
// Recursive
bool isSymmetricUtil(Node* leftNode, Node* rightNode) {
    if (!leftNode && !rightNode) return true;
    if (!leftNode || !rightNode) return false;
    if (leftNode->data != rightNode->data) return false;

    return isSymmetricUtil(leftNode->left, rightNode->right) &&
           isSymmetricUtil(leftNode->right, rightNode->left);
}

bool isSymmetricRecursive(Node* root) {
    if (!root) return true;
    return isSymmetricUtil(root->left, root->right);
}

// Iterative using queue
bool isSymmetricIterative(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        Node* leftNode = q.front(); q.pop();
        Node* rightNode = q.front(); q.pop();

        if (!leftNode && !rightNode) continue;
        if (!leftNode || !rightNode) return false;
        if (leftNode->data != rightNode->data) return false;

        // enqueue children in mirrored order
        q.push(leftNode->left);
        q.push(rightNode->right);

        q.push(leftNode->right);
        q.push(rightNode->left);
    }
    return true;
}

// ---------- 4. Build Tree from Inorder and Preorder ----------

Node* buildFromInPreHelper(vector<int>& preorder, int preStart, int preEnd,
                           vector<int>& inorder, int inStart, int inEnd,
                           unordered_map<int,int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);

    int inRootIndex = inMap[rootVal];
    int leftTreeSize = inRootIndex - inStart;

    root->left = buildFromInPreHelper(preorder, preStart+1, preStart+leftTreeSize,
                                      inorder, inStart, inRootIndex-1, inMap);
    root->right = buildFromInPreHelper(preorder, preStart+leftTreeSize+1, preEnd,
                                       inorder, inRootIndex+1, inEnd, inMap);

    return root;
}

Node* buildFromInorderPreorder(vector<int>& inorder, vector<int>& preorder) {
    unordered_map<int,int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildFromInPreHelper(preorder, 0, (int)preorder.size()-1,
                                inorder, 0, (int)inorder.size()-1, inMap);
}

// ---------- 5. Build Tree from Inorder and Postorder ----------

Node* buildFromInPostHelper(vector<int>& postorder, int postStart, int postEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int,int>& inMap) {
    if (postStart > postEnd || inStart > inEnd) return nullptr;

    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);

    int inRootIndex = inMap[rootVal];
    int leftTreeSize = inRootIndex - inStart;

    root->left = buildFromInPostHelper(postorder, postStart, postStart+leftTreeSize-1,
                                       inorder, inStart, inRootIndex-1, inMap);
    root->right = buildFromInPostHelper(postorder, postStart+leftTreeSize, postEnd-1,
                                        inorder, inRootIndex+1, inEnd, inMap);

    return root;
}

Node* buildFromInorderPostorder(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildFromInPostHelper(postorder, 0, (int)postorder.size()-1,
                                inorder, 0, (int)inorder.size()-1, inMap);
}

// --------- Helper for printing inorder ----------
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Example Tree for diameter, balanced, symmetric tests
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << "Diameter of tree: " << diameter(root) << "\n";

    cout << "Is balanced: " << (isBalanced(root) ? "Yes" : "No") << "\n";

    cout << "Is symmetric (recursive): " << (isSymmetricRecursive(root) ? "Yes" : "No") << "\n";
    cout << "Is symmetric (iterative): " << (isSymmetricIterative(root) ? "Yes" : "No") << "\n";

    // Build tree from inorder and preorder
    vector<int> inorderVec = {9,3,15,20,7};
    vector<int> preorderVec = {3,9,20,15,7};
    Node* rootFromInPre = buildFromInorderPreorder(inorderVec, preorderVec);
    cout << "Tree built from inorder & preorder, inorder traversal: ";
    inorderTraversal(rootFromInPre);
    cout << "\n";

    // Build tree from inorder and postorder
    vector<int> postorderVec = {9,15,7,20,3};
    Node* rootFromInPost = buildFromInorderPostorder(inorderVec, postorderVec);
    cout << "Tree built from inorder & postorder, inorder traversal: ";
    inorderTraversal(rootFromInPost);
    cout << "\n";

    return 0;
}
