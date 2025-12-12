#include<bits/stdc++.h>
using namespace std;

// the problem simply states that we have n veritces or computers and given the connections or edges by which we know how they are connected, so we hace to reomve some of the edges or connections and add they somehwere else to make the entire graph connected

// currently the graph is disconnected

// as long as there are atleast n - 1 connections or edges (number of edges in spanning tree) we can still connect the entire graph of n vertices

// example : we have 5 components which are disconnected so min number of edges required to connect these 5 components = 4 

// so one of the approaches is to simply traverse and count the number of components in the graph and return components - 1 as those are the min number of edges to connect n components, (same as in spanning tree) and we have to return the min number

void dfsHelper(int node, vector<bool> &visited, vector<vector<int>> &adj) {

    visited[node] = true;

    for(int adjNode : adj[node]) {
        if(!visited[adjNode]) {
            dfsHelper(adjNode, visited, adj);
        }
    }
}

int makeConnectedDFS(int n, vector<vector<int>> &connections) {

    if(connections.size() < n - 1) {
        return -1;
    }

    vector<bool> visited(n, false);

    vector<vector<int>> adj(n);

    for(int i = 0; i < connections.size(); i++) {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    int components = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            components++;
            dfsHelper(i, visited, adj);
        }
    }

    // for n different components of a graph we require atleast n - 1 edges to connected them hence return components - 1

    return components - 1; 

} // O(N + 2E) time for dfs and O(N) space

///////////////////////////////////////////////////////////////////////////////////

// but the above solution is sort of a shortcut, the question stated to remove the connected edges and reuse them not build edges out of thin air 

// so what are the edges that can be reused, those are extra edges or edges whose removal does not make the graph disconnected

// once we have the number of extra edges as n, if n >= no. of components - 1 then we have our answer as no. of components - 1 else impossible and we return -1

// now how to count extra edges, we will use Disjoint Set, the edges which alreayd have same ultimate parent means they are already connected and hence can be counted as extra edges

class DisjointSet {

    vector<int> parent, size;

    public:

    DisjointSet(int n) {

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {

        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        // if they belong to the same component then we dont need to do the union operation

        if(ultimateParentU == ultimateParentV) {
            return;
        }

        // again the smaller size gets attached to larger size but the else if and else block is same so we just write the other case to simplify the logic

        if(size[ultimateParentU] < size[ultimateParentV]) {

            size[ultimateParentV] += size[ultimateParentU];
            parent[ultimateParentU] = ultimateParentV;

        } else {
            size[ultimateParentU] += size[ultimateParentV];
            parent[ultimateParentV] = ultimateParentU;
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections) {

    DisjointSet ds(n);

    int extraEdges = 0;

    for(int i = 0; i < connections.size(); i++) {
 
        int u = connections[i][0];
        int v = connections[i][1];

        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
            ds.unionBySize(u, v);
        } else {
            extraEdges++;
        }
    }

    // now lets find out the number of components using Disjoint Set

    int components = 0;

    for(int i = 0; i < n; i++) {
        if(ds.findUltimateParent(i) == i) {
            components++;
        }
    }

    return extraEdges >= components - 1 ? components - 1 : -1;

} // O(E + N) time and O(N) space for disjoint set

int main() {
    
    return 0;
}