#include<bits/stdc++.h>
using namespace std;

// same as previous but here we will implement dijkstra using set 

// in the set if we are updating in the distance array and and distance is not INT_MAX which means someone else reached it before us so we can actually erase that from the set since we have a better one and thus reduce the total number iterations in the set which we cant do in priority queue

// but the deletion in set takes logN time so we are investing logN time ot reduce one iteration in the future so here a lot of factors come into play and we cannot certainly tell which implementation is better set or priority queue

/////////////////////////////////////////////////////////////////////////////////

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> &adj, int src) {

    set<pair<int,int>> st;
    vector<int> distance(v, INT_MAX);

    st.insert({0, src});
    distance[src] = 0;

    while(!st.empty()) {

        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        st.erase(it);

        for(auto &neighbour : adj[node]) {

            int adjNode = neighbour.first;   
            int weight = neighbour.second;

            if(dis + weight < distance[adjNode]) {

                // erase the entry of adjNode and distance[adjNode] if it has been visited before

                if(distance[adjNode] != INT_MAX) {
                    st.erase({distance[adjNode], adjNode});
                }

                distance[adjNode] = dis + weight;
                st.insert({distance[adjNode], adjNode});
            }
        }
    }

    return distance;

} // O(ElogV) time and O(V) space

//////////////////////////////////////////////////////////////////////////////////////

// the only advantage of set over PQ is just the memory which is O(V) for set and upto O(E) or O(V^2) for PQ but in PQ we apply optimisation of lazy dijkstra and hence it only processes shortest entry and avoids redundant entries with bigger distances so run time wise PQ wins big time

// and SPFA performs the worst which is O(VE) time or avg O(kE) time and space wise it is O(V) since we dont push the same node again in the queue by maitaining a visited, only after a node is popped we make its visited false and it is ready to be inserted again if lower distance found

// and if you dont use a visited then it is naive spfa or dijkstra using queue then it is worst in case of both time and space with space being exponential in some cases O(2^V)

int main() {
    
    return 0;
}