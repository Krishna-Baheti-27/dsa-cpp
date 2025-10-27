#include<bits/stdc++.h>
using namespace std;

// it is only possible for a DAG (Directed Acyclic Graph), definition explains why only DAG
// Topo sort is the linear ordering of vertices such that if there is a edge between u and v then u appears before v in that ordering

/////////////////////////////////////////////////////////////////////////////////////////

// The intution for this algo is pretty easy we want to place u before v if there is edge between u -> v, we know that u will be traversed after v since thats how dfs works so instead we push them in stack so that when returing u will sit on top of all nodes whose dfs have been completed and the linear ordering will be followed

// so for implementing it using DFS we use a stack and before returing the dfs call we insert the node in the stack and once the traversal in over we pop out one by one from the stack and store it in the answer 

void dfsBrute(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {

    visited[node] = true;

    for(int adjNode : adj[node]) {
        if(!visited[adjNode]) {
            dfsBrute(node, visited, st, adj);
        }
    }

    st.push(node); // while returning push into the stack
}

vector<int> topoSortBrute(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);
    stack<int> st;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfsBrute(i, visited, st, adj);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
} // O(N + E) time for traversal + O(N) time for popping from stack
// O(2N) space for stack and visited ignoring recursion stack space of O(N) in worst case

////////////////////////////////////////////////////////////////////////////////

void dfsOptimal(int i, vector<bool> &visited, vector<int> &ans, vector<int> adj[]) {

    visited[i] = true; // mark as visited

    for(auto adjNode : adj[i]) {
        if(!visited[adjNode]) {
            dfsOptimal(adjNode, visited, ans, adj);
        }
    }
    ans.push_back(i); // before returning add it to answer (or stack)
}

vector<int> topoSortOptimal(int v, vector<int> adj[]) {

    vector<bool> visited(v, false);
    vector<int> ans;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfsOptimal(i, visited, ans, adj);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
} // O(N) space for visited (ignoring the recursion stack space and space for returning answer)
// O(N + E) time for directed acyclic graph for dfs and O(N / 2) time in last for reversal


int main() {
    
    return 0;
}