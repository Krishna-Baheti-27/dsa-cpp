#include<bits/stdc++.h>
using namespace std;

// here the bfs algo will be applied because its clear that we want to calculate the distance or go level by level, first at level 0, then at level 1 and so on

// this is for finding nearest 1, not nearest 0
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    queue<pair<pair<int,int>,int>> q; // queue for bfs
    // intialise visited matrix
    vector<vector<int>> visited(n ,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                visited[i][j] = 1; // mark initial ones as visited
                q.push({{i,j}, 0}); // push in the queue
            } else {
                visited[i][j] = 0; // mark rest as unvisited
            }
        }
    }
    vector<vector<int>> distance(n, vector<int>(m)); // this is our answer matrix

    // we start the traversal of queue
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int distanceOfNearestOne = q.front().second;
        distance[row][col] = distanceOfNearestOne; // put in our answer
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {
                q.push({{nrow, ncol}, distanceOfNearestOne + 1});
                visited[nrow][ncol] = 1;
                // we are guranteed that mat[nrow][ncol] wont be 1 since we dealt with that initially by putting in the queue
            }
        }
    }
    return distance;
}

// for finding nearest 0
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    queue<pair<pair<int,int>,int>> q; // queue for bfs
    // intialise visited matrix
    vector<vector<int>> visited(n ,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                visited[i][j] = 1; // mark initial zeroes as visited
                q.push({{i,j}, 0}); // push in the queue
            } else {
                visited[i][j] = 0; // mark rest as unvisited
            }
        }
    }
    vector<vector<int>> distance(n, vector<int>(m)); // this is our answer matrix

    // we start the traversal of queue
    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

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
                visited[nrow][ncol] = 1;
                // we are guranteed that mat[nrow][ncol] wont be 0 since we dealt with that initially by putting in the queue
            }
        }
    }
    return distance;
} // O(nm + nm + nm * 4) time + O(nm + nm + nm) space // for queue visted and distance

int main() {
    
    return 0;
}