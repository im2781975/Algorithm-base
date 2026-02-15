// check if a queue of first n natural number can be sorted using a stack
#include<bits/stdc++.h>
using namespace std;
bool CheckSorted(int n, queue <int> &q){
    stack <int> st;
    int expect = 1;
    int first;
    while(!q.empty()){
        first = q.front();
        q.pop();
        if(first == expect)
            expect++;
        else {
            if(st.empty())
                st.push(first);
            // if top element is less than element which need to be pushed, then return false.
            else if(!st.empty() && st.top() < first)
                return false;
            else
                st.push(first);
        }
        //while expected element are coming from stack, pop them out
        while(!st.empty() && st.top() == expect){
            st.pop();
            expect++;
        }
    }
    // while expected element are coming from stack, pop them out.
    if(expect - 1 == n && st.empty())
        return true;
    return false;
}
int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n = q.size();
    (CheckSorted(n, q) ? (cout << "Yes") :(cout << "No"));
}
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
#include<bits/stdc++.h>
using namespace std;
void print(queue <int> &q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
void reverse(queue <int> &q){
    if(q.size() == 0)
        return;
    int first = q.front();
    q.pop();
    reverse(q);
    q.push(first);
}
void Reverse(queue <int> &q){
    stack <int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
};
// reverse first k elements of a queue.
void ReverseFirst(int k, queue <int> &q){
    if(q.empty() || k > q.size())
        return;
    if(k <= 0)
        return;
    stack <int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 0; i < q.size() - k; i++){
        q.push(q.front());
        q.pop();
    }
}
// Function to reverse first k elements of a queue
void solve(queue <int> q, int k){
    if(k == 0)
        return;
    int first = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(first);
}
queue <int> ReverseFirst(queue <int> q, int k){
    solve(q, k);
    int size = q.size() - k;
    while(size-- > 0){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
int main(){
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    reverse(q);
    Reverse(q);
    print(q);
    //
    queue <int> q;
    for(int i = 10; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    ReverseFirst(k, q);
    print(q);
    //
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    // Need to store the value in a queue
    q = ReverseFirst(q, k);
    print(q);
}
#include<iostream>
#include<stack>
using namespace std;
// Function to check if brackets are balanced
bool IsBalanced(string str){
    stack <char> st;
    for(int i = 0; i < str.length(); i++){
        if(st.empty())
            st.push(str[i]);
        else{
            if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']'))
                st.pop();
            else{
                st.push(str[i]);
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}
bool IsBalanced(string str){
    int i = -1;
    for(auto &ch : str){
        if(ch == '(' || ch == '{'|| ch == '[')
            str[++i] = ch;
        else{
            if(i >= 0 && ((str[i] == '(' && ch == ')') || (str[i] == '{' && ch == '}') || (str[i]== '[' && ch == ']')))
                return true;
            return false;
        }
    }
    //If i is -1, it means all opening brackets have been matched with 
    //closing brackets, and the brackets are balanced. The function returns true.
    return i == -1;
}
int main(){
    string str = "{()}[]";
    (IsBalanced(str)) ?cout << "Yes":
    cout << "No";
}
#include<iostream>
#include<stack>
using namespace std;
bool IsOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return true;
    return false;
}
string PrefixToInfix(string str){
    stack <string> st;
    for(int i = str.size() -1; i >= 0; i--){
        if(IsOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            //concat the operands and operator
            string tmp = "(" + x + str[i] + y + ")";
            st.push(tmp);
        }
        else
            //Convert the character to a string and push it onto the stack.
             //first arg(1) specifies the number of times to copy the char.second arg (str[i]) is the character to be copied
            st.push(string(1, str[i]));
    }
    return st.top();
}
bool isOperand(char x){
    if((x >= 'a' && x <= 'z') || x >= 'A' && x <= 'Z')
        return true;
    return false;
}
string PostfixToInfix(string str){
    stack < string> st;
    for(int i = 0; str[i]; i++){
        if(isOperand(str[i]))
            // creates a string from the single character str[i] 
            //this string is then pushed onto the stack st
            st.push(string(1, str[i]));
        else{
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x + ")");
        }
    }
    return st.top();
}
int main(){
    string st = "*-A/BC-/AKL";
    cout << PrefixToInfix(st);
    
    string str ="ab*c+";
    cout << "\n" << PostfixToInfix(str);
}
#include<bits/stdc++.h>
using namespace std;
// Function to return precedence of operators
int prec(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
void InfixToPostfix(string str){
    stack <char> st;
    string result;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9'))
            result += ch;
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        // If an operator is scanned
        else{
            while(!st.empty() && prec(str[i]) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // Pop all the remaining elements from the stack
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result;
}
bool IsOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    return false;
}
string PrefixToPostfix(string str){
    stack < string> st;
    for(int i = str.size() -1; i >= 0; i--){
        if(IsOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            string tmp = x + y + str[i];
            st.push(tmp);
        }
        else
            st.push(string(1, str[i]));
    }
    return st.top();
}
int main(){
    string str ="a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(str);
    string str = "*-A/BC-/AKL";
    cout << PrefixToPostfix(str);
}
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}
string PostfixToPrefix(string str){
    stack <string> st;
    for(int i = 0; i < str.size(); i++){
        if(isOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            string tmp = str[i] + y + x;
            st.push(tmp);
        }
        else
            st.push(string(1, str[i]));
    }
    string ans = "";
    while(!st.empty()){
        ans+= st.top();
        st.pop();
    }
    return ans;
}
//***//
bool IsOperator(char ch){
    return (!isalpha(ch) && !isdigit(ch));
}
int prec(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}
string InfixToPostfix(string str) {
    stack<char> st;
    string final;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            final += str[i];
        } else if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                final += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        } else {
            while (!st.empty() && prec(st.top()) >= prec(str[i])) {
                final += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty()) {
        final += st.top();
        st.pop();
    }
    return final;
}
string InfixToPrefix(string str){
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
        string prefix = InfixToPostfix(str);
        reverse(prefix.begin(), prefix.end());
        return prefix;
}
int main(){
    string str ="ABC/-AK/L-*";
    cout << PostfixToPrefix(str);
    string st =("x+y*z/w+u");
    cout << "\n" << InfixToPrefix(st);
}
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}
string PostfixToPrefix(string str){
    stack <string> st;
    for(int i = 0; i < str.size(); i++){
        if(isOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            string tmp = str[i] + y + x;
            st.push(tmp);
        }
        else
            st.push(string(1, str[i]));
    }
    string ans = "";
    while(!st.empty()){
        ans+= st.top();
        st.pop();
    }
    return ans;
}
//***//
bool IsOperator(char ch){
    return (!isalpha(ch) && !isdigit(ch));
}
int prec(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}
string InfixToPostfix(string str) {
    stack<char> st;
    string final;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            final += str[i];
        } else if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                final += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        } else {
            while (!st.empty() && prec(st.top()) >= prec(str[i])) {
                final += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty()) {
        final += st.top();
        st.pop();
    }
    return final;
}
string InfixToPrefix(string str){
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
        string prefix = InfixToPostfix(str);
        reverse(prefix.begin(), prefix.end());
        return prefix;
}
int main(){
    string str ="ABC/-AK/L-*";
    cout << PostfixToPrefix(str);
    string st =("x+y*z/w+u");
    cout << "\n" << InfixToPrefix(st);
}
#include<iostream>
#include<stack>
using namespace std;
// evaluate value of a postfix expression having multiple digit operands
int EvalutePostfix(char *str){
    stack <int> st;
    int i;
    //in loop str[i] means str[i]!=NULL
    for(i = 0; str[i]; i++){
        if(str[i] == ' ')
            continue;
        // If the scanned character is an operand (number here)
        //extract the full number Push it to the stack.
        else if(isdigit(str[i])){
            int num = 0;
            while(isdigit(str[i])){
                num = num * 10 + (int)(str[i] - '0');
                i++;
            }
            //After the loop exits, i has been incremented one extra time 
            //(pointing to a non-digit character). i-- decrements the index back to the last digit character.
            i--;
            st.push(num);
        } else {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]){
                case '+':
                     st.push(x + y);
                     break;
                case '-':
                    st.push(y - x);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(y / x);
                    break;
            }
        }
    }
    return st.top();
}
// evaluate value of a postfix expression
int postfix(string str){
    stack<char>st;
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i]))
            st.push(str[i] - '0');
        else{
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]){
                case '+':
                    st.push(x + y);
                    break;
                case '-':
                    st.push(y - x);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(y / x);
                    break;
            }
        }
    }
    return st.top();
}
int main(){
    char str[] = "100 200 + 2 / 5 * 7 +";
    cout << EvalutePostfix(str);
    string st ="231*+9-";
    cout << postfix(st);
}
#include<iostream>
#include<stack>
using namespace std;
// Function to build Monotonic increasing stack
void Increasing(int *arr, int n){
    stack <int> st;
    for(int i = 0; i < n; i++){
        while(st.size() > 0 && st.top() > arr[i])
            st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int ans[sz], j = sz - 1;
    while(!st.empty()){
        ans[j] = st.top();
        st.pop(); j--;
    }
    cout << "\nArray is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nStack is: ";
    for(int i = 0; i < sz; i++)
        cout << ans[i] << " ";
}
void Decreasing(int *arr, int n){
    stack <int> st;
    for(int i = 0; i < n; i++){
        while(st.size() > 0 && st.top() < arr[i])
            st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int ans[sz], j = sz - 1;
    while(!st.empty()){
        ans[j] = st.top();
        st.pop(); j--;
    }
    cout << "\nArray is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nStack is: ";
    for(int i = 0; i < sz; i++)
        cout << ans[i] << " ";
}
int main(){
    int arr[]{1, 4, 5, 3, 12, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Increasing(arr, n);
    Decreasing(arr, n);
}
#include<iostream>
#include<stack>
using namespace std;
void InsertBottom(stack <int> &st, int x){
    if(st.size() == 0)
        st.push(x);
    else{
        int p = st.top();
        st.pop();
        InsertBottom(st, x);
        st.push(p);
    }
}
void Reverse(stack <int> &st){
    if(st.size() > 0){
        int x = st.top();
        st.pop();
        Reverse(st);
        InsertBottom(st, x);
    }
}
// reverse the number using a stack
stack <int> st;
void PushDigit(int num){
    while(num !=0){
        st.push(num % 10);
        num /= 10;
    }
}
int Reverse(int num){
    PushDigit(num);
    int rev = 0, i = 1;
    while(!st.empty()){
        rev = rev + (st.top() * i);
        st.pop();
        i *= 10;
    }
    return rev;
}
int main(){
    stack <int> a, b;
    for(int i = 1; i <= 4; i++)
        a.push(i);
    b = a;
    while(!b.empty()){
        cout << b.top() << " ";
        b.pop();
    }
    Reverse(a);
    cout << "\n";
    while(!a.empty()){
        cout << a.top() <<  " ";
        a.pop();
    }
    //****//
    int num; cin >> num;
    cout << Reverse(num);
}
// sort a stack using an auxiliary stack.
#include<iostream>
#include<stack>
using namespace std;
stack <int> SortStack(stack <int> st){
    stack <int> Stack;
    while(!st.empty()){
        int tmp = st.top();
        st.pop();
        while(!Stack.empty() && Stack.top() > tmp){
            st.push(Stack.top());
            Stack.pop();
        }
        Stack.push(tmp);
    }
    return Stack;
}
int main(){
    stack <int> st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(4);
    stack <int>Stack = SortStack(st);
    while(!Stack.empty()){
        cout << Stack.top() << " ";
        Stack.pop();
    }
    //BuildIn Stack
    stack <int> st;
    for(int i = 21; i <= 30; i++)
        st.push(i);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

