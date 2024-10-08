#include<bits/stdc++.h>
using namespace std;
main(){
    int node; cin >> node;
    vector <pair <int, int> >adjList[node];
    adjList[0] = {{1, 2}}; adjList[1] = {{3, 4}};
    adjList[2] = {{5, 6}}, adjList[3] = {{7, 8}, {9, 10}};
    adjList[0].push_back({11, 12});
    adjList[1].push_back({13, 14});
    adjList[2].push_back({15, 16});
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j].first << " " << adjList[i][j].second << " ";
        cout << "\n";
    }
}
/***/
main(){
    int node = 4;
    vector <int> adjList[node];
    adjList[0] = {1}; adjList[1] = {0, 2, 3};
    adjList[2] = {1, 3}; adjList[3] = {1, 2};
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        cout << "\n";
    }
}
/***/
main(){
    int node = 4;
    vector <int> adjList[node];
    adjList[0] = {2, 3};
    adjList[1] = {1, 1, 2, 2};
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        cout << "\n";
    }
}
/***/
main(){
    int node = 4;
    vector <vector <pair<int, int> > >adjList(node);
    adjList[0] = {{1, 2}}; adjList[1] = {{3, 4}};
    adjList[2] = {{1, 7}, {2, 3}}; adjList[3] = {{9, 6}};
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j]. first << " " << adjList[i][j].second << " ";
        cout << "\n";
    }
}
/***/
main(){
    int node, edge; cin >> node >> edge;
    vector <pair<int, int> >adjList[node];
    for(int i = 1; i <= edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= adjList[i].size(); j++)
            cout << adjList[i][j].first << " " << adjList[i][j].second;
        cout << "\n";
    }
}
/***/
