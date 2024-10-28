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
//Count Sink node
using namespace std;
int countSink(int node, int edge, int src[], int dst[]){
    int arr[node] = {0};
    for(int i = 0; i < node; i++)
        arr[src[i]] = 1;
    int cnt = 0;
    for(int i = 1; i <= node; i++){
        if(arr[i] == 0)
            cnt++;
    }
    return cnt;
}
int main(){
    int node = 4, edge = 2;
    int src[]{2, 4}, dst[]{3, 3};
    cout << countSink(node, edge, src, dst);
}
//count walks from u to v with exactly k edges
int CountWalks(int graph[][node], int u, int v, int k){
    if(k == 0 && u == v)
        return 1;
    if(k == 1 && graph[u][v])
        return 1;
    if(k <= 0)
        return 0;
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(graph[u][i] == 1)
            cnt += CountWalks(graph,i, v, k - 1);
    }
    return cnt;
}
int main(){
    int graph[node][node] ={ { 0, 1, 1, 1 },{ 0, 0, 0, 1 },
    { 0, 0, 0, 1 },{ 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v, k);
}
