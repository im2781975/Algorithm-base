#include<bits/stdc++.h>
//find transpose of a graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}
void Display(vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void TransposeGraph(vector <int> transpose[], vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    vector <int> transpose[node];
    
    TransposeGraph(transpose, adj, node);
    //Display(adj, node);
    Display(transpose, node);
}
//Finds the representative of the set that i is an element of
using namespace std;
const int maxn = 1005;
int parent[maxn];
int Find(int i){
    if(parent[i] == i)
        return i;
    return Find(parent[i]);
}
int main(){
    for(int i = 0; i < maxn; i++)
        parent[i] = i;
    int rep1 = Find(1);
    int rep2 = Find(2);
    if(rep1 != rep2)
        parent[rep1] = rep2;
    int val = 1;
    int rep = Find(val);
    cout << "The representative of element " << val << " is: " << rep;
}
