#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> Parent;
    vector<int> Rank;

    UnionFind(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);

        // Initialize each element as a separate set with itself as the parent
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
    }

    int find(int i) {
        if (Parent[i] != i) {
            // Path compression: Set the parent to the representative
            Parent[i] = find(Parent[i]);
        }
        return Parent[i];
    }

    void unionbyrank(int i, int j) {
        int irep = find(i);
        int jrep = find(j);

        if (irep == jrep)
            return;

        int irank = Rank[irep];
        int jrank = Rank[jrep];

        if (irank < jrank) {
            Parent[irep] = jrep;
        } else if (jrank < irank) {
            Parent[jrep] = irep;
        } else {
            Parent[irep] = jrep;
            Rank[jrep]++;
        }
    }
};

int main() {
    // Example usage
    int n = 10; // Set size
    UnionFind uf(n);

    // Union operations
    uf.unionbyrank(0, 1);
    uf.unionbyrank(2, 3);
    uf.unionbyrank(4, 5);
    uf.unionbyrank(1, 5);

    // Find operations
    cout << "Parent of 0: " << uf.find(0) << endl; // Output should be the representative of the set containing 0
    cout << "Parent of 3: " << uf.find(3) << endl; // Output should be the representative of the set containing 3

    return 0;
}

