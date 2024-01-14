//print path in a BFS traversal. Use adjacency matrix as your graph representation.
#include <iostream>
#include <queue>
using namespace std;
#define N 101
int graph[N][N];
bool visited[N];
void printPath(int parent[], int start, int end) {
    if (start == end) {
        cout << start << " ";
        return;
    }
    printPath(parent, start, parent[end]);
    cout << end << " ";
}
void BFS(int start, int end, int nodes) {
    queue<int> q;
    bool found = false;
    int parent[N];

    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < nodes; i++) {
            //Iterates through all nodes in the graph to check if they
            //are adjacent to the current node and not yet visited
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                q.push(i);

                if (i == end) {
                    found = true;
                    break;
                }
            }
        }
    }

    if (found) {
        cout << "Path from " << start << " to " << end << ": ";
        printPath(parent, start, end);
    } else {
        cout << "No path from " << start << " to " << end << " exists.";
    }
}
int main() {
    int nodes, start, end;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the adjacency matrix (1 for connected, 0 for not):\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the starting & ending node: ";
    cin >> start >> end;
    BFS(start, end, nodes);
    return 0;
}
