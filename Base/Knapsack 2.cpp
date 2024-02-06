// A iron rod was cut into pieces.each pieces have some values.what is the maximum value.
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>&wt, vector<int>&val, int size, int weight)
{
    if(weight==0 || size==0)
        return 0;
    if(wt[size-1] <=weight)
        return max(val[size - 1]+ maxSum(wt, val, size,  weight- wt[size-1]), maxSum(wt, val, size -1, weight));
    else
        return maxSum(wt, val, size -1, weight);
}
int main()
{
    int n ;
    cin >> n ;
    vector<int>wt(n), val(n);
    for(int i=0; i<n; i++)
    {
        wt[i] = i + 1;
        cin >> val[i];
    }
    cout << maxSum(wt, val, n, n);
}
