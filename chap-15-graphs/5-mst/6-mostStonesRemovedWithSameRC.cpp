#include<bits/stdc++.h>
using namespace std;

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed

////////////////////////////////////////////////////////////////////////////////////

// if you again see here, we have n nodes at the given locations of [x,y] and we can remove the stone if it has same row or col as another stone that has not already been removed

// so here again the graph is dynamic and changing at each step as we remove stones and hence we use Disjoint set data structure

// if we assume the stone to be nodes in a graph then the stones having either same row or column can be connected together as a same component, and the number of stones which we can remove from each component = component size - 1 (since there would be no stone left to remove the last node in component)

// so total number of stones removed = sum of all stones removed from each component
// ans = number of stones - number of components (pretty obvious to prove this)

// but what to treat as nodes in our disjoint set 

// so we will treat an entire row as node and similarly an entire column as a node
// so 0 to rows - 1 will represent the nodes of rows in disjoint set and rows to rows + cols - 1 as nodes of columns in disjoint set

// or columns as simply col + rows (where col starts from 0 to number of columns - 1)

class DisjointSet {

    vector<int> parent, size;

    public:

    DisjointSet(int n) {

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {

        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        // if they belong to the same component then we dont need to do the union operation

        if(ultimateParentU == ultimateParentV) {
            return;
        }

        // again the smaller size gets attached to larger size but the else if and else block is same so we just write the other case to simplify the logic

        if(size[ultimateParentU] < size[ultimateParentV]) {

            size[ultimateParentV] += size[ultimateParentU];
            parent[ultimateParentU] = ultimateParentV;

        } else {
            size[ultimateParentU] += size[ultimateParentV];
            parent[ultimateParentV] = ultimateParentU;
        }
    }
};

int removeStones(vector<vector<int>> &stones) {

    int n = stones.size();

    int maxRow = 0;
    int maxCol = 0;

    for(int i = 0; i < n; i++) {
        maxRow = max(maxRow, stones[i][0]);
        maxCol = max(maxCol, stones[i][1]);
    }

    DisjointSet ds(maxRow + maxCol + 1); // require +1 because of zeroes
    unordered_map<int,bool> uniqueNodes; // to count the unique nodes using which we will have idea of components

    for(int i = 0; i < n; i++) {

        int row = stones[i][0];
        int col = stones[i][1] + maxRow + 1;

        ds.unionBySize(row, col);
        uniqueNodes[row] = true;
        uniqueNodes[col] = true;

    }

    // now count the number of components

    int components = 0;

    for(auto &node : uniqueNodes) {
        if(ds.findUltimateParent(node.first) == node.first) {
            components++;
        }
    }

    return n - components;

} // O(n) time in worst case where n = no. of stones, O(maxrow + maxcol) space

int main() {
    
    return 0;
}