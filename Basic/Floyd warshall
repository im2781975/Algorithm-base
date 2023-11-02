#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int INF=1e9;
int d[N][N];

int main()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            d[i][j]=INF;
        }
    }
    for(int i=0; i<edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }
    for(int i=1; i<=node; i++)
    {
        d[i][i]=0;
    }
    for(int k=1; k<=node; k++)
    {
        for(int u=1; u<=node; u++)
        {
            for(int v=1;v<=node; v++)
            {
                d[u][v]=min(d[u][v],d[u][k]+d[k][v]);
            }
        }
    }
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
}
