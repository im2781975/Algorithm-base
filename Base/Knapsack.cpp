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
