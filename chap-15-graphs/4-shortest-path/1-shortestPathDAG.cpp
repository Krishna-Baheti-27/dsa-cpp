#include<bits/stdc++.h>
using namespace std;

// given a directed acyclic graph (DAG), find the shortest path from source to all vertices where edge weight represents the distance

///////////////////////////////////////////////////////////////////////////////

// here we will apply the algo which works specifically for DAG since we will be using modified version of topo sort (with relaxation)

// step 1 of algo : do the topo sort (use any method dfs or bfs)

// step 2 : take out nodes from stack one by one and relax the edges

// the reason this algo works is because in the topo sort, we will have the ordering of vertices according to reachability, first we will have those from which we can reach to everyone else (those having indegree == 0) so we travel sequentially in increasing order of indegree and hence starting at node u we are sure that we have already processed all the paths leading to u (vertices appearing before u in topo sort) and therefore distance[u] is alreayd finalised and optimal and we dont have to look back and find any other path to u which has shorter distance from source since from the beginning we tried to process nodes in the correct linear order 

// hence it is based on the simple logic that finding the shortest path is easy if you know the shortest path of all the vertices preceding the current vertex since the only way to reach the current vertex is by the preceding vertices in the topo sort and we have already computed the shortest distance from source to preceding vertex and hence our computation for current vertex would also be correct

// and also the longest path is easy if you know the longest path of all the vertices preceding the current vertex

void dfsHelper(int node, vector<bool> &visited, stack<int> &st, vector<vector<pair<int,int>>> &adj) {

    visited[node] = true;

    for(auto &adjNode : adj[node]) {
        if(!visited[adjNode.first]) {
            dfsHelper(adjNode.first, visited, st, adj);
        }
    }
                       
    st.push(node);
}

vector<int> shortestPath(int source, int v, vector<vector<pair<int,int>>> &adj) {

    vector<bool> visited(v, false);
    stack<int> st;

    // dfsHelper(source, visited, st, adj); 

    // writing only this is an optimisation since you are only trying to find the topo sort of the vertices that you can rech from source and thats exactly what we want right since if we cant reach vertices of other components from source (distanc = infinity) then there is no need to find the complete topo sort of the entire graph

    // but it is standard to find the entire topo sort even for graph with multiple components and hence  

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfsHelper(i, visited, st, adj);
        }
    }

    vector<int> distance(v, INT_MAX);
    distance[source] = 0;

    while(!st.empty()) {

        int node = st.top();

        st.pop();

        // only relax the edge if node has been reached before which means that
        // distance[node] != INT_MAX else we will have overflow due to INT_MAX + edge weight

        if(distance[node] != INT_MAX) {
            for(auto &adjNode : adj[node]) {
                distance[adjNode.first] = min(distance[adjNode.first], distance[node] + adjNode.second);
            }
        }
    }

    return distance;

} // O(N + E) time and O(N) space

int main() {
    
    return 0;
}