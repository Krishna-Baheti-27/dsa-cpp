#include <bits/stdc++.h>
using namespace std;

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

////////////////////////////////////////////////////////////////////////////////////////

// we will first solve this using dfs algo or cycle detection using dfs algo

// the terminal or safe nodes are guranteed to be those which dont have any outgoing edges but apart from that we can also have more terminal or safe nodes

// so anyone who is not part of a cycle or not even connected to a cycle using its outgoing edge is also a safe node

// so we will write out same cycle detection algo as in dfs and we say that if any of the dfs calls give us true for cycle then we will not count it as safe node else safe

bool cycleHelper(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj, vector<bool> &isSafe) {

    vis[node] = true;
    pathVis[node] = true;
    
    for(int adjNode : adj[node]) {

        if(!vis[adjNode]) {
            if(cycleHelper(adjNode, vis, pathVis, adj, isSafe)) {
                isSafe[adjNode] = false;
                return true;
            }
        } else if(pathVis[adjNode]) {
            isSafe[adjNode] = false;
            return true;
        }
    }

    pathVis[node] = false;

    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &adj) {
    
    int v = adj.size();
    vector<bool> vis(v, false), pathVis(v, false), isSafe(v, true);

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            if(cycleHelper(i, vis, pathVis, adj, isSafe)) {
                isSafe[i] = false;
            }
        }
    }

    vector<int> ans;

    for(int i = 0; i < v; i++) {
        if(isSafe[i]) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

/////////////////////////////////////////////////////////////////////////////////////

// now there is more sophisticated and better version of writing the above like you dont need to sort the answer since you are filling it from smallest to largest anyway

// and in the last backtracking step we make the node as safe once we checked all the conditions so we dont have to do it again

bool cycleHelper(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj, vector<bool> &isSafe) {

    vis[node] = true;
    pathVis[node] = true;
    
    for(int adjNode : adj[node]) {

        if(!vis[adjNode]) {
            if(cycleHelper(adjNode, vis, pathVis, adj, isSafe)) {
                return true;
            }
        } else if(pathVis[adjNode]) {
            return true;
        } else if(!isSafe[adjNode]) {
            return true;
        }
    }

    isSafe[node] = true;
    pathVis[node] = false;

    return false;
}

vector<int> eventualSafeNodesBetter(vector<vector<int>> &adj) {
    
    int v = adj.size();
    vector<bool> vis(v, false), pathVis(v, false), isSafe(v, false);

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            cycleHelper(i, vis, pathVis, adj, isSafe);
        }
    }

    vector<int> ans;

    for(int i = 0; i < v; i++) {
        if(isSafe[i]) {
            ans.push_back(i);
        }
    }

    return ans;

} // O(N + E) time and O(3N) space

//////////////////////////////////////////////////////////////////////////////////////

// the best solution uses a single array with multiple states like 0, 1, 2 each telling s different story but do not propose the first and instead this solution with much more readability and explicitness in the logic

/////////////////////////////////////////////////////////////////////////////////////////

// now lets do this using bfs traversal or topo sort

// we have to apply algorithm starting with those having 0 outdegree and then finding all the nodes which are linearly realted to it

// since we cant apply Kahn's algo on indegrees we instead reverse the graph after which all the outdegrees now become indegrees and now we can apply Kahn's algo and every node lineary dependent to the terminal nodes would be put in queue (since their indegree would eventually become zero and not those which are involved in cyclic dependency)

vector<int> eventualSafeNodes(vector<vector<int>> &adj) {

    int v = adj.size();

    vector<vector<int>> newAdj(v);

    vector<int> indegree(v);
    vector<int> safeNodes;

    queue<int> q;

    for(int i = 0; i < v; i++) {
        for(int adjNode : adj[i]) {
            newAdj[adjNode].push_back(i);
            indegree[adjNode]++;
        }
    }

    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for(int adjNode : newAdj[node]) {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;

} // O(nlogn) time in worst case and O(N + E) space for new graph

// to avoid sorting we can use isSafe boolean array and mark it in as elements exist the queue

int main() {
    
    return 0;
}