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
// Function that returns true if the given pixel is valid
bool isValid(int screen[][8], int m, int n, int x, int y,
             int prevC, int newC)
{
    if (x < 0 || x >= m || y < 0 || y >= n
        || screen[x][y] != prevC || screen[x][y] == newC)
        return false;
    return true;
}
void floodFill(int screen[][8], int x, int y, int prevC, int newC) {
   /* int m = screen.size(), n = screen[0].size();
    int x = 4, y = 4;
    int prevC = screen[x][y];
    // New color that has to be filled
    int newC = 3;
    floodFill(screen, m, n, x, y, prevC, newC); */
    queue<pair<int, int> > queue;
    pair<int, int> p(x, y);
    queue.push(p);
    // Color the pixel with the new color
    screen[x][y] = newC;
    while (queue.size() > 0) {
        pair<int, int> currPixel = queue.front();
        queue.pop();
 
        int posX = currPixel.first;
        int posY = currPixel.second;
        if (isValid(screen, m, n, posX + 1, posY, prevC,
                    newC)) {
            screen[posX + 1][posY] = newC;
            p.first = posX + 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX - 1, posY, prevC,
                    newC)) {
            screen[posX - 1][posY] = newC;
            p.first = posX - 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX, posY + 1, prevC,
                    newC)) {
            screen[posX][posY + 1] = newC;
            p.first = posX;
            p.second = posY + 1;
            queue.push(p);
        }
 
        if (isValid(screen, m, n, posX, posY - 1, prevC,
                    newC)) {
            screen[posX][posY - 1] = newC;
            p.first = posX;
            p.second = posY - 1;
            queue.push(p);
        }
    }
}
