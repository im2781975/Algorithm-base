// convert an Adjacency Matrix to an Adjacency List.
#include <iostream>
#include <vector>
using namespace std;

// Function to convert an adjacency matrix to an adjacency list
vector<vector<int>> adjacencyMatrixToList(vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                adjacencyList[i].push_back(j);
            }
        }
    }
    return adjacencyList;
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }
    vector<vector<int>> adjacencyList = adjacencyMatrixToList(adjacencyMatrix);

    cout << "The adjacency list is:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < adjacencyList[i].size(); ++j) {
            cout << adjacencyList[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

