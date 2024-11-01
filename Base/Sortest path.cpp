//print path
using namespace std;
const int n = 1e5;
int visited[n], level[n];
vector <int> adj[n];
void BFS(int src){
    queue <int> q;
    visited[src] = 1; level[src] = 0;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(0);
    for(int i = 0; i < node; i++)
        cout << "Node: " << i << " Level: " << level[i] << "\n";
}
