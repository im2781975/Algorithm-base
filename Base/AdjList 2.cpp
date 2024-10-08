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
