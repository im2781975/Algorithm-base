#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, int M, int N, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (dp[x][y] != -1)
        return dp[x][y];
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        
        if (X < 0 || X >= N || Y < 0 || Y >= M)
            continue;
        if (mat[x][y] >= mat[X][Y])
            continue;
        ans = max(ans, 1 + dfs(X, Y, M, N, mat, dp));
    }
    return dp[x][y] = ans;
}

int LongestIncrPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0; 
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j, m, n, matrix, dp));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Length of the longest increasing path: " << LongestIncrPath(matrix) << endl;
    return 0;
}

