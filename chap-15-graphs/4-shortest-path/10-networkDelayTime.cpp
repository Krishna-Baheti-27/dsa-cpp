#include<bits/stdc++.h>
using namespace std;

// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1

////////////////////////////////////////////////////////////////////////////////////

// so we have to simply return the max of all the min shortest path starting with node = k as the src

// so apply dijkstra and find the shortest path for all nodes starting from source = k and then return the max amongst them since if you are able to send the signal to the node with max time and then all other nodes would automatically get the signal but if some node is unreachable then we return -1

int netWorkDelayTime(vector<vector<int>> &times, int n, int k) {

    // convert to adjacency list

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < times.size(); i++) {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }

    vector<int> minTime(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    minTime[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {

        int time = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // lazy dijkstra optimization
         
        if(time > minTime[node]) {
            continue;
        }

        for(auto &neighbour : adj[node]) {
            
            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(time + weight < minTime[adjNode]) {
                minTime[adjNode] = time + weight;
                pq.push({minTime[adjNode], adjNode});
            }
        }
    }

    minTime.erase(minTime.begin());

    int maxTime = *max_element(minTime.begin(), minTime.end());
    
    return maxTime == INT_MAX ? -1 : maxTime;

} // O(ElogV) time and O(V + E) space same as Dijkstra

int main() {
    
    return 0;
}