// count number of sink nodes
#include<bits/stdc++.h>
using namespace std;
// sink node is a node with no outgoing edges.
int countSink(int n, int e, int edgeFrom[], int edgeTo[])
{
    // Array for marking the non-sink node.
    int mark[n];
    //initialize mark array as 0;
    memset(mark, 0, sizeof mark);
    // Marking the non-sink node.
    for (int i = 0; i < e; i++)
        mark[edgeFrom[i]] = 1;
    // Counting the sink nodes.
    int count = 0;
    for (int i = 1; i <= n ; i++)
        if (!mark[i])
            count++;
    return count;
}
int main()
{
    int n = 4, e = 2;
    int edgeFrom[] = { 2, 4 };
    int edgeTo[] = { 3, 3 };
    cout << countSink(n, e, edgeFrom, edgeTo) << endl;
    return 0;
}
