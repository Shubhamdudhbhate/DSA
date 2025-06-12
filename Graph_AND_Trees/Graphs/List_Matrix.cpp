#include <iostream>
#include <vector>
using namespace std;

void printAdjList(const vector<vector<int>>& adjList) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}


void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < adjMatrix.size(); i++) {
        for (int j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Adjacency List and Matrix
    vector<vector<int>> adjList(V);
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Print both representations
    printAdjList(adjList);
    printAdjMatrix(adjMatrix);

    return 0;
}
