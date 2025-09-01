#include<bits/stdc++.h>
using namespace std;

// a province is part of graph in each there exists a path from u to v or v to u where u,v are nodes in that province, given the graph we have to count the number of provinces


// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces


void dfs(int node, int vis[], vector<int> adjLs[]) {
    vis[node] = 1; // make the node visited and then go to the depths of it
    for(auto it : adjLs[node]) {
        if(!vis[it]) dfs(it, vis, adjLs);
    }
}

int numOfProvinces(vector<vector<int>> &adj) {
    // the question here apprantely gives us adjancency matrix and not list and hence we convert the matrix to list
    int v = adj.size();
    vector<int> adjLs[v]; // adjacency list
    // to change the adjacency matrix to list
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int count = 0;
    int vis[v];
    for(int i = 0; i < v; i++) vis[i] = 0;
    // our main logic to calculate the number of provinces
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            // if this node is note visited then visit it by dfs but how many times dfs is called is exactly the number of provinces since a dfs would traverse entirety of that province and mark everyone there to be visited and hence if it were to be called again it means that a new province is encountered whose nodes have not been traversed yet
            count++;
            dfs(i, vis, adjLs);
        }
    }
    return count;
    // we ignoring time and space for adjacency matrix to list because most of the time we will have list
} // O(N) space for visited and O(N) for recursion stack space
// O(N) + O(V + 2E) time, since the dfs function is actually only being called count number of times and not in every iteration and it overall processes the entire graph so O(V + 2E) overall when it processes all provinces

int main() {
    
    return 0;
}