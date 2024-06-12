//Finds the representative of the set that i is an element of
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005; // Adjust the maximum number of elements as needed
int parent[MAXN];
int find(int i)
{
    // If i is the parent of itself
    if (parent[i] == i) {
        // Then i is the representative of this set
        return i;
    }
    else {
        // Else if i is not the parent of itself, then i is not the
        // representative of his set. So we recursively call Find on its parent
        return find(parent[i]);
    }
}
// Unites the set that includes i and the set that includes j
int main() {
    for (int i = 0; i < MAXN; ++i) {
        parent[i] = i;
    }
    // Example usage:
    // Assuming you have union operations, let's say you want to union elements 1 and 2
    int representative1 = find(1);
    int representative2 = find(2);
    // Check if they are in the same set before union
    if (representative1 != representative2) {
        // Perform the union operation by making one the parent of the other
        parent[representative1] = representative2;
    }

    // Now, you can use find function to get the representative of any element
    int elementToFind = 1;
    int representative = find(elementToFind);

    cout << "The representative of element " << elementToFind << " is: " << representative << endl;

    return 0;
}

