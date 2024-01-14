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
void listPair()
{
    int node=4;
    vector<pair<int,int>>adj_list[node];
    
    adj_list[0] = {{1,2}};
    adj_list[1] = {{2,4}};
    adj_list[2] = {{2,8}};
    adj_list[3] = {{1,7},{9,4}};
    
    adj_list[0].push_back ({1,2});
    adj_list[1].push_back ({2,4});
    adj_list[2].push_back ({2,8});
    adj_list[3].push_back ({1,7});
    adj_list[3].push_back ({9,4});
    
    for(int i=0;i<node;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adj_list[i].size();j++)
        {
            cout<<"["<<adj_list[i][j].first<<"] ["<<adj_list[i][j].second<<"]";
        }
        cout<<"\n";
    }
}
int main() {
    printPair();
    AdjList();
    AdjPair();
    listPair();
    return 0;
}
