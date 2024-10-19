//Building Roads
using namespace std;
const int maxn = 1e7;
vector <int> adj[maxn];
vector <bool> visited(maxn);
void DFS(int src){
     visited[src] = true;
     for(int child : adj[src]){
         if(!visited[child])
             DFS(child);
     }
 }
 int main(){
     int node, edge; cin >> node >> edge;
     for(int i = 1; i <= edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     vector <int> ans;
     for(int i = 1; i <= node; i++){
         if(!visited[i]){
             ans.push_back(i);
             DFS(i);
         }
     }
     for(int i = 0; i < ans.size(); i++)
         cout << ans[i] << " ";
 }
