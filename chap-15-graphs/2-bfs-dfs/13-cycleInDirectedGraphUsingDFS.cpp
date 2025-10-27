#include<bits/stdc++.h>
using namespace std;

// the same algorithm for finding cycle in undirected graph does not work in directed graph due to a simple fact that in directed graph we have directed edges so a path from A to B is not same as path from B to A which is same in case of undirected graph 

// so on the same path you have to visit that node again to be called as cyclic directed graph

/////////////////////////////////////////////////////////////////////////////////////

// to do this using DFS we will maintain two arrays one visited and another path visited, for the directed graph to be cyclic if we find a node which is both and visited (and on the same path, that is path visited then we call the graph cyclic (shouldnt be parent as previous algo))

// if node encountered is visited but not path visited means it was visited before but not on the same path and hence not a cycle

// so apply this logic for each component and if any component returns true then graph is cyclic

bool isCyclicHelper(int node, vector<bool> &visited, vector<bool> &pathVisited, vector<int> adj[]) {

    visited[node] = true;
    pathVisited[node] = true;
    
    for(int adjNode : adj[node]) {
        if(!visited[adjNode]) { // for not visited
            if(isCyclicHelper(adjNode, visited, pathVisited, adj) == true) return true;
        } else if(pathVisited[adjNode]) { // already visited
            return false;
        }
    }

    // when backtracking change pathVisited to initial state
    pathVisited[node] = false;

    return false;
}

bool isCyclic(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);
    vector<bool> pathVisited(v, false);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(isCyclicHelper(i, visited, pathVisited, adj) == true) return true;
        }
    }

    return false;
} // O(N + E) time since directed graph and O(2N) space for visited and pathVisited

// Figure out how to do this using single array

int main() {
    
    return 0;
}