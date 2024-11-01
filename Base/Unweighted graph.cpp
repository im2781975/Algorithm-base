//printing shortest path between two vertices of unweighted graph
using namespace std;
const int n = 1e5;
int parent[n], dist[n];
bool visited[n];
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool BFS(vector <int> adj[], int src, int dst, int parent[], int dist[], int node){
    list <int> queue;
    for(int i = 0; i < node; i++){
        visited[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue.push_back(v);

                if (v == dst)
                    return true;
            }
        }
    }
    return false;
}
void sortestDist(vector <int> adj[], int src, int dst, int node){
    if(!BFS(adj, src, dst, parent, dist, node)){
        clog << "Src & dest aren't connect";
        return;
    }
    vector <int> path;
    int val = dst;
    path.push_back(val);
    while(parent[val]!= -1){
        path.push_back(parent[val]);
        val = parent[val];
    }
    cout << "Sortest pth length is: " << dist[dst];
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> adj[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        addEdge(adj, u, v);
    }
    int src, dst; cin >> src >> dst;
    sortestDist(adj, src, dst, node);
}
using namespace std;
#define node 4
int Travelling(int graph[node][node], int src){
    vector <int> vertix;
    for(int i = 0; i < node; i++){
        if(i != src)
            vertix.push_back(i);
    }
    int minPath = INT_MAX;
    do{
        int curPathWeight = 0;
        int k = src;
        for(int i = 0; i < vertix.size(); i++){
            curPathWeight += graph[k][vertix[i]];
            k = vertix[i];
        }
        curPathweight += graph[k][src];
        minPath = min(minpath, curPathWeight);
    }while(next_permutation(vertix.begin(), vertix.end()));
    return minPath;
}
int main(){
    int graph[][node] { 
        { 0, 10, 15, 20 }, { 10, 0, 35, 25 },
    { 15, 35, 0, 30 }, { 20, 25, 30, 0 } };
    cout << Travelling(graph, 0);
}
