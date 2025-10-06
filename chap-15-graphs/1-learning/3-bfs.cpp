#include<bits/stdc++.h>
using namespace std;

// also know as level wise traversal since we go level by level, first we traverse all the nodes at a same level or at 0th level (only single node) from the starting node, then 1st level, 2nd level and so on, to do this we maintain a visited array to not traverse anything twice and also a queue to keep account of nodes to be  inserted from adjacency list

// here the level zero means nodes at 0 distance from startign node, level 1 means nodes at 1 distance from starting node and so on and thats why its BFS, since we go breadth first increasing distance by 1 unit in each iteration

// all depends on the starting node and depending on the starting node everything changes


// this code only traverses one component of a disconnected graph
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> bfs;
    int vis[v]; // try to use vectors instead of C-style arrays
    for(int i = 0; i < v; i++) vis[i] = 0; // since it is 0 based graph we have size of visited array as n and not n + 1 where n is number of node or number of vertices v
    queue<int> q; 
    q.push(0); // insert the first node which is 0 for 0 based graph
    vis[0] = 1; // mark the first node as visited since its in the queue

    // traverse across the graph while the queue is not empty
    while(!q.empty()) {
        int node = q.front(); q.pop(); // we popped this node so we would never get again

        bfs.push_back(node); // the node has been visited now traverse to its neighbours

        for(auto it : adj[node]) { // adj[node] is basically vector which we are traversing
            if(!vis[it]) {
                // if not visited then visit it by inserting into queue
                q.push(it); // inserted means visited
                vis[it] = 1; // so mark it as visited
            }
        } 
    } 
    return bfs;
} // O(N) for queue + O(N) space for visited (Not considereing space of adjaceny list or space to return traversal)
// O(N) time for initialising visited + O(N) time for which queue will run + O(2E) time for inner loop, as we know its visiting each all the degree of all nodes so total 2E

// so overall O(N) space + O(N + 2E) time

int main() { 
    
    return 0;
}