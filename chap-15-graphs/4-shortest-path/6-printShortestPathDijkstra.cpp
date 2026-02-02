#include<bits/stdc++.h>
using namespace std;

// You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge between vertices a and b with weight w.

// If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.

//////////////////////////////////////////////////////////////////////////////////////

// so we have source = 1 and dest = n and we have to return the path taken from 1 to n and the first element of that array is weight of the path and corresponding elements are the nodes taken from 1 to n (along the shortest path) and if no path exists return the list consisting of only {-1}

// so here we will apply the dijkstra algo to find the shortest path from 1 to n

// but here we will need to sort of memoize to remember where are we coming from and backtrack which means we maintain from which node we got our min distace in the parent array

// and if we can maitain our min distance node for each node then we are done we will simply trace back the path from n to 1 using this once we find min distance parent node for everybody

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {

    // converting the edges to adjacency list

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // intialising distance and parent array to know the path where we came from

    vector<int> distance(n + 1, INT_MAX);
    vector<int> parent(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        parent[i] = i;   
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1}); // (dist, node)
    distance[1] = 0; 

    // so when we are starting from distance = 0 for node = 1, where are we actually coming from, from 1 only i guess and hence the parent[1] is initialised as 1, which means we got the shortest distance for 1 from node = 1

    while(!pq.empty()) {

        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(dis > distance[node]) {
            continue;
        }

        for(auto &neighbour: adj[node]) {

            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(dis + weight < distance[adjNode]) {

                distance[adjNode] = dis + weight;
                parent[adjNode] = node;
                pq.push({distance[adjNode], adjNode});

            }
        }
    }

    if(distance[n] == INT_MAX) {
        return {-1};
    }

    vector<int> path;
    int destNode = n;

    while(destNode != parent[destNode]) {
        path.push_back(destNode);
        destNode = parent[destNode];
    }

    path.push_back(1);
    path.push_back(distance[n]);

    reverse(path.begin(), path.end());

    return path;

} // O(ElogV) time for dijkstra ignoring construction of adjacency list and last traversal of backtracking to reach the path

// O(N + E) space (same as worst case space for dijkstra)

////////////////////////////////////////////////////////////////////////////////////

// this can also be done without using parent array and simply iterating through each neighbour and checking which neighbour brought me here

// Mathematically, if you are at node v, you look for a neighbor u with weight w such that: distance[u] + w == distance[v]

// but we do take a more time which is O(pathlength * avg degree) and also sacrifice readability and hence not worth it

int main() {
    
    return 0;
}