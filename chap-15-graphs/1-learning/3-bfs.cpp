#include<bits/stdc++.h>
using namespace std;

// also know as level wise traversal since we go level by level, first we traverse all the nodes at a same level or at 0th level (only single node) from the starting node, then 1st level, 2nd level and so on, to do this we maintain a visited array to not traverse anything twice and also a queue to keep account of nodes to be inserted from adjacency list

// here the level zero means nodes at 0 distance from starting node, which is the starting node itself, level 1 means nodes at 1 distance from starting node and so on and thats why its BFS, since we go breadth first increasing distance by 1 unit in each iteration, here the distance is measured radially outwards, in all directions

// all depends on the starting node and depending on the starting node everything changes and also on the order in which the nodes appear in adjacency list

// this code only traverses one component of a disconnected graph, for traversing entire graph split into multiple components, use a for loop across all the nodes and apply this traversal for the nodes which are not visited

vector<int> bfsOfGraph(int v, vector<int> adj[]) {  // v means number of nodes or vertices

    vector<int> bfs;
    vector<bool> vis(v, false); // assuming 0 based graph
    queue<int> q; 

    q.push(0); // insert the first node which is 0 for 0 based graph
    vis[0] = true; // mark the first node as visited since its in the queue

    // traverse across the graph while the queue is not empty

    while(!q.empty()) {

        int node = q.front(); 
        q.pop(); // we popped this node so we would never get again

        bfs.push_back(node); // add nodes to our traversal
        // node was already marked as visited when it was inserted so no need to do it again

        for(auto adjNode : adj[node]) { // adj[node] is list of all neighbours of node

            // if not visited then visit adjNode by inserting into queue

            if(!vis[adjNode]) { 
                q.push(adjNode); // inserted means visited
                vis[adjNode] = true; // so mark it as visited
            }
        } 
    } 

    return bfs;

} // O(N) + O(N + 2E) time and O(2N) space ignoring adjacency list and space to return bfs

// O(N) space for queue + O(N) space for visited (Not considereing space of adjaceny list or space to return traversal)
// O(N) time for initialising visited + O(N) time for which queue will run + O(2E) total time for which inner loop will run across the entire traversal, as we know its visiting all the degree of nodes of graph so total 2E 

// so overall O(N) space + O(N + 2E) time for undirected graph
// O(N) space and O(N + E) time for directed graph

// so it is clear that same code will also be working for directed graph since we just did the normal procedure of traversing all nodes without any specific assumption of undirected graph

int main() { 
    
    return 0;
}