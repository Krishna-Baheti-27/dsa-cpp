#include<bits/stdc++.h>
using namespace std;

// a graph is said to be BIPARTITE if you can color the entire graph using juat 2 colors such that any two adjancent nodes do not have the same color

// using the above definition we can prove that all odd length cyclic graphs are not bipartite and rest any graph is a biparitite graph

////////////////////////////////////////////////////////////////////

// lets solve this using DFS

// so what we do is we start from the starting node and a color (lets say 0) and then in the adjacency list we call the next node which has not been colored with color (1), but if its alreaydy colored then we check if the color same as current color (0 in this case) if yes we return false that the graph cant be bipartite

// now this works for a particular component but for a graph havig multiple connected componenets we have to run a for loop and travel across all those 

bool dfsHelper(int node, int colorNode, vector<int> &color, vector<vector<int>> &graph) {
    
    color[node] = colorNode;

    for(int adjNode : graph[node]) {

        if(color[adjNode] == -1) {
            // if not visited then visit through dfs
            if(dfsHelper(adjNode, 1 - color[node], color, graph) == false) return false;
        } else if(color[adjNode] == colorNode) {
            return false; // cannot be bipartite
        }
    }

    // checking for all adjacent nodes and everybody returned true and hence return true for this componenet

    return true; 
}

bool isBipartite(vector<vector<int>> &graph) { // we are given the adjacency list

    int n = graph.size();
    vector<int> color(n, -1); // since this is 0 based graph

    for(int i = 0; i < n; i++) { // to travel across all connected components

        // if componenet not visited then visit
        // if any of the component returns false then return false right away, else travel to next componet by virtue of color == -1 for not visited

        if(color[i] == -1) { 
            if(dfsHelper(i, 0, color, graph) == false) return false;
        } 

    }
    
    return true;
}

// O(N + 2E) time for DFS and O(N) space for color array and O(N) recursion stack space

//////////////////////////////////////////////////////////////////////////////////////

// this can also be done using BFS but DFS more intuitive

int main() {
    
    return 0;
}