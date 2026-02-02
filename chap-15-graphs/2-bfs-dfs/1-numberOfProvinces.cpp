#include<bits/stdc++.h>
using namespace std;

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces

// a province is part of graph in which there exists a path from u to v or v to u where u,v are nodes in that province, given the graph we have to count the number of provinces, basically a province is a part of a graph where every node is connected to each other

// Here the cities refer to the nodes of graph and province refers to a component, so we have to count number of provinces or the number of connected components in graph

////////////////////////////////////////////////////////////////////////////////////

void dfs(int node, vector<bool> &vis, vector<int> adjLs[]) {

    vis[node] = true; // make the node visited and then go to the depths of it
    for(auto adjNode : adjLs[node]) {
        if(!vis[adjNode]) {
            dfs(adjNode, vis, adjLs);
        }
    }

}

int numOfProvinces(vector<vector<int>> &adj) {

    // the question here apprantely gives us adjancency matrix and not list and hence we convert the matrix to list

    int v = adj.size(); // number of nodes
    vector<int> adjLs[v]; // adjacency list

    // to change the adjacency matrix to list

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {

            // since we cant have an edge from 1 to 1

            if(adj[i][j] == 1 && i != j) { 

                // this alone is sufficient becuase lets say you have edge from 1 - 2 so it will be present in matrix[1][2] and also matrix[2][1] which means we only have to add to either i or j not both and complete traversal of matrix will insert both, else we will be inserting duplicates which increases space and lowers time

                adjLs[i].push_back(j);

                // adjLs[j].push_back(i); // not needed as explained
            }
        }
    } 
    
    // conversion done 

    // our main variable to count number of provinces based on how many times dfs function is being called since each call to dfs completes the traversal for the entire component

    int count = 0; 

    vector<bool> vis(v, false); // visited array initially false

    // our main logic to calculate the number of provinces

    // if this node is not visited then visit it by dfs but how many times dfs is called is exactly the number of provinces since a dfs would traverse entirety of that province and mark everyone there to be visited and hence if it were to be called again it means that a new province is encountered whose nodes have not been traversed yet

    for(int i = 0; i < v; i++) {
        
        if(!vis[i]) {
            count++; // count the new province
            dfs(i, vis, adjLs);
        }
    }

    return count;
} 

// we ignoring time and space for adjacency matrix to list because most of the time we will have list, so time and space complexity will be same of that of traversal algorithm used

// O(N) space for visited and O(N) for recursion stack space
// O(N) + O(N + 2E) time, since the dfs function is actually only being called count number of times and not in every iteration but in the worst case count = N and it overall processes the entire graph so O(N + 2E) overall when it processes all provinces

int main() {
    
    return 0;
}