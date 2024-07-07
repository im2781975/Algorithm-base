#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;
bool IsPalindrome(string str){
    deque <char> dq;
    for(char c :str){
        if(isalnum(c))
        //isalnum ->is alpha numeri 
            dq.push_back(tolower(c));
    }
    while(dq.size() > 1){
        if(dq.front()!=dq.back())
            return false;
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}
int main(){
    string str;
    while(cin >> str){
        if(IsPalindrome(str))
            cout << "Yes";
        else
            cout << "No";
    }
}
