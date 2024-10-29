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
