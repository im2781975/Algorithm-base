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
using namespace std;
//find out whether a given graph can be converted to two Cliques or not
const int node = 5;
bool IsBipartite(int graph[][node], int src, int color[]){
    color[src] = 1;
    queue <int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 0; v < node; v++){
            if(graph[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(graph[u][v] && color[u] == color[v])
                return false;
        }
    }
    return true;
}
bool IsBicolorable(int graph[][node]){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    for(int i = 0; i < node; i++){
        if(color[i] == -1){
            if(!IsBipartite(graph, i, color))
                return false;
        }
    }
    return true;
}
int main(){
    int g[node][node] = 
    {{0, 1, 1, 1, 0},{1, 0, 1, 0, 0},{1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},{0, 0, 0, 1, 0}};
    int graph[node][node];
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            //Ignore diagonal.
            graph[i][j] = (i != j) ? !g[i][j] : 0;
        }
    }
    (IsBicolorable(graph)) ? cout << "Yes" : cout << "No";
}
//Grid Traversal
using namespace std;
int row, col;
const int n = 200;
int arr[n][n], level[n][n], visited[n][n];
int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
bool IsInside(pair <int, int> p){
    int x = p.first, y = p.second;
    if(x >= 0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}
bool IsForbidden(pair<int, int> p){
    int x = p.first, y = p.second;
    if(arr[x][y] == -1)
        return true;
    return false;
}
void BFS(pair <int, int> src){
    queue <pair <int, int> >q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);
    while(!q.empty()){
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first, y = head.second;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            pair <int, int> adj = {newx, newy};
            if(IsInside(adj) && !IsForbidden(adj) && !visited[newx][newy]){
                visited[newx][newy] = 1;
                level[newx][newy] = level[x][y] + 1;
                q.push(adj);
            }
        }
    }
}
int main(){
    cin >> row >> col;
    pair <int, int> src, dst;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            level[i][j] = -1;
    }
    for(int i = 0; i < row; i++){
        string str; cin >> str;
        for(int j = 0; j < col; j++){
            if(str[j] == '#')
                arr[i][j] = -1;
            else if(str[j] == 'A')
                src = {i, j};
            else if(str[j] == 'B')
                dst = {i, j};
        }
    }
    BFS(src);
    (level[dst.first][dst.second] == -1)? cout << "No" : cout << "Yes " << level[dst.first][dst.second];
}
//generate a graph for a given fixed degrees
using namespace std;
// Function to validate if the degree sequence can represent a simple undirected graph.
bool Isvalid(const int Deg[], int n){
    int DegreeSum = 0;
    for(int i = 0; i < n; i++){
        if(Deg[i] < 0 || Deg[i] >= n)
            return false;
        DegreeSum += Deg[i];
    }
    return DegreeSum % 2 == 0;
}
void print(int DegSeq[], int n){
    int mat[n][n] = {0};
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(DegSeq[i] > 0 && DegSeq[j]){
                DegSeq[i]--; DegSeq[j];
                mat[i][j] = 1; mat[j][i] = 1;
            }
        }
    }
    //setw controls the width for alignment, making the output more structured.
    cout << "\n" << setw(3) << "     ";
    for (int i = 0; i < n; i++)
        cout << setw(3) << "(" << i << ")";
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << "(" << i << ")";
        for (int j = 0; j < n; j++)
            cout << setw(5) << mat[i][j];
        cout << "\n\n";
    }
    cout << "\n";
}
int main(){
    int DegSeq[]{2, 2, 1, 1, 1};
    int n = sizeof(DegSeq)/sizeof(DegSeq[0]);
    if(Isvalid(DegSeq, n))
        print(DegSeq, n);
    else
        cout << "The degree sequence is invalid for generating a simple undirected graph.\n";
}

// incremental connectivity
using namespace std;
int root(int arr[], int i){
    while(arr[i] != i){
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void weightUnion(int arr[], int Rank[], int a, int b){
    int rootA = root(arr, a);
    int rootB = root(arr, b);
    if(Rank[rootA] < Rank[rootB]){
        arr[rootA]  = arr[rootB];
        Rank[rootB] += Rank[rootA];
    }
    else{
        arr[rootB] = arr[rootA];
        Rank[rootA] += Rank[rootB];
    }
}
bool Equal(int arr[], int a, int b){
    return (root(arr, a) == root(arr, b));
}
void query(int type, int x, int y, int arr[], int Rank[]){
    if(type == 1){
        (Equal(arr, x, y)) ? cout << "Yes\n" : cout << "No\n";
    }
    else if(type == 2){
        if(!Equal(arr, x, y))
            weightUnion(arr, Rank, x, y);
    }
}
int main(){
    int n = 7;
    int arr[n], Rank[n];
    for(int i = 0; i < n; i++){
        arr[i] = i;
        Rank[i] = 1;
    }
    int q = 11;
    query(1, 0, 1, arr, Rank);
    query(2, 0, 1, arr, Rank);
    query(2, 1, 2, arr, Rank);
    query(1, 0, 2, arr, Rank);
    query(2, 0, 2, arr, Rank);
    query(2, 2, 3, arr, Rank);
    query(2, 3, 4, arr, Rank);
    query(1, 0, 5, arr, Rank);
    query(2, 4, 5, arr, Rank);
    query(2, 5, 6, arr, Rank);
    query(1, 2, 6, arr, Rank);
}
