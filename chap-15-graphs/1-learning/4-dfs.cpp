#include<bits/stdc++.h>
using namespace std;

// in the case of bfs we were making sure that we only travel the nodes level by level which means travelling nodes at 1 distance, then 2 distances and so on inserting them in a queue and going from there but in dfs we focus only travelling the depth first so basically we select a starting node and from there we go to its first negihbours depth entirely and when that returns we go to second neighbours depth and so on until all nodes are visited

// again order of traversal depends on the starting node and how nodes are arranged in the adjacency list

void dfsHelper(int node, vector<int> adj[], vector<int> &dfs, vector<bool> &vis) {

    dfs.push_back(node); // we added it to dfs traversal
    vis[node] = true; // marked visited

    // traverse all neighbours in depth first way if not visited

    for(auto adjNode : adj[node]) {
        if(!vis[adjNode]) {
            dfsHelper(adjNode, adj, dfs, vis); // if it is not visited then visit it
        }
    }
} 

// O(N + 2E) time for undirected graph as the dfsHelper would be called for exactly N times for N nodes and the inner for loop will run for total of 2E times across the entire traversal to visit all the neighbours and for directed graph we have O(N + E) time

// this code only traverses one component of a disconnected graph

vector<int> dfsOfGraph(int src, int v, vector<int> adj[]) {
   
    vector<bool> vis(v, false); // 0 baed graph
    vector<int> dfs;

    dfsHelper(src, adj, dfs, vis);

    return dfs;

} // O(N) space for visited and O(N) recursion stack space in worst case (ignoring the space to return answer and adjacency list)
// O(N) for initialising visited array + O(N + 2E) or O(N + E) time depending on graph

/////////////////////////////////////////////////////////////////////////////////////

// the generalised code for dfs is here

void dfsHelper(int src, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &dfs) {

    dfs.push_back(src);
    visited[src] = true;

    for(int adjNode : adj[src]) {

        if(!visited[adjNode]) {
            dfsHelper(adjNode, visited, adj, dfs);       
        }
    } 
}

vector<int> dfsGeneral(int v, vector<vector<int>> &adj) {

    vector<bool> visited(v, false);
    vector<int> dfs;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfsHelper(i, visited, adj, dfs);
        }
    }

    return dfs;

} // O(N + 2E) time and O(N) space

int main() {
    
    return 0;
}