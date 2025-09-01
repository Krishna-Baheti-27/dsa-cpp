#include<bits/stdc++.h>
using namespace std;

// in the case of bfs we were making sure that we only travel the nodes level by level by inserting them in a queue and going from there but in dfs we focus only travelling the depth first so basically we select a starting node and from there we go to its first negihbours depth entirely and when that returns we go to second neighbours depth and so on

void dfsHelper(int node, vector<int> adj[], vector<int> &dfs, int vis[]) {
    dfs.push_back(node);
    vis[node] = 1;
    // traverse all neighbours in depth first way
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfsHelper(it, adj, dfs, vis);
        }
    }
} // O(N) + O(2E) time for undirected but for directed it will be O(N) + O(E) (since we will traversing an edge only once)

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    // which nodes would be traversed first depends on how they are placed in adjacency list and what is the starting node
    // 0 based graph
    int vis[v];
    for(int i = 0; i < v; i++) vis[i] = 0;
    vector<int> dfs;
    int start = 0;
    dfsHelper(start, adj, dfs, vis);
    return dfs;
} // O(3N) space + O(N) time

int main() {
    
    return 0;
}