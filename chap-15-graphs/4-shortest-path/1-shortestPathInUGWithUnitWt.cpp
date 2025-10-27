#include<bits/stdc++.h>
using namespace std;

// you are given an undirected graph with a source node, you ave to find the shortest distance from source to all nodes, all tbe edges are unit weighted

///////////////////////////////////////////////////////////////////////////////////////

// here we follow a simple BFS traversal since we know it goes level by level and all the edge weights are one so first level 0 for the node itself then level at distance 1, pretty easy, then we apply greedy approach to only update the distance if its lesser than already stored value since we want shortest path

// here i have taken adjacency list directly but if questions gives us nodes

vector<int> shortestPath(int v, vector<int> adj[], int src) {

    queue<int> q; // to store (node, distance)
    vector<int> distance(v, INT_MAX);

    distance[src] = 0;
    q.push(src);

    while(!q.empty()) {

        int node = q.front();

        q.pop();

        for(auto adjNode : adj[node]) {
            if(distance[adjNode] > distance[node] + 1) {
                q.push(adjNode);
                distance[adjNode] = distance[node] + 1;
            }
        }

    }

    // now if someone could not be reached then its distance would be left as INT_MAX, so now we traverse the array and all the distance which were INT_MAX, we change them to -1 as question demanded

    for(int i = 0; i < distance.size(); i++) {
        if(distance[i] == INT_MAX) distance[i] = -1;
    }

    return distance; 
}

int main() {
    
    return 0;
}