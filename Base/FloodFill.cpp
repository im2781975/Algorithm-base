#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m || 
        image[row][col] != oldColor || image[row][col] == newColor)
        return;
    
    // Change color
    image[row][col] = newColor;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        dfs(row + dr[i], col + dc[i], image, newColor, oldColor, n, m);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    /* int x = 1, y = 1, newC = 3;
    vector <vector <int>> res = floodFill(image, x, y, newC); */
    int n = image.size(), m = image[0].size();
    int oldColor = image[sr][sc];
    
    if (oldColor != newColor)
        dfs(sr, sc, image, newColor, oldColor, n, m);
    return image;
}
