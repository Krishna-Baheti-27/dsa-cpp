#include<bits/stdc++.h>
using namespace std;

// here we are using the priority queue or min-heap implementation of the Dijkstra algo
// we are given the unidirected weighted graph and the source and we have to find the shortest path to all the vertices from the source and it is guaranteed that grpah is connected and does not have any negative edge weights

//////////////////////////////////////////////////////////////////////////////////

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> &adj, int src) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(v, INT_MAX);

    distance[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {

        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // if the current distance is worse than what we already found then we skip it, this is know as Lazy optimisation 
        // This correctly skips outdated entries in the priority queue

        if(dis > distance[node]) continue;

        for(auto &it : adj[node]) {

            int adjNode = it.first;
            int weight = it.second;

            if(dis + weight < distance[adjNode]) {
                distance[adjNode] = dis + weight;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }

    return distance;

} // O(ElogV)  or O(ElogE) time and but in the worst case we have duplicate insertion problem in PQ (as C++ STL does not have decrease_key for PQ) and hence the space can go up to O(V + E) or O(E) or O(V^2) as E = V^2 for dense graphs

// but if we have Index Priority Queue with decrease_key method then we can have O(V) space implementation

// E is total number of edges in graph and V is total number of nodes

/////////////////////////////////////////////////////////////////////////////////

// Why does dijkstra does not work for negative weights (answer is not guaranteed to be correct) and definitely does not work for negative weight cycles

// for negative weight we have chance that answer might be incorrect, but here it wont be the case since we are inserting each time even if we already have a better distance (the thing which we dont do in Dijkstra using set) and hence here we will have correct answer but still it is not preferred to use Dijkstra for graph having negative weights

// and in case of negative weight cycle we get stuck in an infinite loop of repeated insertion and popping in min heap thus doesnt work

int main() {
    
    return 0;
}