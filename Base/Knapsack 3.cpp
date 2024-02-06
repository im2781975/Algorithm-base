// coin count
#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& val, int size, int weight) {
    if (weight == 0 || size == 0)
        return 0;
    if (val[size - 1] <= weight)
        return max(val[size - 1] + maxSum(val, size, weight - val[size - 1]), maxSum(val, size - 1, weight));
    else
        return maxSum(val, size - 1, weight);
}
int main() {
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << maxSum(val, n, n);
    return 0;
}


