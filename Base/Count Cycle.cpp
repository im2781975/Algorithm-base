// count cycles of length n in a given graph.
#include <bits/stdc++.h>
using namespace std;
const int V = 5;
void DFS(bool graph[][V], bool marked[], int n, int vert,
         int start, int& count)
{
    marked[vert] = true;
    // if the path of length (n-1) is found
    if (n == 0) {
        // mark vert as un-visited to make it usable again
        marked[vert] = false;
        // Check if vertex vert can end with vertex start
        if (graph[vert][start] && graph[start][vert]) {
            count++;
            return;
        }
        else
            return;
    }
    // For searching every possible path of length (n-1)
    for (int i = 0; i < V; i++)
        if (!marked[i] && graph[vert][i])
            // DFS for searching path by decreasing length by 1
            DFS(graph, marked, n - 1, i, start, count);
    // marking vert as unvisited to make it usable again.
    marked[vert] = false;
}
// Counts cycles of length N in an undirected
// and connected graph.
int countCycles(bool graph[][V], int n)
{
    // all vertex are marked un-visited initially.
    bool marked[V];
    memset(marked, 0, sizeof(marked));
 
    // Searching for cycle by using v-n+1 vertices
    int count = 0;
    for (int i = 0; i < V - (n - 1); i++) {
        DFS(graph, marked, n - 1, i, i, count);
 
        // ith vertex is marked as visited and will not be visited again.
        marked[i] = true;
    }
    return count / 2;
}
int main()
{
    bool graph[][V] = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 0, 1 },
        { 0, 1, 0, 1, 0 },{ 1, 0, 1, 0, 1 },{ 0, 1, 0, 1, 0 } };
    int n = 4;
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n);
    return 0;
}
// a round trip begins in a city, goes through more other cities, and finally returns to the starting city. 
//Every intermediate city on the route has to be distinct. print the number of cities on the route. 
//Then print cities in the order they will be visited.If there are no solutions, print "IMPOSSIBLE".
using namespace std;
#define maxn 1006
vector <int> adj[maxn];
bool visited[maxn];
vector <int> route;
bool foundCycle = false;
void DFS(int src, int parent){
    visited[src] = true;
    route.push_back(src);
    for(int child : adj[src]){
        if(!visited[child]){
            DFS(child, src);
            if(foundCycle)
                return;
        }
        else if(child != parent && route.size() > 2 && child == route[0]){
            route.push_back(child);
            foundCycle = true;
            return;
        }
    }
    route.pop_back();
}
int main(){
    int node, edge;cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= node; i++){
        route.clear();
        fill(visited, visited + node + 1, false);
        foundCycle = false;
        DFS(i, -1);
        if(foundCycle && route.size() >= 4){
            //Cycle includes start and end, so size is 4
            cout << route.size() -1<< "\n";
            for(int j = 0; j < route.size() - 1; j++)
                cout << route[j] << " ";
            return 0;
        }
    }
    cout << "Impossible";
}
