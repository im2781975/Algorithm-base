#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> Parent;

    DisjointSet(int n) {
        // Initialize the parent array with indices
        for (int i = 0; i < n; ++i) {
            Parent.push_back(i);
        }
    }

    int Find(int i) {
        // Find the representative of the set to which i belongs
        if (Parent[i] == i)
            return i;
        return Find(Parent[i]);
    }

    void Union(int i, int j) {
        // Find the representatives for the sets containing i and j
        int irep = Find(i);
        int jrep = Find(j);

        // Make the parent of i’s representative be j’s representative
        Parent[irep] = jrep;
    }
};

int main() {
    // Example usage
    int n = 5; // Number of elements
    DisjointSet ds(n);

    // Perform some unions
    ds.Union(0, 1);
    ds.Union(2, 3);
    ds.Union(0, 4);

    // Check if elements belong to the same set
    cout << "Are 1 and 4 in the same set? " << (ds.Find(1) == ds.Find(4) ? "Yes" : "No") << endl;
    cout << "Are 2 and 4 in the same set? " << (ds.Find(2) == ds.Find(4) ? "Yes" : "No") << endl;

    return 0;
}

