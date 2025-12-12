#include<bits/stdc++.h>
using namespace std;

// we have to convert the region of the O's into X's which are surrounded by X in all four directions
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

////////////////////////////////////////////////////////////////////////

// so our observations are : we start with boundary O's and form a region of connected O's and mark them that they will not converted, rest will be converted to X, since those will be the O's which were not connected directly to any of the boundary O's

// here both dfs and bfs will works but dfs is more intuitive

void dfsHelper(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &board,int n, int m) {

    visited[row][col] = true;

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

// we have to do it inplace dont return anything

void solveDFS(vector<vector<char>> &board) {
    
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n ,vector<bool>(m, false));

    // we have to traverse all boundary O's and from there mark all O's in depth

    // so this is problem of multisource dfs

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

    // check and replace the O's with X's which are not marked as visited as they were not connected to any of the boundary O's and they were surrounded by X so they will be converted

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'O' && !visited[i][j]) {
                board[i][j] = 'X';
            }
        }
    }

    // successfully updates the matrix in place
}
// O(mn + 4 * mn + mn) time in worst case and O(mn) space for visited

/////////////////////////////////////////////////////////////////////////////

// this can also be solved using BFS

void solveBFS(vector<vector<char>> &board) {

    int n = board.size(), m = board[0].size();

    queue<pair<int,int>> q; // queue for bfs storing (row, col)
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // in the intial config put all the O's on boundary inside the queue and mark them visited

    // so this is problem of multisource bfs
    
    // for first and last row

    for(int j = 0; j < m; j++) {

        if(!visited[0][j] && board[0][j] == 'O') {
            q.push({0, j});
            visited[0][j] = true;
        }

        if(!visited[n - 1][j] && board[n - 1][j] == 'O') {
            q.push({n - 1, j});
            visited[n - 1][j] = true;
        }
    }

    // for first column and last column (ignoring first and last row since already touched)

    for(int i = 1; i < n - 1; i++) {

        if(!visited[i][0] && board[i][0] == 'O') {
            q.push({i, 0});
            visited[i][0] = true;
        }

        if(!visited[i][m - 1] && board[i][m - 1] == 'O') {
            q.push({i, m - 1});
            visited[i][m - 1] = true;
        }
    }

    // now we start traversal of the queue

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                q.push({nrow, ncol});
                visited[nrow][ncol] = true;
            }
        }
    }

    // now all nodes which are not marked as visited and are 'O' will be converted to 'X'

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'O' && !visited[i][j]) {
                board[i][j] = 'X';
            }
        }
    }

} // O(m + n + 4 * mn + mn) time and O(2mn) for queue and visited

int main() {
    
    return 0;
}