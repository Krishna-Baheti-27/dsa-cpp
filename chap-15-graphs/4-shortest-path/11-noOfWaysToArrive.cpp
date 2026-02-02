#include <bits/stdc++.h>
using namespace std;

// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.

////////////////////////////////////////////////////////////////////////////////////

// we have to basically count the number of shortest paths from 0 to n - 1

int countPathsOptimal(int n, vector<vector<int>> &roads) {

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    vector<long long> minTime(n, LONG_MAX);
    vector<long long> ways(n, 0);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    pq.push({0, 0}); // (time, node)
    ways[0] = 1;
    minTime[0] = 0;

    long long mod = 1e9 + 7;

    while(!pq.empty()) {
        
        int node = pq.top().second;
        long long time = pq.top().first;

        pq.pop();

        if(time > minTime[node]) {
            continue;
        }

        for(auto &adjNeighbour : adj[node]) {

            int adjNode = adjNeighbour.first;
            long long adjTime = adjNeighbour.second;

            if(time + adjTime < minTime[adjNode]) {

                minTime[adjNode] = time + adjTime;
                pq.push({minTime[adjNode], adjNode});
                ways[adjNode] = ways[node] % mod;
                 
            } else if(time + adjTime == minTime[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;

} // O(ELogV) time and O(V + E) space, same as dijkstra

////////////////////////////////////////////////////////////////////////////////////////

// now there is one more approach of doing this by separating the concerns and first finding the shortes path to all nodes and then using the property that shortest path always forms a DAG we can use dp to count all the ways

// we just have to obey this (similar to what we did in print shortest path and backtracking logic)

// Mathematically, if you are at node v, you look for a neighbor u with weight w such that: distance[u] + w == distance[v]



int main() {
    
    return 0;
}