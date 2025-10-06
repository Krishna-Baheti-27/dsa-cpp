#include<bits/stdc++.h>
using namespace std;

// in the case of bfs we were making sure that we only travel the nodes level by level which means travelling nodes at 1 distance, then 2 distances and so on inserting them in a queue and going from there but in dfs we focus only travelling the depth first so basically we select a starting node and from there we go to its first negihbours depth entirely and when that returns we go to second neighbours depth and so on

void dfsHelper(int node, vector<int> adj[], vector<int> &dfs, int vis[]) {
    dfs.push_back(node); // we added it to dfs traversal
    vis[node] = 1; // marked visited
    // traverse all neighbours in depth first way if not visited
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfsHelper(it, adj, dfs, vis); // if it is not visited then visit it
        }
    }
} // O(N + 2E) time for undirected graph as the dfsHelper would be called for exactly N times for N nodes and the inner for loop will run for total of 2E times to visit all the neighbours and for directed graph we have O(N + E) time


// this code only traverses one component of a disconnected graph
vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    // which nodes would be traversed first depends on how they are placed in adjacency list and what is the starting node
    // 0 based graph
    int vis[v];
    for(int i = 0; i < v; i++) vis[i] = 0;
    vector<int> dfs;
    int start = 0; // starting node
    dfsHelper(start, adj, dfs, vis);
    return dfs;
} // O(N) space for visited and O(N) for  recursion in worst case (ignoring the space to return answer and adjacency list)
// O(N) for initialising visited array + O(N + 2E) or O(N + E) time depending on graph

int main() {
    
    return 0;
}