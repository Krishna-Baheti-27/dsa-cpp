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

// same concept as in printNodes at distance K, in which we move radially outwards, the question is essentially asking us to find the distance of node which is located the farthest from given node
// so we here same as previously we actually have to find the distance dis of a node till the bfs queue is empty

void setParentPointers(Node *root, unordered_map<Node*,Node*> &mpp) {
    queue<Node*> q; // our bfs queue
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *node = q.front(); q.pop();
            if(node->left) {
                q.push(node->left);
                mpp[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
    }
}

// so here we have to apply bfs from the given target till we process all nodes and queue is empty, the max distance thus travelled would be the min time taken to burn the BT
int timeToBurn(Node *root, Node *target) {
    unordered_map<Node*,Node*> mpp;
    setParentPointers(root, mpp);
    unordered_map<Node*, bool> visited; 
    queue<Node*> q;

    q.push(target);
    visited[target] = true;
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        bool burnedSomethingOnThisLevel = false;
        for(int i = 0; i < size; i++) {
            Node *node = q.front(); q.pop();
            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
                burnedSomethingOnThisLevel = true;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
                burnedSomethingOnThisLevel = true;
            }
            if(mpp.find(node) != mpp.end() && !visited[mpp[node]]) {
                q.push(mpp[node]);
                visited[mpp[node]] = true;
                burnedSomethingOnThisLevel = true;
            }
        }
        // it may happen that on this level we didnt encounter any new node and all the nodes were already in the visited array and for that we check before incrementing time that did we burn something or not
        if(burnedSomethingOnThisLevel) {
            time++;
        }
    }
    return time;
    // another fix can be
    // That's why the fix is to count the number of levels the BFS runs and subtract one. If the BFS has L levels, it takes L-1 time steps to propagate through them.
}

int main() {
    
    return 0;
}