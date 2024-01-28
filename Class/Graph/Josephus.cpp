// find last man standing
#include <bits/stdc++.h>
using namespace std;
int josephusCircle(int n, int k){
    list<int>l;
    for(int i=0;i<n;i++)
        l.push_back(i);
      
    auto it = l.begin();  
    while(l.size()>1){
        for(int i=1;i<k;i++){
            it++;
             
            if(it==l.end()){
              //if iterator reaches the end,then we change it to begin of the list
                it = l.begin();
            }
        }
         it = l.erase(it);
          
         if(it==l.end()){
           //if iterator reaches the end,then we change it to begin of the list
                it = l.begin();
            }
    }
    return l.front();
}
int main()
{
   int n=14,k=2;
      cout<<josephusCircle(n,k)<<"\n";
    return 0;
}
