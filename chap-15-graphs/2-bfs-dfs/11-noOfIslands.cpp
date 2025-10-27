#include<bits/stdc++.h>
using namespace std;

// we are given a grid of size n * m where consisting of 0 and 1 where 0 means water and 1 means land cell, we have to find the number of islands
// we have to find number of islands, an island is formed by connnecting adjacent lands (8 directional) and is surrounded by water from all 8 directions

// this is different from number of enclaves where we were finding safe path by marking all safe starting from boundary, here we want to calculate all such islands and not only safe ones connected to boundary and more thing to note is that here we are ok if island is not covered by 0's in all 8 directions but it should be covered whereever the indices are valid 

////////////////////////////////////////////////////////////////////////////////

// this is questions is very similar to what we did in 1st questions that is number of provinces, here we have to find the number of islands or number of group of ones surrounded by water on all 8 sides (whereever possible) so the number of islands would be number of dfs calls made, thats it

void dfsHelper(int row, int n, int col, int m, vector<vector<bool>> &visited, vector<vector<int>> &grid) {

    visited[row][col] = true;

    int drow[] = {-1,-1,-1,0,0,+1,+1,+1};
    int dcol[] = {-1,0,+1,-1,+1,-1,0,+1};
    
    for(int i = 0; i < 8; i++) {

        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfsHelper(nrow, n, ncol, m, visited, grid);
        }
    }
}

int numIslands(vector<vector<int>> &grid) {

    int n = grid.size(), m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int countIslands = 0;

    // here we traverse entire grid instead of just boundary like in number of enclaves

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                countIslands++;
                dfsHelper(i, n, j, m, visited, grid);
            }
        }
    }

    return countIslands;
}

///////////////////////////////////////////////////////////////////////////////

// it can also be done using BFS its just that DFS is more intuitive here

int main() {
    
    return 0;
}