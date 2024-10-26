#include<cstring>
#include<iostream>
using namespace std;
const int M = 3, N = 3;
string dic[]{ "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dic) / sizeof(dic[0]);
// A given function to check if a given string is present in dictionary
bool IsWord(string &str){
    for(int i = 0; i < n; i++){
        if(str.compare(dic[i]) == 0)
            return true;
    }
    return false;
}
void FindWords(char Boggle[M][N], bool visited[M][N], int i, int j, string str){
    visited[i][j] = true;
    str += Boggle[i][j];
    if(IsWord(str))
        cout << str << " ";
    // Traverse 8 adjacent cells of boggle[i][j]
    for(int row = i - 1; row <= i + 1 && row < M; ++row){
        for(int col = j - 1; col <= j + 1 && col < N; ++col){
            if(row >= 0 && col >= 0 &&! visited[row][col])
                FindWords(Boggle, visited, row, col, str);
        }
    }
    // Erase current character from string and mark visited of current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}
int main(){
    char Boggle[M][N] = {
        {'G','I','Z'},{'U','E','K'}, {'Q','S','E' } };
    bool visited[M][N] = { {false} };
    //Consider every character and look for all words starting with this character
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            string str = "";
            FindWords(Boggle, visited, i, j, str);
        }
    }
}
