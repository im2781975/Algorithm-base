#include<bits/stdc++.h>
using namespace std;
main(){
    int n; cin >> n;
    vector <vector <int> >vec(n, vector <int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            vec[i][j] = i + j;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << "\n";
    }
    vector <int> cev[n];
    cev[1].push_back(12);
    cev[1].push_back(14);
    cev[1].push_back(16);
    cev[2].push_back(18);
    cev[2].push_back(20);
    cev[3].push_back(22);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < cev[i].size(); j++)
            cout << cev[i][j] << " ";
        cout << "\n";
    }
}
/***/
main(){
    int node, edge; cin >> node >> edge;
    vector <int> adjlist[node + 1];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i = 0; i < node; i++){
        cout << i << " > ";
        for(int j = 0; j < adjlist[i].size(); j++)
            cout << adjlist[i][j] << " ";
        cout << "\n";
    }
}
/***/
