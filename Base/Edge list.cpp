#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edge_list(4); // Initialize a vector of 4 empty vectors

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

