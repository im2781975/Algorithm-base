#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node=2;
    int matrix[node][node] ={};
    
    matrix[0][1]=1;
    matrix[1][0]=1;
    matrix[1][1]=1;
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }
}
