#include <bits/stdc++.h>
using namespace std;

// Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

// Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

////////////////////////////////////////////////////////////////////////////////////////

// this is also single source shortest path

// bellmann ford helps us find shortest path similar to dijkstra but it works for graphs having negative edge weights and also help us detech negative weight cycle where dijkstra would give wrong answer and tle respectively

// but it only works for directed graphs and hence convert the undirected graph to directed graph by inserting both edges

// but if the undirected graph has negative weights then converting it to directed would make a negative weight cycle and bellmann would not be able to calculate shortest path

// so here we are doing n - 1 iterations and in each iteration we relax all the edges and we do it for n - 1 times since starting from any src the max edges required to reach the farthest node is n - 1, so in each iteration we are finding the shortest distance of each node one by one and (starting closest to src) and after n - 1 iterations we would be able to find the distance of farthest node

// and if the nth iteration we are still able to find a lower distance which means we have a negative weight cycle which is reduing the distance (it will be infinite loop similar to dijkstra) and hence break out and say it has negative weight cycle

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dis(V, 100000000);

    dis[src] = 0;

    for(int i = 0; i < V - 1; i++) {

        for(int j = 0; j < edges.size(); j++) {
            
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dis[u] != 100000000 && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(dis[u] != 100000000 && dis[u] + w < dis[v]) {
            return {-1};
        }
    }

    return dis;

} // O(V.E) time and O(V) extra space for distance array

int main() {
    
    return 0;
}