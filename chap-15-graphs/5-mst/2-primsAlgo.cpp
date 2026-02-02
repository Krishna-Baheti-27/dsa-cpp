#include<bits/stdc++.h>
using namespace std;

// helps us find the MST of the given graph

// the intuition is that we start from a node and put all the adjacents in the min heap and on next iteration we greedily choose the one having min edge weight amongst the nodes inserted and maintain a visited array to make sure we only inserting all the nodes only once and thus taking only min possible weights for all

////////////////////////////////////////////////////////////////////////////////////////

vector<pair<int,int>> spanningTree(int v, vector<vector<pair<int,int>>> &adj) {

    vector<pair<int,int>> ans; // to store the edges of our mst

    vector<bool> visited(v, false);

    // we will be storing {weight, node, parent}

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;   

    pq.push({0, {0, -1}}); // because no edge exists yet
    int sum = 0; // use long long since it may overflow

    while(!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if(!visited[node]) {

            if(parent != -1) {
                ans.push_back({node, parent});
            }

            // mark it visited only when we add it to the mst because we dont want to mark visited when inserting in PQ because we might have a min entry sitting in the PQ and we would want to take that instead of bigger and hence directly insert in PQ and finalize by marking visited only after popping from PQ

            visited[node] = true;
            sum += weight;

            for(auto &neighbour : adj[node]) {

                int adjNode = neighbour.first;
                int wt = neighbour.second;

                if(!visited[adjNode]) {
                    pq.push({wt, {adjNode, node}});
                }
            }
        }
    }

    // sum now stores the value of sum of edge weights of mst, and we dont need to maintain parent reference if only want the value of sum, PQ of {weight, node} would suffice

    return ans; // this are all the edges in our mst 

} // O(ElogV) or O(ElogE) time and O(V + E) or O(E) space in worst case since PQ might end up storing all the edges

// for dense graphs E = V^2 and hence logE = 2logV and hence O(ElogE) = O(ElogV)

// and here also we are only restricting the re processing of node already using visited but it doesnt mean that we cannot insert the same node multiple times in PQ
// In our C++ implementation (which is "Lazy Prim's"), we do not check if a node is already in the Priority Queue (PQ) before pushing. We only check if it has been popped and finalized (visited) so in worst case we can push every edge and hence size of PQ is O(E) and each time push pop costs O(logE) and hence O(ElogE)

// the same logic works in case of lazy dijkstra

int main() {
    
    return 0;
}