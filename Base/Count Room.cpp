//Count rooms
#include<bits/stdc++.h>
using namespace std;
const int dx[]{0, 0, -1, 1};
const int dy[]{-1, 1, 0, 0};
void DFS(int x, int y, vector <vector <char> > &mp, vector <vector <bool> > &visited){
    visited[x][y] = true;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && nx < mp.size() && ny >= 0 && ny < mp[0].size() && !visited[nx][ny] && mp[nx][ny] == '.')
            DFS(nx, ny, mp, visited);
    }
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > > mp(n, vector <char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> mp[i][j];
    }
    int roomCnt = 0;
    vector <vector <bool> > visited(n, vector <bool> (m, false));
    for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[0].size(); j++){
            if(mp[i][j] == '.' && !visited[i][j]){
                DFS(i, j, mp, visited);
                roomCnt++;
            }
        }
    }
    cout << roomCnt;
}
//count the number of rooms and the length of the longest room.
//length of the longest room means that room which contain maximum floor
using namespace std;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int DFS(vector <vector <char > > &Building, int x, int y){
    if(x < 0 || x >= Building.size() || y < 0 || y >= Building[0].size() || Building[x][y] == '#')
        return 0;
    int size = 1;
    Building[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += DFS(Building, nx, ny);
    }
    return size;
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > >Building(n, vector <char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> Building[i][j];
    }
    int roomCnt = 0, LongestRoom = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(Building[i][j] == '.'){
                int roomSize = DFS(Building, i, j);
                roomCnt++;
                LongestRoom = max(LongestRoom, roomSize);
            }
        }
    }
    cout << roomCnt << " " << LongestRoom << '\n';
}
//count the number of connected components in an undirected graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector <int> adj[], int u, vector <bool> &visited){
    visited[u] = true;
    for(int v = 0; v < adj[u].size(); v++){
        if(!visited[adj[u][v]]){
            DFS(adj, adj[u][v], visited);
        }
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    vector <bool> visited(node, false);
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(!visited[i]){
            DFS(adj, i, visited);
            cnt++;
        }
    }
    cout << cnt;
}
//count the number of distinct clusters (connected components) of 1s in a 2D grid (forest)
using namespace std;
typedef pair<int, int> node;
void BFS(vector <vector <int> >&forest, node st, vector <vector <bool> >&visited){
    queue <node> q; q.push(st);
    visited[st.first][st.second] = true;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        int dx[]{0, 0, -1, 1};
        int dy[]{-1, 1, 0, 0};
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < forest.size() && ny >= 0 && ny < forest[0].size() && forest[nx][ny] == 1 && !visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}
int main(){
    vector <vector <int> > forest = {
    {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}, {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int cnt = 0;
    int n = forest.size(), m = forest[0].size();
    vector <vector <bool> >visited(n, vector <bool> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(forest[i][j] == 1 && !visited[i][j]){
                BFS(forest, make_pair(i, j), visited);
                cnt++;
            }
        }
    }
    cout << cnt;
}
using namespace std;
#define N 100
int arr[N][N], visited[N][N];
int row, col;
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};
bool IsInside(int x, int y){
    return (x >= 0 && x < row && y >= 0 && y < col);
}
bool IsForbidden(int x, int y){
    return (arr[x][y] == -1);
}
void BFS(pair <int, int> src){
    queue <pair <int, int> >q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty()){
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first, y = head.second;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(IsInside(newx, newy) && !IsForbidden(newx, newy) && !visited[newx][newy]){
                visited[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}
pair <int, int> FindUnvisited(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 0 && visited[i][j] == 0)
                return {i, j};
        }
    }
    return {-1, -1};
}
int main(){
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        string str; cin >> str;
        for(int j = 0; j < col; j++){
            if(str[j] == '#')
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
                
        }
    }
    int roomCnt = 0;
    while(true){
        pair <int, int> unvisited = FindUnvisited();
        if(unvisited == pair <int, int> (-1, -1))
            break;
        BFS(unvisited);
        roomCnt++;
    }
    cout << roomCnt;
}
