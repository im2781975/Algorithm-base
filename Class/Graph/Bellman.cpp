#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int source, destination;
};
void bellmanFordUnweighted(vector<Edge>& edges, int V, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;
    for (int i = 1; i < V; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + 1 < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + 1;
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        scout << "Shortest distance from " << source << " to " << i << " is " << distance[i] << "\n";
    }
}
int main() {
    int n = 5;
    vector<Edge> edges {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4} };
    int source = 0;
    bellmanFordUnweighted(edges, n , source);
    return 0;
}
