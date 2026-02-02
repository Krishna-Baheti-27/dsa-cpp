#include <bits/stdc++.h>
using namespace std;

// You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
// The graph may contain negative edge weights, but it does not contain any negative weight cycles.

// Your task is to find the shortest distance between every pair of nodes i and j in the graph.

// Note: Modify the distances for every pair in place.

//////////////////////////////////////////////////////////////////////////////////////

void floydWarshall(vector<vector<int>> &dist) {
    
    int n = dist.size();

    // we have to do it inplace so modify the current adjancency matrix

    for(int via = 0; via < n; via++) {

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][via] != 100000000 && dist[via][j] != 100000000) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }   

} // O(n^3) time and O(n^2) space

////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> floydWarshallComplete(vector<vector<int>> &dist) {

    // get the starting point, where dist[i][i] = 0 and unreachable nodes are marked with INT_MAX

    vector<vector<int>> cost = dist; 

    int n = dist.size();

    for(int via = 0; via < n; via++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(cost[i][via] != 100000000 && cost[via][j] != 100000000) {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
    }  

    // detect negative weight cycle

    for(int i = 0; i < n; i++) {
        if(cost[i][i] < 0) {
            return {};
        }
    }

    return cost;

} // O(n^3) time and O(n^2) space

/////////////////////////////////////////////////////////////////////////////////////

// Why must via be the outer loop? Floyd-Warshall is a Dynamic Programming algorithm.

// Iteration 0: Find shortest paths using only Node 0 as an intermediate point.

// Iteration 1: Find shortest paths using Nodes {0, 1} as intermediate points.

// Iteration K: Find shortest paths using Nodes {0, 1, ..., K} as intermediate points.

// If you put the via loop inside, you would just be checking if a direct hop through one specific node helps, but you wouldn't be building on top of previous optimizations.

//////////////////////////////////////////////////////////////////////////////////////

// and we can also apply dijkstra N times but we shouldnt have negative weights and preferable for sparse graphs where E == V and for dense use floyd warshall E == V^2

int main() {
    
    return 0;
}