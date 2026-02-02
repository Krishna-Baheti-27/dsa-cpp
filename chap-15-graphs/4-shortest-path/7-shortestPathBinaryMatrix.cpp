#include<bits/stdc++.h>
using namespace std;

// this is question is sort of similar to last question where we have to find the length of shortest path from source (0,0) to destination (n - 1, n - 1)

// but there are constraints like we can only move to 8 directionally adjacent cells at a time and all the cells in the path must be 0 in order to be called as a clear path

// the lenth of the clear path is the number of cells visited in this path

// we have to return the length of shortest amongst all such clear paths

// if no such path exists return -1

/////////////////////////////////////////////////////////////////////////////////

// so we have to explore all possible paths from source to node having all cells as 0 so we use the queue for bfs and not priority queue since we know that for the level 1, all nodes inserted would be of distance = 1, so priority queue will not be beneficial since we dont have any specific min distance path to take whereas in dijkstra we had different edge weights so did had the possibility of selecting min path

int shortestPath(vector<vector<int>> &grid) {

    int n = grid.size();

    // no clear path exists since source or destination themselves not 0

    if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return -1;
    }

    // since we already checked that grid[0][0] and grid[n-1][n-1] are not 1 and hence simply return 1 since 1 cell in thep path from source to destination

    if(n == 1) {
        return 1;
    }

    vector<vector<bool>> visited(n, vector<bool> (n, false));

    int drow[] = {-1,-1,-1,0,0,+1,+1,+1};
    int dcol[] = {-1,0,+1,-1,+1,-1,0,+1};

    queue<pair<int,pair<int,int>>> q;
    
    q.push({1, {0,0}}); // (dis, row, col)
    visited[0][0] = true;

    while(!q.empty()) {

        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;

        q.pop();

        for(int i = 0; i < 8; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // optimisation : return immediately if we found the target since bfs goes level by level and the first time we find the target is our answer

            if(nrow == n - 1 && ncol == n - 1) {
                return dis + 1;
            }

            // this works because we already checked in the beginning that grid[n-1][n-1] is not 1 and hence safely return the distance

            if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == false && grid[nrow][ncol] == 0) {

                q.push({dis + 1, {nrow, ncol}});
                visited[nrow][ncol] = true;
            }
        }
    }

    return -1;

} // O(n^2) time since in the worst case we will explore all the cells and O(n^2) space since we are using an extra visited array and queue

int main() {
    
    return 0;
}