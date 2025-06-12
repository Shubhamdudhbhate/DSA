#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// --- BFS using Queue ---
void bfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// --- Recursive DFS ---
void dfsRecursive(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }
    }
}

// --- Iterative DFS using Stack ---
void dfsIterative(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> s;
    s.push(start);

    cout << "Iterative DFS: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors in reverse to mimic recursive DFS order
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

// --- Main function ---
int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Sample graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2};
    adj[5] = {3};

    int start = 0;

    // BFS
    bfs(start, adj, V);

    // Recursive DFS
    vector<bool> visitedRec(V, false);
    cout << "Recursive DFS: ";
    dfsRecursive(start, adj, visitedRec);
    cout << endl;

    // Iterative DFS
    dfsIterative(start, adj, V);

    return 0;
}
