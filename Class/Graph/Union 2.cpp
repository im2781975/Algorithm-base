#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, Size;

    DisjointSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);  // Initialize each element as its own parent
        Size.assign(n, 1);  // Initially, each set has size 1
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);  // Path compression
        return parent[i];
    }

    void unionBySize(int i, int j) {
        int irep = find(i);
        int jrep = find(j);

        if (irep == jrep)
            return;

        if (Size[irep] < Size[jrep]) {
            parent[irep] = jrep;
            Size[jrep] += Size[irep];
        } else {
            parent[jrep] = irep;
            Size[irep] += Size[jrep];
        }
    }
};

int main() {
    int n = 10;  // Number of elements
    DisjointSet ds(n);

    ds.unionBySize(1, 2);
    ds.unionBySize(3, 4);
    ds.unionBySize(1, 4);

    // Now, elements 1, 2, 3, and 4 are in the same set
    return 0;
}

