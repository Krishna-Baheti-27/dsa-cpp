#include<bits/stdc++.h>
using namespace std;

// we have to detect whether a cycle is present or not in a Directed graph, we have already done this using DFS, here we will use BFS 

////////////////////////////////////////////////////////////////////////

// One distinct advantage of Kahn's algorithm over the DFS stack method is Cycle Detection.If the graph has a cycle (e.g., A to B to A), the indegrees of nodes in that cycle will never reach 0. They will never be added to the queue.If topoSort.size() < V at the end of the algorithm, it proves the graph contains a cycle (it is not a DAG).

// so for DAG, the indegree array at the end should have all values as 0 else there is a cycle in the graph

// We know that topoSort exists only for DAG which are directed acyclic graphs, if we try to apply topoSort to Directed cyclic graphs, (using Kahn algo) it would generate an invalid toppSort having lesser than N elements and valid in every other case and hence we can use topoSort to detect cycles since topoSort order is only being broken for cyclic graphs

// but here we dont even need to store the entire ordering but simply the number of nodes in it

bool detectCycle(int v, vector<int> adj[]) {

    vector<int> indegree(v, 0);
    queue<int> q; // queue for bfs

    for(int i = 0; i < v; i++) { 
        for(int adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }
    
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop(); 

        count++;

        for(int adjNode : adj[node]) {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    return count != v;

} // O(N + E) time for indegree + O(N) for insertion in queue + O(N + E) for traversal 
// O(2N) space for indegree + visited 

int main() {
    
    return 0;
}