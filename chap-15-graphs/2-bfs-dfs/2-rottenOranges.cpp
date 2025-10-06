#include<bits/stdc++.h>
using namespace std;

// we are given a matrix of n x m dimension where n is number of rows and m is number of columns in each row
// if the cell is empty then grid[i][j] = 0, if the cell has fresh orange then grid[i][j] = 1 and if the cell has rotten orange then grid[i][j] = 2

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. so we have to check for top bottom left right, and in each minute the rotten orange will make the 4 directionally adjacent oranges rotten in one minute

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// so we will use BFS since a lot of oranges will be rottened simultaneously if they are at same level and only BFS  allows us to go distance by distance, and we have to do it in minTime basically rot the oranges simultaneously (for min time) and we can achieve that using dfs since it goes to depth of each node, and that would probably take more time

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));
    queue<pair<pair<int,int>,int>> q; // q will store ((row, col), time)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j}, 0});
                visited[i][j] = 2;
            } else {
                visited[i][j] = 0; // if empty
            }
        }
    }
    // so we have set the initial config of the queue
    // Now its time for bfs
    int maxTime = INT_MIN;
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        maxTime = max(maxTime, time);
        for(int i = 0; i < 4; i++) { 
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                // if the indices are valid and they are not rottened or visited before and you are a fresh guy then
                q.push({{nrow, ncol}, time + 1});
                visited[nrow][ncol] = 2; // mark them as visited
            }
        }
    }
    // check if every fresh orange was rottened or not, because if not then return -1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && visited[i][j] != 2) return -1;
        }
    }
    // more elegantly you can check using, when initially traversing the grid, keep track of countfresh, and when you rotten a fresh orange decrease  countfresh by 1, in the end if countfresh == 0 then you have rottened everybody and return maxTime else -1
    // helps save last traversal of O(mn)
    return maxTime;
} // O(2nm) space for visited and queue and O(nm + 4*mn) time

int main() {
    
    return 0;
}