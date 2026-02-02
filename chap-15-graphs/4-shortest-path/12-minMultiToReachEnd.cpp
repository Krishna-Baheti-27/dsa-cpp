#include <bits/stdc++.h>
using namespace std;

// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

/////////////////////////////////////////////////////////////////////////////////////////

// this problem is very similar to word-ladder and since there also we are trying everything

// here dijkstra not needed since steps increase by one and hence a simple queue would give us the shortest path and first answer to reach end is our answer

int minimumMultiplications(vector<int>& arr, int start, int end) {

    queue<pair<int,int>> q;
    vector<int> dis(100000, INT_MAX);

    q.push({0, start}); // (steps, node)
    dis[start] = 0;

    int mod = 100000;

    while(!q.empty()) {

        int steps = q.front().first;
        int node = q.front().second;

        q.pop();

        // no need to check since bfs with unit weights

        if(steps > dis[node]) {
            continue;
        }

        if(node == end) {
            return steps;
        }

        for(int i = 0; i < arr.size(); i++) {

            int num = (1LL * node * arr[i]) % mod; // long long more safe to avoid overflow

            // no need to relax like this, the first time we reach someone that is our answer

            if(steps + 1 < dis[num]) {
                dis[num] = steps + 1;
                q.push({steps + 1, num});
            }
        }
    }

    return -1; // not possible
        
} // O(10^5 * N) time but hypothetical since we wont ge generating all nodes or numbers and hence much lesser than this and O(10^5) for dis + O(10^5 * N) space for queue

////////////////////////////////////////////////////////////////////////////////////

int minMultiBetter(vector<int> &arr, int start, int end) {

    if(start == end) {
        return 0;
    }

    queue<pair<int,int>> q;
    vector<int> dis(100000, INT_MAX);

    q.push({0, start}); // (steps, node)
    dis[start] = 0;

    int mod = 100000;

    while(!q.empty()) {

        int steps = q.front().first;
        int node = q.front().second;

        q.pop();

        for(int i = 0; i < arr.size(); i++) {

            int num = (1LL * node * arr[i]) % mod; // long long more safe to avoid overflow

            if (dis[num] == INT_MAX) { 
                dis[num] = steps + 1;
                if (num == end) return steps + 1; // Return immediately optimization
                q.push({steps + 1, num});
            }
        }
    }

    return -1; // not possible
}

int main() {
    
    return 0;
}