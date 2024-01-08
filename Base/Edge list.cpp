#include <bits/stdc++.h>
using namespace std;
void First()
{
vector<vector<int>> edge_list(4); 
    edge_list[0].push_back(0);
    edge_list[0].push_back(1);
    edge_list[1].push_back(1);
    edge_list[1].push_back(2);

    edge_list[2].push_back(1);
    edge_list[2].push_back(3);
    edge_list[3].push_back(2);
    edge_list[3].push_back(3);
    
    
    for (int i = 0; i < edge_list.size(); i++) {
        for (int j = 0; j < edge_list[i].size(); j++) {
            cout << edge_list[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    //First();
    vector <vector<int > >edge_list{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12},};
    edge_list.push_back({13, 14, 15});
    for(int i=0; i<edge_list.size(); i++)
    {
        cout<<edge_list[i][0] << " "<<edge_list[i][1] <<" " <<edge_list[i][2] <<"\n";
    }
}

