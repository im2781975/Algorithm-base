#include<bits/stdc++.h>
using namespace std;
void DFS(vector <int>adjList[], vector<int>&visited, int cur){
    visited[cur] = 1;
    for(int x : adjList[cur]){
        if(!visited[x])
            DFS(adjList, visited, x);
    }
}
void aPoint(vector <int> adjList[], int node){
    for(int i = 1; i <= node; i++){
        int components = 0;
        vector <int> visited(node + 1 , 0);
        for(int j = 1; j <= node; j++){
            if(j != i && !visited[j]){
                    components++;
                    DFS(adjList, visited, j);
            }
        }
        if(components > 1)
            cout << i << " ";
    }
}
void addEdge(vector <int> adjList[], int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
int main(){
    int node = 5;
    vector <int> adjList[node + 1];
    cout << "Articulation Point\n";
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 3, 4);
    aPoint(adjList, node);
}
