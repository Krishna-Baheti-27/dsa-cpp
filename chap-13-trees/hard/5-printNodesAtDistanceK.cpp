#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order

// all the node->data are unique, so we can use a map to store the parent of a node
// now to travel a distance of k in the tree in radially outward direction you need to have parent pointers also because how else can we traverse upwards, we would be able to traverse only downwards using left and right pointers

// the code is sort of difficult to understand so have patience
// step 1 => set up parent pointers using map
// step 2 => perform bfs traversal from the given target by inserting nodes in queue and maintaining a visited hashh until the radial distance == k, at that point the nodes in queue are the nodes at distance of K from target

// set parent pointers using any traversal here we are using BFS
Node* setParentPointers(Node *root, unordered_map<Node*,Node*> &mpp) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *node = q.front(); q.pop();
            if(node->left) {
                q.push(node->left);
                mpp[node->left] = node; // the parent of node->left is node 
            }
            if(node->right) {
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
    }
    return root;
}

vector<int> nodesAtDistanceK(Node *root, Node *target, int k) {
    unordered_map<Node*, Node*> mpp; // to maintain child parent relation 
    Node *newRoot = setParentPointers(root, mpp);
    // this is the newRoot having child parent pointers
    queue<Node*> q;
    q.push(target);
    // now we will do BFS up down from this target node initially starting from dis = 1 till dis = k
    unordered_map<Node*, int> visited;
    visited[target]++;
    int dis = 0;
    while(dis < k) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *node = q.front(); q.pop();
            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left]++;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right]++;
            }
            if(mpp.find(node) != mpp.end() && !visited[mpp[node]]) {
                q.push(mpp[node]);
                visited[mpp[node]]++;
            }
        }
        dis++;
    }
    // will break out when dis == k, so now all the nodes in our queue are actually the nodes at a radial distance of k and hence simply pop them and add in the answer
    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

// NOW THIS SOLUTION CAN BE IMPROVED A LOT SINCE WE KNOW THAT ALL NODES ARE UNIQUE SO INSTEAD OF STORING ADDRESSED WE CAN SIMPLY STORE THEIR INTEGER VALUES WHICH WILL SAVE US LOT OF SPACE

int main() {
    
    return 0;
}