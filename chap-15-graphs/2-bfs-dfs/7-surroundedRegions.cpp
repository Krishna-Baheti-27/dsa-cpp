#include<bits/stdc++.h>
using namespace std;

// we have to convert the region of the O's into X's which are surrounded by X in all four directions
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

// so our observations are : we start with boundary O's and form a region of connected O's and mark them that they will not converted, rest will be converted to X

void dfsHelper(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board,int n, int m) {
    visited[row][col] = 1;
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
            dfsHelper(nrow, ncol, visited, board, n ,m);
        }
    }
}

void solve(vector<vector<char>> &board) {
    // we have to do it inplace dont return anything
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited(n ,vector<int>(m, 0));
    // traverse first row and last row
    for(int j = 0; j < m; j++) {
        if(!visited[0][j] && board[0][j] == 'O') {
            dfsHelper(0, j, visited, board, n, m);
        }
        if(!visited[n - 1][j] && board[n - 1][j] == 'O') {
            dfsHelper(n - 1, j, visited, board, n, m);
        }
    }
    // traverse the first and last column
    for(int i = 0; i < n; i++) {
        if(!visited[i][0] && board[i][0] == 'O') {
            dfsHelper(i, 0, visited, board, n , m);
        }
        if(!visited[i][m - 1] && board[i][m - 1] == 'O') {
            dfsHelper(i , m - 1, visited, board, n , m);
        }
    }
    // check and replace the O's with X's which are not marked as visited
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
        }
    }
}

int main() {
    
    return 0;
}