#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> // for reverse

using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree using level order input (iterative)
Node* buildTreeLevelOrder() {
    int val;
    cout << "Enter root node value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return nullptr;

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

// 1) Search for a key - Recursive
bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchRecursive(root->left, key) || searchRecursive(root->right, key);
}

// 2) Search for a key - Iterative (level order)
bool searchIterative(Node* root, int key) {
    if (!root) return false;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->data == key) return true;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return false;
}

// 3) Path from root to given key - Recursive
// Returns true if path exists and fills vector with path nodes
bool pathToNodeRecursive(Node* root, int key, vector<int>& path) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == key) return true;

    if (pathToNodeRecursive(root->left, key, path) || pathToNodeRecursive(root->right, key, path))
        return true;

    path.pop_back(); // backtrack
    return false;
}

// 4) Path from root to given key - Iterative
// Uses parent map and BFS to reconstruct path
vector<int> pathToNodeIterative(Node* root, int key) {
    vector<int> path;
    if (!root) return path;

    queue<Node*> q;
    q.push(root);

    unordered_map<Node*, Node*> parent;
    parent[root] = nullptr;

    Node* target = nullptr;

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->data == key) {
            target = curr;
            break;
        }
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    if (!target) return path;

    for (Node* cur = target; cur != nullptr; cur = parent[cur]) {
        path.push_back(cur->data);
    }
    reverse(path.begin(), path.end());
    return path;
}

// 5) Lowest Common Ancestor (LCA) - Recursive
Node* lowestCommonAncestor(Node* root, int a, int b) {
    if (!root) return nullptr;
    if (root->data == a || root->data == b) return root;

    Node* leftLCA = lowestCommonAncestor(root->left, a, b);
    Node* rightLCA = lowestCommonAncestor(root->right, a, b);

    if (leftLCA && rightLCA) return root;

    return leftLCA ? leftLCA : rightLCA;
}

// 6) Lowest Common Ancestor (LCA) - Iterative
// Uses parent map and ancestor set
Node* lowestCommonAncestorIterative(Node* root, int a, int b) {
    if (!root) return nullptr;

    unordered_map<Node*, Node*> parent;
    queue<Node*> q;
    q.push(root);
    parent[root] = nullptr;

    Node* nodeA = nullptr;
    Node* nodeB = nullptr;

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->data == a) nodeA = curr;
        if (curr->data == b) nodeB = curr;
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    if (!nodeA || !nodeB) return nullptr;

    unordered_set<Node*> ancestors;
    for (Node* cur = nodeA; cur != nullptr; cur = parent[cur]) {
        ancestors.insert(cur);
    }

    for (Node* cur = nodeB; cur != nullptr; cur = parent[cur]) {
        if (ancestors.count(cur)) return cur;
    }

    return nullptr;
}

int main() {
    Node* root = buildTreeLevelOrder();

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    cout << "\nSearch (recursive): " << (searchRecursive(root, key) ? "Found" : "Not Found") << "\n";
    cout << "Search (iterative): " << (searchIterative(root, key) ? "Found" : "Not Found") << "\n";

    vector<int> pathRec;
    bool foundRec = pathToNodeRecursive(root, key, pathRec);
    cout << "Path to node (recursive): ";
    if (foundRec) {
        for (int v : pathRec) cout << v << " ";
        cout << "\n";
    } else {
        cout << "No path found\n";
    }

    vector<int> pathIter = pathToNodeIterative(root, key);
    cout << "Path to node (iterative): ";
    if (!pathIter.empty()) {
        for (int v : pathIter) cout << v << " ";
        cout << "\n";
    } else {
        cout << "No path found\n";
    }

    int a, b;
    cout << "\nEnter two nodes to find LCA:\n";
    cin >> a >> b;

    Node* lcaRec = lowestCommonAncestor(root, a, b);
    cout << "LCA (recursive): " << (lcaRec ? lcaRec->data : -1) << "\n";

    Node* lcaIter = lowestCommonAncestorIterative(root, a, b);
    cout << "LCA (iterative): " << (lcaIter ? lcaIter->data : -1) << "\n";

    return 0;
}
