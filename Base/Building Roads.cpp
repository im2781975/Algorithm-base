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
//Find the sortest route between cities
using namespace std;
int main(){
    int node, edge; cin >> node >> edge;
    vector <vector <int> >dist(node, vector <int> (node, INT_MAX));
    for(int i = 0; i < node ; i++)
        dist[i][i] = 0;
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        //Assuming cities are 1-base idx
        dist[u - 1][v - 1] = w;
        dist[v - 1][u - 1] = w;
    }
    for(int k = 0; k < node; k++){
        for(int u = 0; u < node; u++){
            for(int v = 0; v < node; v++){
                if(dist[u][k] != INT_MAX && dist[k][v] != INT_MAX)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int src, dst; cin >> src >> dst;
        cout << "Sortest distance between " << src << " to " << dst << " is: ";
        if(dist[src - 1][dst - 1] != INT_MAX)
            cout << dist[src - 1][dst - 1];
        else
            cout << "Not connected";
    }
}
