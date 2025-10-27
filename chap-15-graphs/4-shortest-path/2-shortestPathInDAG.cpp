#include<bits/stdc++.h>
using namespace std;

// given a DAG, find the shortest path from source to all vertex and source would be zero always, here the edge weights are not unit

//////////////////////////////////////////////////////////////////////////////

void dfs(int node, stack<int> &st, vector<bool> &visited, vector<pair<int,int>> adj[]) {

    visited[node] = true;

    for(auto adjNode : adj[node]) {
        if(!visited[adjNode.first]) {
            dfs(adjNode.first, st, visited, adj);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int src, int v, int e, vector<vector<int>> &edges) {
    // construct the graph
    vector<pair<int,int>> adj[v];
    for(int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    // find the topo sort of graph using dfs
    stack<int> st;
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(i, st, visited, adj);
        }
    }

    // now initialise a distance array with all values as INT_MAX and st.top as 0
    vector<int> distance(v, INT_MAX);
    distance[src] = 0;

    while(!st.empty()) {
        int node = st.top(); st.pop();

        if(distance[node] != INT_MAX) {
            for(auto adjNode : adj[node]) {
                if(distance[adjNode.first] > distance[node] + adjNode.second) {
                    distance[adjNode.first] = distance[node] + adjNode.second;      
                }
            } 
        }
    }

    for(int i = 0; i < distance.size(); i++) {
        if(distance[i] == INT_MAX) distance[i] = -1; // for unreachable
    }

    return distance;
}

int main() {
    
    return 0;
}