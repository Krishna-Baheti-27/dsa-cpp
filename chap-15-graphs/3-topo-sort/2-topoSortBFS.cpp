#include<bits/stdc++.h>
using namespace std;

// This is also known as Kahn's Algorithm, which is simply the algo to find the topo sort in DAG using the BFS traversal

/////////////////////////////////////////////////////////////////////////////////////

// here use something known as an indegree array which stores the indegree of all the nodes, the nodes having indegree == 0 must be placed at the start of topoSort since indegree == 0 means there is no incoming edge to them which means there is only outgoing edge from them and hence they should be placed first as by definition u -> v means u before v in that linear ordering

// and there will always be intially a min of 1 nodes for which indegree == 0, that is by the definition of DAG

// of so initially we put all nodes having indegree == 0 in the queue then we pop them one by one, add them to our answer and then decrease the indegree of all nodes associated or adjacent with them by 1, as soon as indegree of any nodes becomes 0, put it in the queue, continue this process till queue is empty

// now how to find the indegree of all nodes, its by traversing through the adjacency list if you have a edge u -> v this means indegree[v]++

vector<int> topoSort(int v, vector<int> adj[]) {

    vector<int> indegree(v, 0);
    queue<int> q; // queue for bfs
    vector<int> topoSort;

    // calculate the indegree of all nodes, if there is an edge from u -> v then indegree of v++

    for(int i = 0; i < v; i++) {
        for(int adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }
    
    // insert all nodes with indegree = 0 in the queue then apply multisource bfs for this nodes having indegree == 0 and always there will be min of one node having indegree == 0

    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {

        int node = q.front();
        q.pop(); 

        topoSort.push_back(node);
        
        for(int adjNode : adj[node]) {

            indegree[adjNode]--;
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    return topoSort;

} // O(N + E) time for indegree + O(N) for insertion in queue + O(N + E) for traversal 
// O(2N) space for indgree + visited (not considering the space to return answer)

// The intuition behind the Kahn's algo

// 1. The "Prerequisite" Analogy : 
// Imagine the graph edges are prerequisites. An edge U to V means "You must finish U before you can start V."Indegree represents the number of unmet prerequisites.If Node A has indegree = 3, it means there are 3 other tasks that must finish before A can start.Indegree 0 represents a task that is "Ready to Execute." It has no prerequisites (or all of them are already done).

// 2. The Algorithm: "Peeling the Onion" : 
// Kahn's algorithm is essentially a simulation of completing tasks in order.Find "Ready" Tasks: At the very beginning, the only tasks you can possibly start are the ones with indegree == 0 (no prereqs).Execute & Remove: When you pick a node from the queue and add it to your topoSort list, you are saying, "I have finished this task."Unlock Neighbors: Once you finish a task (let's say Task A), it no longer blocks its neighbors.If you have an edge $A \to B$, completing A satisfies one of B's requirements.Mathematically, this is indegree[B]--.Check for New Unlocks: If indegree[B] drops to 0, it means all of B's prerequisites are now met. B is now "Ready to Execute," so you push it into the queue.

int main() {
    
    return 0;
}