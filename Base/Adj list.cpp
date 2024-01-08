#include <bits/stdc++.h>
using namespace std;

void printPairs() {
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

int main() {
    // printPairs();
    vector<int> adj_list[4];

    adj_list[0] = {1};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};

    for (int i = 0; i < 4; i++) {
        cout << i << "->";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


