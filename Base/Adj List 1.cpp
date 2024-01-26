#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v[5];
    v[1].push_back(1);
    v[1].push_back(2);
    v[1].push_back(3);
    for(int i=0; i<v[1].size(); i++)
        cout << v[1][i] << " ";
}
