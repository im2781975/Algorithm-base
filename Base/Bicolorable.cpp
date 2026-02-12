#include<bits/stdc++.h>
// M Coloring problem using backtracking
using namespace std;
#define node 4
bool IsSafe(int src, int graph[node][node], int color[], int type){
    for(int v = 0; v < node; v++){
        if(graph[src][v] && type == color[v])
            return false;
    }
    return true;
}
bool graphcolor(int graph[node][node], int num, int color[], int src){
    if(src == node)
        return true;
    for(int i = 1; i <= num; i++){
        if(IsSafe(src, graph, color, i)){
            color[src] = i;
            if(graphcolor(graph, num, color, src + 1))
                return true;
                 //If assigning color c doesn't lead to a solution then remove it
            color[src] = 0;
        }
    }
    return false;
}
void print(int color[]){
    for(int i = 0; i < node; i++)
        cout << color[i] << " ";
}
int main(){
    int graph[node][node] = {
        { 0, 1, 1, 1 }, { 1, 0, 1, 0 },
        { 1, 1, 0, 1 }, { 1, 0, 1, 0 },
    };
    int num = 3; 
    //represent the color type
    int color[node] = {0}
    for(int i = 0; i < node; i++)
        color[i] = 0;
    for(int i = 0; i < node; i++){
        if(graphcolor(graph, num, color, 0) == false){
            cout << "Solution doesn't exit";
            return 0;
        }
    }
    print(color);
}
using namespace std;
const int n = 1e5;
int visited[n + 1];
int color[n];
vector <int> adj[n + 1];
bool DFS(int u, int type){
    visited[u] = 1;
    color[u] = type;
    for(int v : adj[u]){
        if(!visited[v]){
            if(!DFS(v, 3 - type))
                return false;
        }
        else if(color[v] == color[u])
            return false;
    }
    return true;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool IsBicolorable = true;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool ok = DFS(i, 1);
            if(!ok){
                IsBicolorable = false;
                break;
            }
        }
    }
    if(!IsBicolorable)
        cout << "Impossible";
    else{
        for(int i = 1; i <= node; i++)
            cout << color[i] << " ";
    }
}
//find out whether a given graph is Bipartite or not
#include<iostream>
#include<queue>
using namespace std;
#define node 4
bool IsBaipartite(int graph[][node], int src){
    //Create a color array. Vertex  number is used as index in this array. value '-1'used 
    //to indicate that no color is assigned to vertex 'i'. value 1 is used to indicate first color & 0 for second color.
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    color[src] = 1;
    queue <int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        //Return false if there is a self-loop 
        if(graph[u][u] == 1)
            return false;
        for(int v = 0; v < node; v++){
            if(graph[u][v] == 1 && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(graph[u][v] == 1 && color[u] == color[v])
                return false;
        }
    }
    return true;
}
int main(){
    int graph[][node] = 
    {{0, 1, 0, 1}, {1, 0, 1, 0},
    {0, 1, 0, 1}, {1, 0, 1, 0} };
    IsBaipartite(graph, 0)? cout << "Yes" : cout << "No";
}
/***/
bool IsBipartite(int node, vector <int> adj[]){
    //vector to store colour of vertex assigning all to -1
    vector <int> color(node, -1);
    queue <pair<int, int> >q;
    for(int u = 0; u < node; u++){
        if(color[u] == -1){
            color[u] = 0;
            q.push({u, 0});
            while(!q.empty()){
                pair <int, int> p = q.front();
                q.pop();
                //first node
                int v = p.first;
                //color of first node
                int c = p.second;
                for(int j : adj[v]){
                    //if already coloured with parent vertex 
                    //color then bipartite graph is not possible
                    if(color[j] == c)
                        return 0;
                    if(color[j] == -1){
                        color[j] = (c) ? 0 : 1;
                        q.push({j, color[j]});
                    }
                        
                }
            }
        }
    }
    return 1;
}
int main(){
    int node = 4, edge = 8;
    vector <int> adj[node];
    adj[0] = {1, 3}; adj[1] = {0, 2};
    adj[2] = {1, 3}; adj[2] = {0, 2};
    (IsBipartite(node, adj))? cout << "Yes" : cout << "No";
}
/***/
#define node 4
bool colorGraph(int graph[][node], int color[], int u, int c){
    if(color[u] != -1 && color[u] != c)
        return false;
    //color this pos as c and all its neighbours and 1-c
    color[u] = c;
    bool ans = true;
    for(int v = 0; v < node; v++){
        if(graph[u][v]){
            if(color[v] == -1)
                ans &= colorGraph(graph, color, v, 1 - c);
            if(color[v] != -1 && color[v] != 1 - c)
                return false;
        }
        if(!ans)
            return false;
    }
    return true;
}
bool IsBipartite(int graph[][node]){
    int color[node];
    for(int i = 0; i < node; i++)
        color[i] = -1;
    int src = 0;
    return colorGraph(graph, color, src, 1);
}
int main(){
    int graph[][node] = 
    {{0, 1, 0, 1}, {1, 0, 1, 0},
    {0, 1, 0, 1}, {1, 0, 1, 0} };
    IsBipartite(graph)? cout << "Yes" : cout << "No";
}
/***/
