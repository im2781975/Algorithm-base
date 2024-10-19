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
