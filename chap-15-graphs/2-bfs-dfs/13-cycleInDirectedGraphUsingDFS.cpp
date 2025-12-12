#include<bits/stdc++.h>
using namespace std;

// the same algorithm for finding cycle in undirected graph does not work in directed graph due to a simple fact that in directed graph we have directed edges so a path from A to B is not same as path from B to A which is same in case of undirected graph 

// so on the same path you have to visit that node again to be called as cyclic directed graph
// if the node was visited again but from a different path then it cannot be called as cyclic

// if you remember our logic for finding cycle in undirected graph we used the fact that if the node has been visited already from some different path other than our current then its a cycle, but here we need to have the same path


/////////////////////////////////////////////////////////////////////////////////////

// to do this using DFS we will maintain two arrays one visited and another path visited, for the directed graph to be cyclic if we find a node which is both and visited (and on the same path, that is path visited then we call the graph cyclic 

// if node encountered is visited but not path visited means it was visited before but not on the same path and hence not a cycle

// so apply this logic for each component and if any component returns true then graph is cyclic

// here we dont check for if the adjNode is parent or not, because in directed graphs, nodes are one-way streets, like u -> v, so you are sure that you wont have u as an adjNode of v and thus no need to check it

bool isCyclicHelper(int node, vector<bool> &visited, vector<bool> &pathVisited, vector<int> adj[]) {

    visited[node] = true;
    pathVisited[node] = true;
    
    for(int adjNode : adj[node]) {

        if(!visited[adjNode]) { 

            // if we found that there is cycle then return true early and no need to do the entire dfs traversal

            if(isCyclicHelper(adjNode, visited, pathVisited, adj) == true) {
                return true;
            }

        } else if(pathVisited[adjNode]) { 

            // node is already visited if we entered this else-if block, if the node is also path visited then it is cycle so we return true

            return true;
        }
    }

    // when backtracking change pathVisited to initial state since we didnt found our answer

    pathVisited[node] = false;

    return false;
}

bool isCyclic(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);
    vector<bool> pathVisited(v, false);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(isCyclicHelper(i, visited, pathVisited, adj) == true) {
                return true; // found the cycle so return true for entire graph
            }
        }
    }

    return false;

} // O(N + E) time since directed graph and O(2N) space for visited and pathVisited and O(N) for recursion stack space

//////////////////////////////////////////////////////////////////////////////////

// Now this can also be done using a single array that is just visited
// what we do is that in the visited we create states that is
// 0 == unvisited
// 1 == visited
// 2 == visited and path visited

// and thus using this definition we can solve this problem using a single array

bool dfsHelper(int node, vector<int> &visited, vector<int> adj[]) {

    visited[node] = 2; // mark the node as visited and path visited

    for(int adjNode : adj[node]) {
        if(visited[adjNode] == 0) {
            if(dfsHelper(adjNode, visited, adj) == true) {
                return true;
            }
        } else if(visited[adjNode] == 2) {
            // this is visited and path visited
            return true;
        } 
    }

    // backtracking step of making path visited false

    visited[node] = 1;

    return false; 
} 

bool isCyclicOptimal(int v, vector<int> adj[]) {

    vector<int> visited(v, 0);

    for(int i = 0; i < v; i++) {
        if(visited[i] == 0) {
            if(dfsHelper(i, visited, adj) == true) {
                return true;
            }
        }
    }

    return false;

} // O(N + E) time and O(N) space for array and O(N) recursion stack space

int main() {
    
    return 0;
}