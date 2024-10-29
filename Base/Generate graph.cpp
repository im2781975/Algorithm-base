//generate a graph for a given fixed degrees
using namespace std;
// Function to validate if the degree sequence can represent a simple undirected graph.
bool Isvalid(const int Deg[], int n){
    int DegreeSum = 0;
    for(int i = 0; i < n; i++){
        if(Deg[i] < 0 || Deg[i] >= n)
            return false;
        DegreeSum += Deg[i];
    }
    return DegreeSum % 2 == 0;
}
void print(int DegSeq[], int n){
    int mat[n][n] = {0};
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(DegSeq[i] > 0 && DegSeq[j]){
                DegSeq[i]--; DegSeq[j];
                mat[i][j] = 1; mat[j][i] = 1;
            }
        }
    }
    //setw controls the width for alignment, making the output more structured.
    cout << "\n" << setw(3) << "     ";
    for (int i = 0; i < n; i++)
        cout << setw(3) << "(" << i << ")";
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << "(" << i << ")";
        for (int j = 0; j < n; j++)
            cout << setw(5) << mat[i][j];
        cout << "\n\n";
    }
    cout << "\n";
}
int main(){
    int DegSeq[]{2, 2, 1, 1, 1};
    int n = sizeof(DegSeq)/sizeof(DegSeq[0]);
    if(Isvalid(DegSeq, n))
        print(DegSeq, n);
    else
        cout << "The degree sequence is invalid for generating a simple undirected graph.\n";
}


