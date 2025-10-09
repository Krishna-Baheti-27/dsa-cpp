#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int parent, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1; // mark it as visited
    for(auto adjNode : adj[node]) {
        if(!visited[adjNode]) {
            if(detectCycle(adjNode, node, visited, adj) == true) return true;
        } else if(adjNode != parent) {
            return true; // again we have a cycle
        }
    }
    return false;
}

bool isCycleComplete(int v, vector<int> adj[]) {
    vector<int> visited(v);
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(detectCycle(i, -1, visited, adj)) return true; // return true if any of the components return true for the cycle
        }
    }
    return false; // if no cycle in all components 
} // O(N) space for visited + O(N) for recursion stack space
// O(N) times the for loop runs in total and O(N + 2E) total time, because only when not visited then detectCycle will be called

int main() {
    
    return 0;
}