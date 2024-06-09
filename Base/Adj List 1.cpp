#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> vec[5];
    vec[1].push_back(2);
    vec[1].push_back(3);
    vec[1].push_back(4);
    for(int i = 0; i < vec[1].size(); i++)
        cout << vec[1][i] << " ";
}
