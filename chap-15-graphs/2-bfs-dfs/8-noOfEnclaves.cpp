#include<bits/stdc++.h>
using namespace std;

// we have to find the number of enclaves or lands (having value = 1) from which you cannot go out of the boundary of grid, if land is on the boundary then you can definitely go out of the boundary but even if land is inside and there exists a 4 directional adjacent path to the boundary then also you can go 
// so now return the number of lands from which you cannot go out of the boundary

// this question is same as previous as there we had to mark all the zeroes or their adjacent on boundary which could not be converted to X and here we also have to find the 1's or land cells which are not connected to any boundary land cell as that will be our answer

// we will use bfs here to mark all the adjacent and the remaining umarked ones are those from which you cannot escape the grid
int numEnclaves(vector<vector<int>> &nums) {
    int n = nums.size(), m = nums[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // initially insert all the boundary ones into the queue and mark them as visited
    // later we will count all the ones and substract those from the ones which are safe, and the safe ones are those which were put in the queue atleast once
    int safeOnes = 0;
    queue<pair<int,int>> q; // to store row,col
    // insert only the boundary ones
    for(int j = 0; j < m; j++) {
        if(!visited[0][j] && nums[0][j] == 1) { // first row
            q.push({0, j});
            visited[0][j] = 1;
            safeOnes++;
        }
        if(!visited[n - 1][j] && nums[n - 1][j] == 1) { // last row
            q.push({n - 1, j});
            visited[n - 1][j] = 1;
            safeOnes++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i][0] && nums[i][0] == 1) { // first col
            q.push({i ,0});
            visited[i][0] = 1;
            safeOnes++;
        }
        if(!visited[i][m - 1] && nums[i][m - 1] == 1) { // last col
            q.push({i, m - 1});
            visited[i][m - 1] = 1;
            safeOnes++;
        }
    }
    // starting bfs traversal for queue
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && nums[nrow][ncol] == 1) {
                visited[nrow][ncol] = 1; 
                q.push({nrow, ncol}); // mark it as safe
                safeOnes++;
            }
        }
    }
    int totalOnes = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] == 1) totalOnes++;
        }
    }
    return totalOnes - safeOnes;
}

int main() {
    
    return 0;
}