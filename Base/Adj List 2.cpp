#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector <int> adjlist[node + 1];
    for(int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i = 1; i <= node; i++)
    {
        cout << i << "->";
        for(int j = 0; j< adjlist[i].size(); j++)
            cout << adjlist[i][j] << " ";
        cout << "\n";
    }
}
