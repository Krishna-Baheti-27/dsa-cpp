#include<bits/stdc++.h>
using namespace std;

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1

/////////////////////////////////////////////////////////////////////////////////

// so this question is same as previous, here also we simply need to minimise the price (similar to minimising the effort) and the number of stops taken or length of path must be lesser than or equal to k, where source and destination are not included in path length

// int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {

//     if(flights.size() == 0) {
//         return -1;
//     }

//     // converting into adjacency list so that the problem is simplified to shortest distance between src and dest with path length excluding src and dst atmost k

//     vector<vector<pair<int,int>>> adj(n); // we are storing {from, weight} for each adj[to]

//     for(int i = 0; i < flights.size(); i++) {
//         adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
//     }

//     // now applying the Dijkstra but in the priority queue we also store the path length so that we discard if the path length becomes > k, but it does not play any role in determing the priority as we always pick the one with min cost

//     // we will store {cost, stops, node}

//     priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 

//     vector<int> minCost(n, INT_MAX);

//     pq.push({0, {0, src}});
//     minCost[src] = 0;

//     while(!pq.empty()) {

//         int cost = pq.top().first;
//         int stops = pq.top().second.first;
//         int node = pq.top().second.second;

//         pq.pop();

//         if(node == dst && stops <= k + 1) {
//             return cost;
//         }

//         if(stops >= k + 1) {
//             continue;
//         }

//         if(cost > minCost[node]) {
//             continue;
//         }

//         for(auto &neighbour : adj[node]) {

//             int adjNode = neighbour.first;
//             int weight = neighbour.second;

//             if(cost + weight < minCost[adjNode]) {
//                 minCost[adjNode] = cost + weight;
//                 pq.push({minCost[adjNode], {stops + 1, adjNode}});
//             }
//         }
//     }

//     return -1; // not possible
// }

//////////////////////////////////////////////////////////////////////////////////

// So here a simple dijkstra does not work here since

// If you prioritize cost (Standard Dijkstra)...
// As we discussed, this fails because Dijkstra is "greedy." It sees a cheap path with 2 stops and "finalizes" the node, permanently discarding a slightly more expensive path with 1 stop. But that expensive path might have been the only one capable of reaching the destination within the limit.

// How about we use a priority_queue prioritising stops instead of cost

// No, you should not use a Priority Queue where stops has higher preference than cost.Here is the breakdown of why that is a bad idea and why the simple Queue is the correct tool.1. If you prioritize stops...If you configure your Priority Queue to sort by {stops, cost, node}, the PQ will pop elements in this order:All paths with 0 stops.All paths with 1 stop.All paths with 2 stops....This is exactly how a normal Queue (BFS) works.A standard Queue inherently processes items in the order they were inserted (Level 0, then Level 1, etc.).Queue Complexity: 1$O(1)$ per push/pop.2Priority Queue Complexity: $O(\log N)$ per push/pop.

// only way dijkstra works here is by changing the state
// Required Dijkstra: minCost[node][stops] (Best cost to reach Node using exactly S stops)

// but This increases the graph size to $N \times K$ and uses much more memory.

// hence we prefer the queue approach (since PQ takes logN) and explore all paths with a check of stops <= k and then find the min cost through queue BFS which takes O(V.E) time similar to what we used in minEffort problem

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {

    // convert to adjacency list

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < flights.size(); i++) {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]}); // {from, weight}
    }

    queue<pair<int, pair<int,int>>> q; // {stops, cost, node}
    vector<int> minCost(n, INT_MAX);

    q.push({0, {0, src}});
    minCost[src] = 0;

    while(!q.empty()) {

        int stops = q.front().first;
        int cost = q.front().second.first;
        int node = q.front().second.second;

        q.pop();

        // if stops > k, then in the next iteration we would have more than k + 1 stops to be inserted in queue and we cant allow that

        if(stops > k) {
            continue; 
        }

        for(auto &neighbour : adj[node]) {

            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(cost + weight < minCost[adjNode]) {
                minCost[adjNode] = cost + weight;
                q.push({stops + 1, {minCost[adjNode], adjNode}});
            }
        }
    }

    if(minCost[dst] == INT_MAX) {
        return -1;
    }

    return minCost[dst];

} // O(E * k) time when we relax each edge for all k stops in the path and O(V + E) space for queue in worst case

int main() {
    
    return 0;
}