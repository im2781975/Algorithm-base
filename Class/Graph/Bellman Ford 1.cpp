#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int source, destination, weight;
};
// Function to perform Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;
    // Relax all edges |V| - 1 times
    for (int i = 1; i < numVertices; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }
    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains negative weight cycle." << endl;
            return;
        }
    }
    // Print the shortest distances from the source to all vertices
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " " << distance[i] << "\n";
    }
}
int main() {
    vector<Edge> edges = {
    {0, 1, -1}, {0, 2, 4},
    {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
    {3, 2, 5}, {3, 1, 1}, {4, 3, -3}, };
    int numVertices = 5;
    int source = 0;
    bellmanFord(edges, numVertices, source);
    return 0;
}
