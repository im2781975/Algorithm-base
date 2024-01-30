#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
char grid[maxn][maxn];
bool visited[maxn][maxn];
pair< int, int>parent[maxn][maxn];
// directional array
int dx[4]{ 1, 0, -1, 0};
int dy[4]{ 0, 1, 0, -1};
char dir[4] {'D', 'R', 'U', 'L'};
void bfs(int x, int y, int n, int m)
{
    queue<pair <int, int> > q;
    q.push({ x, y});
    visited[x][y]=true;
    parent[x][y] = { -1, -1};
    while(!q.empty())
    {
        bool ok = true;
        pair<int, int>a=q.front();
        q.pop();
        cout << "Current cell -> " << a.first << " " << a.second << "\n";
        for(int i=0; i<4; i++)
        {
            int dx_, dy_;
            dx_ = a.first + dx[i];
            dy_ = a.second + dy[i];
            //cout << dx_ << " " << dy_ << "\n";
            ok = false;
            if (dx_ >= 0 && dx_ < n && dy_ >= 0 && dy_ < m && !visited[dx_][dy_] && grid[dx_][dy_] != '#') {
                q.push({dx_, dy_});
                visited[dx_][dy_] = true;
                parent[dx_][dy_] = {a.first, a.second};
            }
        }
        if(!ok)
            break;
    }
    
}
int main()
{
    int m, n;
    cin >> m >> n;
    int x1, y1, x2, y2;
    // x1,y1 start point
    // x2, y2 end point
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j]=='A')
            {
                x1 = i;
                y1 = j;
            }
            if (grid[i][j]=='B')
            {
                x2 = i;
                y2 = j;
            }
        }
    }
    bfs(x1, y1, n, m);
    if(visited[x2][y2])
    {
        cout << "Yes";
        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                cout << visited[i][j] << " ";
            cout << "\n";
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cout << parent[i][j].first<< " " << pare t[i][j].second << "\n";
            }
        }*/
        vector<pair<int, int> >path;
        path.push_back({ x2, y2});
        int x=x2, y=y2;
        while(parent[x][y]!=make_pair(-1, -1))
        {
            pair<int, int>p=parent[x][y];
            int x=p.first, y=p.second;
            path.push_back({x, y});
        }
        reverse(path.begin(), path.end());
       /* for(auto val:path)
            cout << val.first << " " << val.second << "\n";*/
        string ans;
        for(int i=0; i<path.size()-1; i++)
        {
            for(int j=0; j<4; j++)
            {
                int dx_,dy_;
                dx_=path[i].first + dx[j];
                dy_ = path[i].second + dy[j];
                if(dx_==path[i+1].first && dy_==path[i+1].second)
                {
                    ans.push_back(dir[j]);
                    break;
                }
            }
        }
        cout << ans.size();
        cout << ans;
    }
}
