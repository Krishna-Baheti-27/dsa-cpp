#include<bits/stdc++.h>
using namespace std;

// Disjoint set is one of the most important data structures related to graphs

// it can help us find where the given two nodes are in the same component or not in constant time as opposed to O(N + E) timefor BFS/DFS

// it basically exposes two functionalities that are findParent() and Union() by size or rank

// it is primarily used with dynamic graphs which change their configurations which means they are changing at each step we might have question in any intermediary point and to answer that we will use Disjoint set

// Finding union by Rank

// rank is something which does not decrease and hence it cant be called height since even on path compression height may or may not change and we cant find that and hence we use rank

// parent stores the parent or ultimate parent of a node based on whether path compression has happened before

// the two nodes are said to be in same component if ultimate parent of u == ultimate parent of v, else we can use the union operation by rank to connect them 

// we always connect the smaller rank to larger rank when performing union by rank
// we do that to not increase the height since then finding ultimate parent would cost logN time (longer distance for the first time until path compression is done) hence we shrink the tree and time taken to find the parent

// and in the union by size we simply maintain the size of each component by the size of parent and its much more intuitive since size always grows upon union and again we follow the same logic of attaching the smaller size to larger size

// all the operations take O(4 * alpha) time which is as good as constant

// we only use one of union by rank or union by size to solve our problems

class DisjointSet {

    vector<int> rank, parent, size;

    public:

    DisjointSet(int n) {

        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v) {

        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);

        // if they belong to the same component then we dont need to do the union operation

        if(ultimateParentU == ultimateParentV) {
            return;
        }

        // when smaller gets attached to larger then no change in rank

        if(rank[ultimateParentU] < rank[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV; 
        } else if(rank[ultimateParentV] < rank[ultimateParentU]) {
            parent[ultimateParentV] = ultimateParentU;
        } else {

            // attach whereever you want, here we are attaching u to v and hence rank of v is bound to increase

            parent[ultimateParentU] = ultimateParentV;
            rank[ultimateParentV]++;
        }
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

int main() {
    
    return 0;
}