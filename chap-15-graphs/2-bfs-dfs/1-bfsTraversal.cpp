#include<bits/stdc++.h>
using namespace std;

// also know as level wise traversal since we go level by level, first we traverse all the nodes at a smae level or at 0th level from the starting node, then 1st level, 2nd level and so on, to do this we maintain a visited array to not traverse anything twice and also a queue to keep account of nodes to be  inserted from adjacency list

// we are indeed traversing level wise since all the neighbours of node come at a distance of one level

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> bfs;
    int vis[v];
    for(int i = 0; i < v; i++) vis[i] = 0; // since it is 0 based graph we have size of visited array as n and not n + 1 where n is number of node or number of vertices v
    vis[0] = 1; // mark the first node to visited 
    queue<int> q; 
    q.push(vis[0]); // insert the first node
    // traverse across the graph while the queue is not empty
    while(!q.empty()) {
        int node = q.front(); q.pop();
        bfs.push_back(node); // the node has been visited now traverse to its neighbours
        for(auto it : adj[node]) {
            if(!vis[it]) {
                // if not visited then visit it by inserting into queue
                q.push(it);
                vis[it] = 1;
            }
        }
    } 
} // O(N) for queue + O(N) for visited (Not considereing space of adjaceny list or space to return traversal)
// O(N) time for initialisinf visited + O(N) time for queue and O(2E) time for inner loop as it will run for exactly twice for each since we know no. of degrees = 2 * no of edges

int main() {
    
    return 0;
}