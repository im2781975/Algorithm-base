#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int adjMatrix[n * n][n * n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}
