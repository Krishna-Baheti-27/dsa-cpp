#include<bits/stdc++.h>
using namespace std;

// graph is a set of edges and vertices
// there are mainly two types of graphs : directed and undirected 
// graph is said to be cyclic if there is atleast one cycle (start from the node and comeback at the same node, give extra care while checking for directed graphs)
// DAG is known as Directed Acyclic Graph
// Path is route connecting nodes where any node cannot appear twice

// For undirected graphs only : E is number of edges
// Degree of graph is number of edges attached to it for undirected graphs, degree = 2*E

// For directed graphs only:
// Here we have both indegree and outdegree where there names are self explanatory

// For graphs where edge weight is not given, it is assumed to be unit weighted

// they will give us n nodes and m edges as input so basically n, m or e,v
// and then we would have m lines representing all edges in the graph if it is an undirected graph then 1 2 is same as 2 1 and it means there is an edge from 1 to 2 and 2 to 1, and for directed graph we will have clear indication of direction

// here the number of edges is not related to number of nodes in any way, we can decrease m or increase m according to our choice

// two ways to store => 1) Matrix 2) List

// adjacency matrix way
vector<vector<int>> graph() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1)); // this alone takes O(n^ 2) time
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // in case of weighted graph store weight
        adj[v][u] = 1;  // in case of directed graph you wont do this
    } 
    return adj; 
} // O(n^2) space and O(m + n^2) time, here we have assumed 1-based graph thats why size is n + 1

// adjacency list way
vector<vector<int>> graph2() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1); // use vector<pair<int,int>> for storing weights also
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // in this method we store all the neighbours of a node in a list
        adj[u].push_back(v); // store pairs (node, weight) for weighted graph
        adj[v].push_back(u); // this line will not be required for directed graphs (since edge only from u to v and not v to u and hence only O(e) space)
    }
    return adj;
} // O(2e + n) space where e is number of edges and n space for array of vectors and O(m)  time

// in case of weighted graphs you also have to include the edge weight so how do we do that?
// In matrix instead of storing 1, we store the weight
// In list instead of storing only vector<int>, we store vector<pair<int,int>>, and in each pair the second member keeps track of weight

int main() {
    
    return 0;
}