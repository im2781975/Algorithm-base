#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int solve(int n, int m, vector<vector<char>>& grid, vector<vector<ll>>& dp) {
    if (n < 0 || m < 0 || grid[n][m] == '#') {
        return 0;
    }
    if (n == 0 && m == 0) {
        return 1;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    int ans = 0;
    if (n > 0) {
        ans += solve(n - 1, m, grid, dp);
    }
    if (m > 0) {
        ans += solve(n, m - 1, grid, dp);
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, -1));

    cout << solve(n - 1, m - 1, grid, dp) << endl;
    return 0;
}

