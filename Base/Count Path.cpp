//There has n cities, and m roads between them.goal is to reach from city 1 to n.Print "YES" if  goal is possible else "NO"
using namespace std;
const int maxi = 1e3;
bool visited[maxi];
vector <int> adj[maxi];
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v])
            DFS(v);
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= node; i++)
        visited[i] = false;
    DFS(1);
    if(visited[node])
        cout << "Yes";
    else
        cout << "No";
}
