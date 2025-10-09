#include<bits/stdc++.h>
using namespace std;

// it is only possible for a DAG (Directed Acyclic Graph), definition explains why only DAG
// Topo sort is the linear ordering of vertices such that if there is a edge between u and v then u appears before v in that ordering

void dfs(int i, vector<int> &visited, vector<int> &ans, vector<int> adj[]) {
    visited[i] = 1; // mark as visited
    for(auto adjNode : adj[i]) {
        if(!visited[adjNode]) {
            dfs(adjNode, visited, ans, adj);
        }
    }
    ans.push_back(i); // before returning add it to answer (or stack)
    // Use stack to be more explicit about the LIFO ordering
}

vector<int> topoOrdering(int v, vector<int> adj[]) {
    vector<int> visited(v,0);
    vector<int> ans;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(i, visited, ans, adj);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
} // O(N) space for visited (ignoring the recursion stack space and space for returning answer)
// O(N + E) time for directed acyclic graph for dfs ans O(N / 2) time in last for reversal

int main() {
    
    return 0;
}