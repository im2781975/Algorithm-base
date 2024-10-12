//print path in a BFS traversal. Use adjacency matrix as your graph representation
#include<iostream>
#include<queue>
using namespace std;
#define N 101
int graph[N][N];
bool visited[N];
void printpath(int parent[], int start, int end){
    if(start == end){
        cout << start << " ";
        return;
    }
    printpath(parent, start, parent[end]);
    cout << end << " ";
}
void BFS(int start, int end, int node){
    queue <int> q;
    bool found = false;
    int parent[N];
    for(int i = 0; i < node; i++){
        visited[i] = false;
        parent[i] = -1;
    }
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < node; i++){
            if(graph[cur][i] == 1 &&! visited[i]){
                visited[i] = true; 
                parent[i] = cur;
                q.push(i);
                
                if(i == end){
                    found = true;
                    break;
                }
            }
        }
        if(found)
            break;
    }
    if(found){
        cout << "path from " << start << " to " << end << " is: ";
        printpath(parent, start, end);
    }
    else
        cout << "No path exits";
}
int main(){
    int node; cin >> node;
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++)
            cin >> graph[i][j];
    }
    int start, end; cin >> start >> end;
    BFS(start, end, node);
}
