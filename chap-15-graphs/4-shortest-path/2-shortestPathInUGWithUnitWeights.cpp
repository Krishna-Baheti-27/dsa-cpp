#include<bits/stdc++.h>
using namespace std;

// we are given an undirected graph having unit weights and we have to compute the shortest path to all the vertices from the given source and -1 for unreachable nodes

////////////////////////////////////////////////////////////////////////////////////

// here it is not DAG but instead undirected so we cant apply the previous method of relaxing all the vertices of each vertex one by one in the topo sort order

// however we dont need to apply any fancy algo since it is a graph having unit weights to se can simply do a bfs traversal (level by level) and we are guranteed that the nodes at the most greatest level will be most farthest as the distance increases by constant = 1 (which is our unit weight) for all the edges

// so we simply maintain a queue with (node, distance) and do a bfs traversal and update our distance array if we find a smaller distance (initially all infinity)

vector<int> shortestPathBrute(int v, int src, vector<vector<int>> &adj) {

    queue<pair<int,int>> q;
    vector<int> distance(v, INT_MAX);

    q.push({src, 0});
    distance[src] = 0;

    while(!q.empty()) {

        int node = q.front().first;
        int dis = q.front().second;

        q.pop();

        for(int adjNode : adj[node]) {
            if(dis + 1 < distance[adjNode]) {
                q.push({adjNode, dis + 1});
                distance[adjNode] = dis + 1;
            }
        }
    }

    // the vertices still having distance = infinity are unreachable and hence update them to -1 according to question

    for(int i = 0; i < v; i++) {
        if(distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }

    return distance;

} // O(N + 2E) bfs and O(2N) space for queue and distance

// the above method also works for graphs having different edge weights but performs worse than dijkstra and worst case is O(V.E) time

/////////////////////////////////////////////////////////////////////////////////

// but a more better method is to just store and node and we hzve already have the distance array to store the distance and hence we dont need to store distance for each node

// and also since all edges weights are one it is similar to unweighted graph and (like all edges weights 2, 3 or anything same for all) and hence a simple bfs will help us reach any node in shortest time and the first time we reach it will be our min distance

vector<int> shortestPath(int v, int src, vector<vector<int>> &adj) {

    // Optimization: Store just 'int' in queue
    queue<int> q; 
    vector<int> distance(v, INT_MAX);

    q.push(src); 
    distance[src] = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for(int adjNode : adj[node]) {
            
            // In unit-weight graphs, the first time we reach a node, 
            // it IS the shortest path. We strictly only process unvisited nodes (INT_MAX).
            // and no need for relaxation logic update directly

            if(distance[adjNode] == INT_MAX) {
                distance[adjNode] = distance[node] + 1;
                q.push(adjNode);
            }
        }
    }

    // Convert unreachable nodes to -1
    
    for(int i = 0; i < v; i++) {
        if(distance[i] == INT_MAX) distance[i] = -1;
    }

    return distance;

} // O(N + 2E) time and O(N) space

int main() {
    
    return 0;
}