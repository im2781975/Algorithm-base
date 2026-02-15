// count number of sink nodes
#include<bits/stdc++.h>
using namespace std;
// sink node is a node with no outgoing edges.
int countSink(int n, int e, int edgeFrom[], int edgeTo[])
{
    // Array for marking the non-sink node.
    int mark[n];
    //initialize mark array as 0;
    memset(mark, 0, sizeof mark);
    // Marking the non-sink node.
    for (int i = 0; i < e; i++)
        mark[edgeFrom[i]] = 1;
    // Counting the sink nodes.
    int count = 0;
    for (int i = 1; i <= n ; i++)
        if (!mark[i])
            count++;
    return count;
}
int main()
{
    int n = 4, e = 2;
    int edgeFrom[] = { 2, 4 };
    int edgeTo[] = { 3, 3 };
    cout << countSink(n, e, edgeFrom, edgeTo) << endl;
    return 0;
}
#include<bits/stdc++.h> 
using namespace std; 
// function to add an edge in an  directed graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
} 
void BFSUtil(int u, vector<int> adj[], vector<bool> &visited) 
{ 
    list<int> q; 
    visited[u] = true; 
    q.push_back(u); 
 
    while(!q.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        u = q.front(); 
        cout << u << " "; 
        q.pop_front(); 
   
        for (int i = 0; i != adj[u].size(); ++i) 
        { 
            if (!visited[adj[u][i]]) 
            { 
                visited[adj[u][i]] = true; 
                q.push_back(adj[u][i]); 
            } 
        } 
    } 
} 
void BFS(vector<int> adj[], int V) 
{ 
    vector<bool> visited(V, false); 
    for (int u=0; u<V; u++) 
        if (visited[u] == false) 
            BFSUtil(u, adj, visited); 
} 
int main() 
{ 
    int V = 5; 
    vector<int> adj[V]; 
  
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    BFS(adj, V); 
    return 0; 
}
// modified BFS for adjacency matrix 
#include <iostream> 
#include <queue> 
using namespace std; 
void printBFS(int** edges, int V, int start, int* visited); 
void BFSHelper(int** edges, int V); 
void addEdge(int** edges, int u, int v); 
  
void addEdge(int** edges, int u, int v) { edges[u][v] = 1; } 
void printBFS(int** edges, int V, int start, int* visited) 
{ 
    if (V == 0) 
        return; 
    queue<int> BFS; 
    BFS.push(start); 
    visited[start] = 1; 
    while (!BFS.empty()) { 
        int data = BFS.front(); 
        BFS.pop(); 
        cout << data << " "; 
        for (int i = 0; i < V; i++) { 
            if (edges[data][i] == 1) { 
                if (visited[i] == 0) { 
                    BFS.push(i); 
                    visited[i] = 1; 
                } 
            } 
        } 
    } 
} 
void BFSHelper(int** edges, int V) 
{ 
    if (V == 0) 
        return; 
    int* visited = new int[V]; 
    for (int i = 0; i < V; i++)
        visited[i] = 0; 
    for (int i = 0; i < V; i++) { 
        if (visited[i] == 0)
            printBFS(edges, V, i, visited); 
    } 
} 
int main() 
{ 
    int V = 5, E = 6; 
    if (E == 0){ 
        for (int i = 0; i < V; i++)
            cout << i << " "; 
        return 0;
        } 
    //It initializes a 2D array edges to represent the 
    //adjacency matrix, setting all entries to 0.
    int** edges = new int*[V]; 
    for (int i = 0; i < V; i++){ 
        edges[i] = new int[V]; 
        for (int j = 0; j < V; j++)
            edges[i][j] = 0; 
    } 
    addEdge(edges, 0, 4); 
    addEdge(edges, 1, 2); 
    addEdge(edges, 1, 3); 
    addEdge(edges, 1, 4); 
    addEdge(edges, 2, 3); 
    addEdge(edges, 3, 4);
    BFSHelper(edges, V); 
    return 0; 
}

