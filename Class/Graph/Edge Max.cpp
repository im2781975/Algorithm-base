#include <iostream>
using namespace std;
int max_edges(int V, int E) 
{ 
      return V * (V - 1) / 2 - E; 
}
int main()
{
    int V, E;
    V = 6;
    E = 6;
    cout << "Maximum number of edges that can be added to maintain DAG is " << max_edges(V, E);
    return 0;
}
