#include<bits/stdc++.h>
using namespace std;

// This is also known as Kahn's Algorithm, which is simply the algo to find the topo sort if DAG using the BFS traversal

/////////////////////////////////////////////////////////////////////////////////////

// here use somthing known as an indegree array which stores the indegree of all the nodes, the nodes having indegree == 0 must be placed at the start of topoSort since indegree == 0 means there is no incoming edge to them which means there is only outgoig edge from them and hence they should be places first as by definition u -> v means u before v in that linear ordering

// and there will always be intially a min of 1 nodes for which indegree == 0, that is by the definition of DAG

// of so initially we put all nodes having indegree == 0 in the queue then we pop them one by one, add them to our answer and then decrease the indegree of all nodes associated or adjacent with them by 1, as soon as indegree of any nodes becomes 0, put it in the queue, continue this process till queue is empty

// now how to find the indegree of all nodes, its by traversing through the adjacency list if you have a edge u -> v this means indegree[v]++

vector<int> topoSort(int v, vector<int> adj[]) {

    vector<int> indegree(v, 0);
    queue<int> q; // queue for bfs
    vector<int> topoSort;

    for(int i = 0; i < v; i++) {
        for(int adjNode : adj[v]) {
            indegree[adjNode]++;
        }
    }
    
    for(int i = 0; i < v; i++) {
        if(indegree[v] == 0) q.push(v);
    }

    while(!q.empty()) {

        int node = q.front();
        q.pop(); 

        topoSort.push_back(node);
        
        for(int adjNode : adj[node]) {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) q.push(adjNode);
        }
    }

    return topoSort;
} // O(N + E) time for indegree + O(N) for insertion in queue + O(N + E) for traversal 
// O(2N) space for indgree + visited (not considering the space to return answer)

int main() {
    
    return 0;
}