#include<bits/stdc++.h>
using namespace std;

// a graph is said to be BIPARTITE if you can color the entire graph using just 2 colors such that any two adjancent nodes do not have the same color

// using the above definition we can prove that all odd length cyclic graphs are not bipartite and rest any graph is a biparitite graph

// it was always clear that linear or non cyclic graphs will always be bipartite and the problem was for deciding for cyclic graphs and we can prove that even length cyclic graphs are bipartite and odd length cyclic graphs are non-bipartite

// but here when solving we are not using this mathematical conclusion but simply doing what the problem says (we go ahead and color each node till its possible, if not we return false), since calculating the length of the cycle would probably require a map to maintain from where did the cycle start, so we would simply use a map to satisfy both purposes and not a visited array, (we can also use map instead of array since we will have access in constant time since we know nodes would be from 0 to n - 1)

////////////////////////////////////////////////////////////////////

// lets solve this using DFS

// so what we do is we start from the starting node and a color (lets say 0) and then in the adjacency list we call the next node which has not been colored with color (color == -1), but if its alreaydy colored then we check if the color same as current color (0 in this case) if yes we return false that the graph cant be bipartite

// now this works for a particular component but for a graph havig multiple connected componenets we have to run a for loop and travel across all those 

bool dfsHelper(int node, int colorNode, vector<int> &color, vector<vector<int>> &graph) {
    
    color[node] = colorNode;

    for(int adjNode : graph[node]) {

        if(color[adjNode] == -1) {

            // if not visited then visit through dfs with a different color then current node's color and if that returns false then we return false and return early and no need to complete entire dfs

            if(dfsHelper(adjNode, 1 - colorNode, color, graph) == false) {
                return false;
            }

        } else if(color[adjNode] == colorNode) {

            // cannot be bipartite since the adjNode has already been colored and that too with the same color as our current color so we have two adjacent nodes having same color and hence non bipartite

            return false; 
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
            if(dfsHelper(i, 0, color, graph) == false) {
                return false;
            }
        } 

    }
    
    return true;
}

// O(N + 2E) time for DFS and O(N) space for color array and O(N) recursion stack space

//////////////////////////////////////////////////////////////////////////////////////

// this can also be done using BFS but DFS more intuitive

// so writing the bfs solution here

// we dont need to maintain the state of color here like we do in recursion (although we can also maitaining colorNode in dfs but using that is more intuitive), and we only store the nodes and using the color array we identify the colors to be used on adjacent nodes

bool bfsHelper(int start, vector<int> &color, vector<vector<int>> &graph) {

    queue<int> q; // to store node
    q.push(start); // for node start of the component we have 0 color
    color[start] = 0;

    while(!q.empty()) {
        
        int node = q.front();

        q.pop();

        for(int adjNode : graph[node]) {

            if(color[adjNode] == -1) {

                color[adjNode] = 1 - color[node];
                q.push(adjNode);

            } else if(color[adjNode] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartiteBfs(vector<vector<int>> &graph) {

    int v = graph.size();
    vector<int> color(v, -1);

    for(int i = 0; i < v; i++) {
        if(color[i] == -1) {
            if(bfsHelper(i, color, graph) == false) {
                return false;
            }
        }
    }

    return true;

} // O(N + 2E) time and O(2N) space for color array and queue 

int main() {
    
    return 0;
}