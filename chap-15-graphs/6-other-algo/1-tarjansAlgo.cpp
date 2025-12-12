#include<bits/stdc++.h>
using namespace std;

// the an edge in a graph is said to be a bridge if upon its removal, the graph becomes disconnected (or being broken down into two or more components)

// these are also known as critical edges

// so the problem states to print all the bridges (critical edges) in the graph

////////////////////////////////////////////////////////////////////////////////////

// here we use the dfs approach to find 

void dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &time, vector<int> &low, int &timer, vector<vector<int>> &bridges) {

    visited[node] = true;
    time[node] = timer;
    low[node] = timer;

    timer++;

    for(int adjNode : adj[node]) {

        if(adjNode == parent) {
            continue;
        }

        if(!visited[adjNode]) {
            dfs(adjNode, node, visited, adj, time, low, timer, bridges);
            low[node] = min(low[node], low[adjNode]);

            // bride from node --- it
            if(low[adjNode] > time[node]) {
                bridges.push_back({adjNode, node});
            }
        } else {

            // cannot be a bridge since adjNode is already visited (n)
            low[node] = min(low[node], low[adjNode]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
     
    // creating the adjacency list

    vector<vector<int>> adj(n); // 0 based graph

    for(int i = 0; i < connections.size(); i++) {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> time(n), low(n);
    vector<bool> visited(n, false);

    vector<vector<int>> bridges;

    int timer = 0;

    dfs(0, -1, visited, adj, time, low, timer, bridges);

    return bridges;
}

int main() {
    
    return 0;
}