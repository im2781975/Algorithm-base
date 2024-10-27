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
