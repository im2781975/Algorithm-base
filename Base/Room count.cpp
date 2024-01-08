//sequential cell is count as a room.find number of rooms
#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int arr[N][N];
int visited[N][N];

int m, n;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> p)
{
    int x = p.first;
    int y = p.second;

    if (x >= 0 && x < m && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

bool is_forbidden(pair<int, int> p)
{
    int x = p.first;
    int y = p.second;
    if (arr[x][y] == -1)
    {
        return true;
    }
    return false;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};
            if (is_inside(adj_node) && !is_forbidden(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}
pair<int,int>find_unvisited()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0 && visited[i][j]==0)
            {
                return {i,j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == '#')
            {
                arr[i][j] = -1;
            }

        }
    }
    int room_cnt=0;
    while(1)
    {
        pair<int, int>unvisited_pos=find_unvisited();
        if(unvisited_pos==pair<int,int>(-1,-1))
        {
            break;
        }
        bfs(unvisited_pos);
        room_cnt++;
    }
    cout<<room_cnt;
}

