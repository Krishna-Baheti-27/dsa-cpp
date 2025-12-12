#include<bits/stdc++.h>
using namespace std;

// this is for finding nearest 1, not nearest 0, and then return the matrix having distances of nearest 1

/////////////////////////////////////////////////////////////////////////////////

// here the bfs algo will be applied because its clear that we want to calculate the distance or go level by level, first at level 0, then at level 1 and so on

// here dfs cant be applied for simple reason that DFS will always go to all the depth starting from 1, but rather what we want is starting from 1, reach all zeroes at distance = 1, then all those 0's will have the min distance 1 at 1 diatance

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

    int n = mat.size(), m = mat[0].size();

    queue<pair<pair<int,int>,int>> q; // queue for bfs {{row, col}, dis}
    vector<vector<bool>> visited(n ,vector<bool>(m, false)); //  visited matrix

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                visited[i][j] = true; // mark initial ones as visited
                q.push({{i,j}, 0}); // push in the queue all ones and their distance 0
            }
        }
    }

    vector<vector<int>> distance(n, vector<int>(m, 0)); // this is our answer matrix

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    // we start the traversal of queue

    // this is what we call multisource bfs as there are multiple starting points or sources for our traversal and we have to do bfs for all of those sources obeying certain contraints

    while(!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int distanceOfNearestOne = q.front().second;

        q.pop();

        distance[row][col] = distanceOfNearestOne; // put in our answer what we stored

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // we are guranteed that mat[nrow][ncol] wont be 1 since we dealt with that initially by putting in the queue so here we only check if index is valid and not visisted before

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {
                q.push({{nrow, ncol}, distanceOfNearestOne + 1}); // push in queue
                visited[nrow][ncol] = true; // mark as visited
            }
        }

    }

    return distance;

} // O(mn + mn * 4) time and O(2mn) space for queue + visited (not considering space to return ans)

////////////////////////////////////////////////////////////////////////////////////

// for finding nearest 0

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

    int n = mat.size(), m = mat[0].size();

    queue<pair<pair<int,int>,int>> q; // queue for bfs, {{row,col}, dis}
    vector<vector<bool>> visited(n ,vector<bool>(m, false)); //  visited matrix

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                visited[i][j] = true; // mark initial zeroes as visited
                q.push({{i,j}, 0}); // push in the queue
            } 
        }
    }

    vector<vector<int>> distance(n, vector<int>(m, 0)); // this is our answer matrix

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    // we start the traversal of queue

    while(!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int distanceOfNearestOne = q.front().second;

        q.pop();

        distance[row][col] = distanceOfNearestOne; // put in our answer

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {
                q.push({{nrow, ncol}, distanceOfNearestOne + 1});
                visited[nrow][ncol] = true;
            }
        }
    }

    return distance;

} // O(nm + nm * 4) time + O(nm + nm) space // for queue and visted


int main() {
    
    return 0;
}