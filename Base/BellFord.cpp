#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;
int dist[n], parent[n];
vector <pair <int, int> >adjList[n];
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < node; i++)
        dist[i] = INT_MAX;
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }
    bool NegCycle = false;
    int lastUpdateNode = -1;
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= node; j++){
            for(pair<int, int> child : adjList[node]){
                int u = node, v = child.first, w = child.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    if(i == node){
                        NegCycle = true;
                        lastUpdateNode = v;
                    }
                }
            }
        }
    }
    if(NegCycle){
        cout << "Yes";
        int select = lastUpdateNode;
        for(int i = 1; i < node; i++)
            select = parent[select];
        int first = select;
        vector <int> cycle;
        cycle.push_back(select);
        while(true){
            select = parent[select];
            cycle.push_back(select);
            if(select == first)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for(int i = 0; i!= cycle.size(); i++)
            cout << cycle[i] << " ";
    }
    else
        cout << "No";
} 
