//Grid Traversal
using namespace std;
int row, col;
const int n = 200;
int arr[n][n], level[n][n], visited[n][n];
int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
bool IsInside(pair <int, int> p){
    int x = p.first, y = p.second;
    if(x >= 0 && x < row && y >= 0 && y < col)
        return true;
    return false;
}
bool IsForbidden(pair<int, int> p){
    int x = p.first, y = p.second;
    if(arr[x][y] == -1)
        return true;
    return false;
}
void BFS(pair <int, int> src){
    queue <pair <int, int> >q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);
    while(!q.empty()){
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first, y = head.second;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            pair <int, int> adj = {newx, newy};
            if(IsInside(adj) && !IsForbidden(adj) && !visited[newx][newy]){
                visited[newx][newy] = 1;
                level[newx][newy] = level[x][y] + 1;
                q.push(adj);
            }
        }
    }
}
int main(){
    cin >> row >> col;
    pair <int, int> src, dst;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            level[i][j] = -1;
    }
    for(int i = 0; i < row; i++){
        string str; cin >> str;
        for(int j = 0; j < col; j++){
            if(str[j] == '#')
                arr[i][j] = -1;
            else if(str[j] == 'A')
                src = {i, j};
            else if(str[j] == 'B')
                dst = {i, j};
        }
    }
    BFS(src);
    (level[dst.first][dst.second] == -1)? cout << "No" : cout << "Yes " << level[dst.first][dst.second];
}
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


