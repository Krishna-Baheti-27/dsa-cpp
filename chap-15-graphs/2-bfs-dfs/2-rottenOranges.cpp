#include<bits/stdc++.h>
using namespace std;

// we are given a matrix of n x m dimension where n is number of rows and m is number of columns in each row
// if the cell is empty then grid[i][j] = 0, if the cell has fresh orange then grid[i][j] = 1 and if the cell has rotten orange then grid[i][j] = 2

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. so we have to check for top bottom left right, and in each minute the rotten orange will make the 4 directionally adjacent oranges rotten in one minute

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

////////////////////////////////////////////////////////////////////////////////

// so we will use BFS since a lot of oranges will be rottened simultaneously if they are at same level and only BFS  allows us to go distance by distance, and we have to do it in minTime basically rot the oranges simultaneously (for min time) and we cannot achieve that using dfs since it goes to depth of each node, and that would probably take more time than bfs

int orangesRotting(vector<vector<int>> &grid) {

    int n = grid.size(), m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<pair<int,int>,int>> q; // q will store ((row, col), time)

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j}, 0});
                visited[i][j] = true; // mark it as rottened
            } else {
                visited[i][j] = false; // if empty or fresh then dont mark it as rottened
            }
        }
    }

    // so we have set the initial config of the queue having all the rotten oranges inserted and they have been marked as visited as well

    // Now its time for bfs

    int maxTime = INT_MIN;

    // we will use this for travelling in 4 directions for adjacent cells
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        q.pop();

        maxTime = max(maxTime, time);

        for(int i = 0; i < 4; i++) { 

            int nrow = row + drow[i]; // neighbouring row to traverse
            int ncol = col + dcol[i]; // neighbouring column to traverse

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != true && grid[nrow][ncol] == 1) {

                // if the indices are valid and they are not rottened or visited before and you are a fresh guy then
                q.push({{nrow, ncol}, time + 1}); // level + 1 since we moved to new level
                visited[nrow][ncol] = true; // mark them as visited
            }
        }
    }

    // check if every fresh orange was rottened or not, because if not then return -1, here make sure to check only for fresh using grid[i][j] because empty cells we marked as false in visited and they should remain false but if any fresh ones are left as false then its wrong

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && visited[i][j] == false) return -1;
        }
    }

    // more elegantly you can check using, when initially traversing the grid, keep track of countfresh, and when you rotten a fresh orange decrease  countfresh by 1, in the end if countfresh == 0 then you have rottened everybody and return maxTime else -1
    // helps save last traversal of O(mn)

    return maxTime == INT_MIN ? 0 : maxTime;

} // O(2nm) space for visited and queue and O(nm + 4*mn) time

/////////////////////////////////////////////////////////////////

// WHY USE BFS INSTEAD OF DFS :

// This problem is a multi-source shortest path problem. We need to find the shortest time from any initial rotten orange to every fresh orange.

// BFS is the standard algorithm for finding the shortest path in an unweighted graph. It naturally finds the minimum time.

// DFS is used for tasks like finding connectivity, cycles, or just exploring all nodes. It finds a path, not necessarily the shortest one. Using it here is like trying to measure the width of a river with a stopwatch—it's the wrong tool for the job.

// If we are asked to return whether if its possible or not to rotten all oranges then DFS is works there, since probelm changed from shortest path to connectivity, if there is a path from rotten to fresh (a fresh should not be surrounded by empty cell on all 4 directions)

int main() {
    
    return 0;
}