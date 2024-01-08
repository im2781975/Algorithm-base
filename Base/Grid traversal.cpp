#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int arr[N][N];
int level[N][N];
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
    level[src.first][src.second] = 0;
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
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    pair<int, int> src, dst;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            level[i][j] = -1;
        }
    }
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
            else if (str[j] == 'A') // Fixed the array indexing from str[i] to str[j]
            {
                src = {i, j};
            }
            else if (str[j] == 'B') // Fixed the array indexing from str[i] to str[j]
            {
                dst = {i, j};
            }
        }
    }
    bfs(src);
    if (level[dst.first][dst.second] == -1)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes " << level[dst.first][dst.second];
    }
}
