//find shortest distance in a multistage graph.
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 8
int shortestDist(int graph[N][N]){
    int dist[N]; dist[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        dist[i] = INF;
        for(int j = i; j < N; j++){
            if(graph[i][j] == INF)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}
int main(){
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
    cout << shortestDist(graph);
}
using namespace std;
//find the shortest path using multistage graph
using ump = pair <int, unordered_map<int, int> >;
int shortestPath(vector <ump> &graph, int src, int trg, int k){
    vector <int> dist(graph.size(), INT_MAX);
    dist[trg] = 0;
    //Loop over each stage from k-1 to 1
    for(int i = k - 1; i >= 0; i--){
        //Loop over all vertices in the current stage
        for(int u = 0; u < graph.size(); u++){
            if(graph[u].first != i)
                continue;
            for(const auto &v: graph[u].second){
                if(dist[v.first] != INT_MAX)
                     dist[u] = min(dist[u], v.second + dist[v.first]);
            }
        }
    }
    //Return the shortest path distance from source to target
    return dist[src];
}
int main(){
    //Each stage represented a level of nodes
    vector <ump> graph = {
        {0, {{1, 2}, {2, 9}}},
        {1, {{3, 6}, {4, 3}}},  
        {2, {{4, 1}}},          
        {3, {{5, 7}, {6, 2}}},  
        {4, {{5, 1}, {6, 5}}},  
        {5, {{7, 4}}},          
        {6, {{7, 6}}},          
        {7, {}}
    };
    cout << shortestPath(graph, 0, 7, 4) << " ";
}
