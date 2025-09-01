#include<bits/stdc++.h>
using namespace std;

// they will give us n nodes and m edges as input so basically n, m
// and then we would have m lines representing the graph if it is an undirected graph then 1 2 is same as 2 1 and it means there is an edge from 1 to 2 and 2 to 1, and for directed graph we will have clear indication of direction

// two ways to store => 1) Matrix 2) List

// adjacency matrix way
int** graph() {
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    return adj;
} // O(n^n) space and O(m) time

vector<int> *graph2() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // in this method we store all the neighbours of a node in a list
        adj[u].push_back(v);
        adj[v].push_back(u); // this line will not be required for directed graphs (since edge only from u to v and not v to u and hence only O(e) space)
    }
    return adj;
} // O(2e) space where e is number of edges so basically O(2m) space and O(m) time

// in case of weighted graphs you also have to include the edge weight so how do we do that?
// In matrix instead of storing 1, we store the weight
// In list instead of storing only vector<int>, we store vector<pair<int,int>>, and in each pair the second member keeps track of weight

int main() {
    
    return 0;
}