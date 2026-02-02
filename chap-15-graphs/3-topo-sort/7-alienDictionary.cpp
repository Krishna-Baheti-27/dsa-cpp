#include <bits/stdc++.h>
using namespace std;

// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

//////////////////////////////////////////////////////////////////////////////////////

// so we are given the lexicographical ordering according to alien dictionary and we have to find the correct order to obey this ordering which is nothing but topo sort if you create a graph such that if b > a then there is an edge from b to a

vector<int> topoSort(int v, vector<vector<int>> &adj) {

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

    for(int i = 0; i < v; i++) {
        if(indegree[i] != 0) {
            return {};
        }
    }

    return topoSort;

} 

string findOrder(vector<string> &words) {

    vector<vector<int>> adj(26);

    for(int i = 0; i < words.size() - 1; i++) {

        int j;

        for(j = 0; j < min(words[i].length(), words[i + 1].length()); j++) {
            if(words[i][j] != words[i + 1][j]) {
                adj[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
            }
        }
    }

    vector<int> topo = topoSort(26, adj);

    if(topo.size() == 0) {
        return "";
    }

    string ans;

    for(int i = 0; i < topo.size(); i++) {
        ans += topo[i];
    }

    return ans;
}

int main() {
    
    return 0;
}