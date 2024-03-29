// find out whether a given graph is Bipartite or not.
#include <iostream>
using namespace std;
#define V 4
bool colorGraph(int G[][V],int color[],int pos, int c){
     
    if(color[pos] != -1 && color[pos] !=c)
        return false;
    // color this pos as c and all its neighbours and 1-c
    color[pos] = c;
    bool ans = true;
    for(int i=0;i<V;i++){
        if(G[pos][i]){
            if(color[i] == -1)
                ans &= colorGraph(G,color,i,1-c);
                 
            if(color[i] !=-1 && color[i] != 1-c)
                return false;
        }
        if (!ans)
            return false;
    }
    return true;
}
bool isBipartite(int G[][V]){
    int color[V];
    for(int i=0;i<V;i++)
        color[i] = -1;
    //start is vertex 0;
    int pos = 0;
    // two colors 1 and 0
    return colorGraph(G,color,pos,1);
}
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
 
    isBipartite(G) ? cout<< "Yes" : cout << "No";
    return 0;
} 
