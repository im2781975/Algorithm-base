https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include<bits/stdc++.h>
using namespace std;
const int N = 25;
const int W = 105;
int dp[N][W];

int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(dp[size][weight]!=-1)
        return dp[size][weight];
    if(wt[size-1] <=weight)
      return dp[size][weight] = max(val[size - 1]+ maxSum(wt, val, size -1,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
       return dp[size][weight] = maxSum(wt, val, size -1, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int>wt, val;
    for(int i=1; i<=n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        wt.push_back(weight);
        val.push_back(value);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
            dp[i][j] = -1;
    }
    cout << maxSum(wt, val, n, w);
}
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(wt[size-1] <=weight)
        return max(val[size - 1]+ maxSum(wt, val, size -1,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
        return maxSum(wt, val, size -1, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int>wt, val;
    for(int i=1; i<=n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        wt.push_back(weight);
        val.push_back(value);
    }
    cout << maxSum(wt, val, n, w);
}
