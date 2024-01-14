#include <bits/stdc++.h>
using namespace std;
void printPair() {
    int n = 4;
    vector<vector<pair<int, int>>> adj_list(n);

    adj_list[0] = {{1, 2}};
    adj_list[1] = {{3, 4}};
    adj_list[2] = {{1, 7}, {2, 3}};
    adj_list[3] = {{9, 6}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j].first << " " << adj_list[i][j].second << " ";
        }
        cout << "\n";
    }
}
void AdjPair()
{
    vector<vector<int>> adj(4);
    adj[0] = {2, 3};
    adj[1] = {1, 1, 2, 2};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
    }
}
void AdjList()
{
    vector<int> adj_list[4];
    adj_list[0] = {1};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};

    for (int i = 0; i < 4; i++) {
        cout << i << "->";
        for (int j = 0; j < adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";
            
        cout << "\n";
    }
}
int main() {
    printPair();
    AdjList();
    AdjPair();
    return 0;
}
