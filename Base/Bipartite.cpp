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
