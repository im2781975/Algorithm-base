// convert an Adjacency Matrix to an Adjacency List.
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adjMatrixToList(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> adjMatrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
    vector<vector<int>> adjList = adjMatrixToList(adjMatrix);

    cout << "The adjacency list is:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

