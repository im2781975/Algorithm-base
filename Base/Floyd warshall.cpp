#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 505;
int dist[N][N];
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
        if(i == j)
            dist[i][j] = 0;
        else
            dist[i][j] = INT_MAX;
    }
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for(int k = 1; k <= node; k++){
        for(int u = 1; u <= node; u++){
            for(int v = 1; v <= node; v++)
            if(dist[u][k] < INF && dist[k][v] < INF)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
        if(dist[i][j] == INF)
            cout << "__";
        else
            cout << dist[i][j] << " ";
        cout << "\n";
    }
}
/***/
using namespace std;
#define node 4
#define INF 99999
void print(int dist[][node]){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            (dist[i][j] == INF) ? cout << "INF " : cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
void Floydwar(int dist[][node]){
    for(int k = 0; k < node; k++){
        for(int u = 0; u < node; u++){
            for(int v = 0; v < node; v++){
                if(dist[u][k] !=  INF && dist[k][v] != INF)
                    dist[u][v] = dist[u][k] +  dist[k][v];
            }
        }
    }
    print(dist);
}
int main(){
    int graph[node][node] = 
    { { 0, 5, INF, 10 }, { INF, 0, 3, INF },
    { INF, INF, 0, 1 }, { INF, INF, INF, 0 } };
    Floydwar(graph);
}
/***/
//check if there is a negative weight cycle using Floyd Warshall Algorithm
using namespace std;
#define node 4
#define INF 99999
bool NegCycle(int graph[][node]){
    int dist[node][node];
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++)
            dist[i][j] = graph[i][j];
    }
    for(int k = 0; k < node; k++){
        for(int u = 0; u < node; u++){
            for(int v = 0; v < node; v++){
                if(dist[u][k] + dist[k][v] < dist[u][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }
    for(int i = 0; i < node; i++){
        if(dist[i][i] < 0)
            return true;
    }
    return false;
}
int main(){
    int graph[node][node] = 
    { {0 , 1 , INF, INF}, {INF , 0   , -1  , INF},
    {INF , INF , 0 ,-1},{-1  , INF , INF ,   0}};
    (NegCycle(graph)) ? cout << "Yes" : cout << "No";
}
/***/
using namespace std;
const int N 1e3;
const long long INF 1e18;
int dist[N][N];
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++)
            dist[i][j] = INF;
    }
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int i = 1; i <= node; i++)
        dist[i][i] = 0;
    for(int k = 1; k <= node; k++){
        for(int u = 1; u <= node; u++){
            for(int v = 1; v <= node; v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }
    int query; cin >> query;
    for(int i = 0; i < query; i++){
        int u, v; cin >> u >> v;
        if(dist[u][v] == INF)
            cout << "-1";
        else
            cout << dist[u][v];
    }
}
