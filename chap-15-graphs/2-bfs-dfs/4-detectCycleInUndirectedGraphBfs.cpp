#include<bits/stdc++.h>
using namespace std;

// the intuition is in bfs we started from two different positions but now we are colliding or reaching the same node and this will happen only if there is a cycle

bool isCycle(int v, vector<int> adj[]) {
    queue<pair<int,int>> q;
    vector<int> visited(v, 0);
    q.push({0, -1}); // assuming 0 based graph so parent of 0 is -1
    visited[0] = 1; // mark it as visited
    while(!q.empty()) {
        int node = q.front().first, parent = q.front().second;
        q.pop();
        for(auto it : adj[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push({it, node}); 
            } else if(it != parent) {
                return true; // the parent would be already visited so we check if theres some other node which is visited other than parent but was on a different path and hence forms a cycle
            }
        }
    }
    return false; // no one collided
}

// now this was for the given source as 0 or the first node, but what if graph was broken into multiple components, then we would go and check for the each component once and as soon as any component returns a true for cycle we return true, or else traverse all components and didnt find a cycle so we return false

bool detectCycle(int i, vector<int> adj[], vector<int> &visited) {
    queue<pair<int,int>> q;
    q.push({i, -1});
    visited[i] = 1;
    while(!q.empty()) {
        int node = q.front().first, parent = q.front().second;
        q.pop();
        for(auto adjNode : adj[node]) {
            if(!visited[adjNode]) {
                q.push({adjNode, node});
                visited[adjNode] = 1;
            } else if(adjNode != parent) return true;
        }
    }
    return false;
}

bool isCycleComplete(int v, vector<int> adj[]) {
    vector<int> visited(v, 0);
    for(int i = 0; i < v; i++) { // for 0 based graph
        if(!visited[i]) {
            if(detectCycle(i ,adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    
    return 0;
}