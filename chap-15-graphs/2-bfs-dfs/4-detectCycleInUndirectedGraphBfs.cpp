#include<bits/stdc++.h>
using namespace std;

// the graph is said to have a cycle if we start from a node and return to the same node through some path

////////////////////////////////////////////////////////////////////////////////////////////

// first of all if we are starting from a position and there ae two different ways to reach some end position from that start position then the graph is said to have a cycle

// so what we are looking for is when we traverse all the nodes level by level using bfs and we encouter that a node has already been traversed before (marked as visited) but we didnt came from that node (not parent, as that will always be visited as we came from that), which means we have a cycle as someone else visited it from a different path which means we have two paths and hence the cycle

// the intuition in bfs is that we started from two different positions but now we are colliding or reaching the same node and this will happen only if there is a cycle

// note that this logic only holds for undirected graphs 

////////////////////////////////////////////////////////////////////////////////////////////

bool isCycle(int v, vector<int> adj[]) {

    queue<pair<int,int>> q;
    vector<bool> visited(v, false);

    q.push({0, -1}); // assuming 0 based graph so parent of 0 is -1
    visited[0] = true; // mark it as visited

    while(!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto adjNode : adj[node]) {

            if(!visited[adjNode]) {

                visited[adjNode] = true; // if not visited then visit it
                q.push({adjNode, node}); // set its parent

            } else if(adjNode != parent) {
                
                // the adjNode has been visited, so either the adjNode can be parent and it will be visited naturally since we came from parent and but if the adjNode is not parent but is still visited which means somenone else from different path touched it so there is a cycle

                return true; 
            }
        }
    }

    return false; // no one collided

} // O(N + 2E) time and O(N) space 

////////////////////////////////////////////////////////////////////////////////////

// now this was for the given source as 0 or the first node, but what if graph was broken into multiple components, then we would go and check for the each component once and as soon as any component returns a true for cycle we return true for the whole graph, or else traverse all components and didnt find a cycle so we return false

bool detectCycle(int start, vector<int> adj[], vector<bool> &visited) {

    queue<pair<int,int>> q;

    q.push({start, -1});
    visited[start] = true;

    while(!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto adjNode : adj[node]) {

            if(!visited[adjNode]) {

                q.push({adjNode, node});
                visited[adjNode] = true;

            } else if(adjNode != parent) {
                return true;
            }

        }
    }

    return false;
}

bool isCycleComplete(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);

    // for 0 based graph

    for(int i = 0; i < v; i++) {

        // if any of the components have a cycle then the graph is said to be cyclic

        if(!visited[i]) {
            if(detectCycle(i, adj, visited) == true) {
                return true;
            }
        }
    }
    
    return false;

} // since its a simple bfs so O(N + 2E) time + O(N) for components and O(N) space

int main() {
    
    return 0;
}