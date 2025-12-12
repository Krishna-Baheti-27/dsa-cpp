#include<bits/stdc++.h>
using namespace std;

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell

/////////////////////////////////////////////////////////////////////////////////////

// here we cant apply dp since we cant optimise the state to be only two sided (only right or bottom movement) since we have four sided movement here and we cannot do that by a 4 dimensional array

int minEffortPathBrute(vector<vector<int>> &heights) {

    int n = heights.size();
    int m = heights[0].size();

    if(n == 1 && m == 1) {
        return 0;
    }

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    int minEffort = INT_MAX;

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

    queue<pair<int,int>> q;
    q.push({0, 0});
    effort[0][0] = 0;
    
    while(!q.empty()) {

        
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {

                int eff = max(effort[row][col], abs(heights[row][col] - heights[nrow][ncol]));

                if(eff < effort[nrow][ncol]) {
                    effort[nrow][ncol] = eff;
                    q.push({nrow, ncol});
                }

                if(nrow == n - 1 && ncol == m - 1) {
                    minEffort = min(minEffort, effort[nrow][ncol]);
                }
            }
        }
    }

    return minEffort;

} 

// In graph problems on a 2D Matrix (Grid), we treat every cell as a "Vertex" (Node) and every valid movement as an "Edge".

// hence V = n * m and E = 4 * n * m (since we can move for all vertices in 4 directions)

// O(VE) time since in the worst case we will have to calculate effort for nearly all V nodes and for each movement of E times
// O(V) space since we will store all the nodes in queue in worst case

// O((n * m) * (4 * n * m)) time and O(n * m) space according to n and m given in question

// since in worst case n = 100 and m = 100, we have approx 10^8 operations and might fail and hence its better to use priority queue

//////////////////////////////////////////////////////////////////////////////////

// so here in place of dijkstra we will use priority_queue and explore the min option first 
// Priority Queue (Dijkstra): Processes nodes based on lowest effort. It will pause exploring a "high effort" path to see if a "low effort" path (even if it takes more steps) turns out to be better.

// Rule of Thumb:
// Edge weights = 1? Use Queue (BFS).
// Edge weights vary? Use Priority Queue (Dijkstra).

int minEffortPathOptimal1(vector<vector<int>> &heights) {

    int n = heights.size();
    int m = heights[0].size();

    if(n == 1 && m == 1) {
        return 0;
    }

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

    pq.push({0, {0, 0}});
    effort[0][0] = 0;

    while(!pq.empty()) {

        int eff = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        pq.pop();

        // In Dijkstra (Priority Queue): We explore based on cost, not steps. You might "touch" the destination via a short but expensive path first. The long but cheap path is still sitting in your Priority Queue, waiting to be processed.

        // A node is only finalized when it is popped from the priority queue, not when it is pushed.

        // and hence we have this check at the time of popping and not pushing since if something is getting popped then that popped value is the final shortest path for that node

        if(row == n - 1 && col == m - 1) {
            return eff;
        }

        // since we already have a better answer we dont need to process this and it does happen in PQ that we have both optimal and suboptimal answer sitting in there and we process optimal first due to its min nature but then its also important to skip the suboptimal ones that appear after that (if any)

        if(eff > effort[row][col]) {
            continue;
        }

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {
                
                int newEff = max(eff, abs(heights[row][col] - heights[nrow][ncol]));

                if(newEff < effort[nrow][ncol]) {
                    effort[nrow][ncol] = newEff;
                    pq.push({newEff, {nrow, ncol}});
                }
            }
        }
    }

    return 0; // will never hit
     
} // O(ElogV) time and O(V + E) space using dijkstra
// O(nm * log(nm)) time and O(nm) space

//////////////////////////////////////////////////////////////////////////////////

// Now we will try another approach using binary search on answer
// so our range of answer is from 0 to 10^6 or 1e6, so we will check for mid = (low + high) / 2 and then do a simple bfs to check if there exists a path which has effort <= mid if yes then we store that look for lower similar to what we do in binary search on answers

bool check(int mid, vector<vector<int>> &heights) {

    int n = heights.size();
    int m = heights[0].size();

    int drow[] = {-1, 0, +1 , 0};
    int dcol[] = {0, 1, 0, -1};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;

    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();

        if(row == n - 1 && col == m - 1) {
            return true;
        }

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {

                int eff = abs(heights[row][col] - heights[nrow][ncol]);

                // we are marking something as visited only if it obeys that eff <= mid so we possibly cannot mark a node from a bad path (where eff > mid) as visited so we dont need to worry that we marked something as visited and couldnt get an answer from that path so now we wont able to traverse those nodes in future since we only go there if not visited since they are not going to give us answer anyway

                if(eff <= mid) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    return false;
}

int minEffortPathOptimal2(vector<vector<int>> &heights) {

    int low = 0, high = 1e6, ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(check(mid, heights) == true) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;

} // O(log(max_height of cell) * n * m) time and O(nm) space

int main() {
    
    return 0;
}