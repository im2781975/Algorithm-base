#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
// Minimum number of steps required two make strings same
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans=1;
    int LCS=dp[n][m];
    int ans = (n + m) - (LCS*2);
    cout << ans;
    return 0;
}

