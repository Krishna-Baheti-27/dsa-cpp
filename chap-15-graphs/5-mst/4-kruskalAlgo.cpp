#include<bits/stdc++.h>
using namespace std;

// helps us to find the MST of graph

// sort all the edges according to weight (weight, u, v)

// we are going to use the Disjoint set data structure

// we go from all edges starting from min weight to max and take union if the nodes u and v are not in the same component and thus we make sure we take min first by sorting and dont take anyone again if its already present in the main component or tree

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

int minSpanningTree(int v, vector<vector<pair<int,int>>> &adj) {

    vector<pair<int, pair<int,int>>> edges;

    for(int i = 0; i < v; i++) {

        for(auto &neighbour : adj[i]) {

            int adjNode = neighbour.first;
            int weight = neighbour.second;
            int node = i;

            // so here we inserting the same edge twice because of how adjacency list works but we are using Disjoint set so it will automatically handle that no worries

            edges.push_back({weight, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    int minCost = 0;

    DisjointSet ds(v); // for zero based graph

    for(auto &it : edges) {

        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
            minCost += wt;
            ds.unionBySize(u, v);
        }
    }
  
    return minCost;

} // O(N + 2E) time for figuring out edges then O(ElogE) time to sort edges then O(E * 2 * 4 * alpha) time due to Disjoint set and O(E) space to store all edges and O(2N) space for parent and size array and O(logN) recursion stack space for path compression

int main() {
    
    return 0;
}