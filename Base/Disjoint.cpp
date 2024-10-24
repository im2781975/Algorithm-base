#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;
int parent[n], Rank[n];
int findparent(int node){
    if(node == parent[node])
        return node;
    int x = findparent(parent[node]);
    parent[node] = x;
    return parent[node];
}
void Union(int a, int b){
    a = findparent(a); b = findparent(b);
    if(Rank[a] < Rank[b])
        parent[a] = b;
    if(Rank[b] < Rank[a])
        parent[b] = a;
    else{
        parent[b] = a;
        Rank[a]++;
    }
        
}
int main(){
    for(int i = 0; i < n; i++)
        parent[i] = i;
    int node, edge; cin >> node >> edge;
    for(int i = 1; i <= edge; i++){
        int u, v; cin >> u >> v;
        Union(u, v);
    }
    for(int i = 1; i <= n; i++)
        cout << Rank[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++)
        cout << parent[i] << " ";
}


