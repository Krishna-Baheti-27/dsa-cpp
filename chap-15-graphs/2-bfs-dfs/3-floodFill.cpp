#include<bits/stdc++.h>
using namespace std;

// now starting from image[sr][sc] we have to flood fill the image such that, we change its color to the new color given and the other adjacent (4 directionally) are having same initial color as image[sr][sc] are also colored to new color, and then repeat this for all adjacent that did get after updating and return updated image

/////////////////////////////////////////////////////////////////////////////////

// here we can do this using both bfs and dfs, dfs works here because we have not been told to flood fill in min amount of time or something like that, hence it does the job and updates all the neighbouring cells having same color as image[sr][sc] to color

void dfs(vector<vector<int>> &visited, int n, vector<vector<int>> &image, int m, int row, int col, int color, int initColor) {

    visited[row][col] = color; // do for this then check for neighbours

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    // checking for colors in 4 directions adjacent

    for(int i = 0; i < 4; i++) { 

        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == initColor && visited[nrow][ncol] != color) {

            // if it is valid and has same initial color and it has not been updated to new color then go ahead and color it

            dfs(visited, n, image, m, nrow, ncol, color, initColor);
        } 
    }
}

vector<vector<int>> floodFillDFS(vector<vector<int>> &image, int sr, int sc, int color) {

    int n = image.size(), m = image[0].size();

    vector<vector<int>> visited = image; // first copy everything since we dont want to tamper data

    dfs(visited, n, image, m, sr, sc, color, image[sr][sc]);

    return visited; // updated and flood filled matrix

} 
// O(nm) time to copy + O(nm * 4) since we are calling dfs for atmax n * m nodes in worst case and doing 4 * n * m work in there in worst case and hence O(5mn) time
// O(nm) space for visited array which is used to return answer so technically O(1) space, but our algorithm does use space which we can stop(by probably tampering the data)

/////////////////////////////////////////////////////////////////////////////

// Writing bfs solution just from conceptual clarity, both are optimal

vector<vector<int>> flooFillBFS(vector<vector<int>> &image, int sr, int sc, int color) {

    int n = image.size() , m = image[0].size();
    vector<vector<int>> ans = image; // work on copy of image to avoid tampering data
    queue<pair<int,int>> q; // only have to store (row, col)

    // initial config
    q.push({sr, sc}); // insert in queue
    ans[sr][sc] = color; // mark it visited

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};
    
    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == image[sr][sc] && ans[nrow][ncol] != color) {
                ans[nrow][ncol] = color; // mark as visited by coloring
                q.push({nrow, ncol}); // then push
            }
        }
    }

    return ans;

} // O(nm + 4nm) time and O(nm) space

int main() {
    
    return 0;
} 