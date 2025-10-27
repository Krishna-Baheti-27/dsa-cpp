#include<bits/stdc++.h>
using namespace std;

// the intuition in bfs is that we started from two different positions but now we are colliding or reaching the same node and this will happen only if there is a cycle

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
                return true; 
            }

            // else we visited this node, but we have make sure that adjNode is not parent then only cycle because we know parent will be visited already since we came from parent (so it would be marked as visited before) but if we found a node which has been visited before and is not the parent which means some else touched it but how can two different path touch each other, this means we have a cycle
        }
    }
    return false; // no one collided
}

////////////////////////////////////////////////////////////////////////////////////

// now this was for the given source as 0 or the first node, but what if graph was broken into multiple components, then we would go and check for the each component once and as soon as any component returns a true for cycle we return true, or else traverse all components and didnt find a cycle so we return false

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

    for(int i = 0; i < v; i++) { // for 0 based graph
        if(!visited[i]) {
            if(detectCycle(i, adj, visited) == true) return true;
        }
    }
    return false;

} // since its a simple bfs so O(N + 2E) time + O(N) for components and O(N) space

int main() {
    
    return 0;
}