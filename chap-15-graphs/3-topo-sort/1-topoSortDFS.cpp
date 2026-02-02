#include<bits/stdc++.h>
using namespace std;

// it is only possible for a DAG (Directed Acyclic Graph), definition explains why only DAG
// Topo sort is the linear ordering of vertices such that if there is a edge between u and v then u appears before v in that ordering

/////////////////////////////////////////////////////////////////////////////////////////

// The intution for this algo is pretty easy we want to place u before v if there is edge between u -> v, we know that u will be traversed before v since thats how dfs works (we go in the absolute depth from the source so source would be traversed first) so instead we push them in stack when we are returning and hence u will sit on top of all nodes whose dfs have been completed as it will be the last function call to be returned and hence last push operation would be st.push(u) and the linear ordering will be followed

// once the dfs is done we simply pop out from the stack and store in our answer array

void dfsBrute(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {

    visited[node] = true;

    for(int adjNode : adj[node]) {
        if(!visited[adjNode]) {
            dfsBrute(node, visited, st, adj);
        }
    }

    st.push(node); // while returning push into the stack (backtracking step)
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
// O(2N) space for stack and visited and recursion stack space of O(N) in worst case

//////////////////////////////////////////////////////////////////////////////////

// in the optimal approach instead of storing in the stack we simply store in the vector and reverse it to obtain our answer

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
    
} // O(N) space for visited + O(N) recursion stack space
// O(N + E) time for directed acyclic graph for dfs and O(N / 2) time for reversal of array

int main() {
    
    return 0;
}