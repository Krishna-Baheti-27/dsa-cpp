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

// you have to find the min time taken to burn the binary tree completely starting from any give node, the nodes at distance 1 are burned in 1 unit of time so what is the min time taken tu burn all the nodes

//////////////////////////////////////////////////////////////////////////////////

// same concept as in printNodes at distance K, in which we move radially outwards, the question is essentially asking us to find the distance of node which is located the farthest from given node or we maintain a level variable intitially = 0 and for each iteration increae it by one till the queue is empty and in the end return the answer

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
        bool newNodesAdded = false;

        for(int i = 0; i < size; i++) {

            Node *node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
                newNodesAdded = true;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
                newNodesAdded = true;
            }
            if(mpp.find(node) != mpp.end() && !visited[mpp[node]]) {
                q.push(mpp[node]);
                visited[mpp[node]] = true;
                newNodesAdded = true;
            }
        }

        if(newNodesAdded) {
            time++;
        }

    }

    return time;
    
} // O(N) time and O(N) space

// it may happen that on this level we didnt encounter any new node and all the nodes were already in the visited array and for that we check before incrementing time that did we add any new level, if we did then only we increment since we know that time here is proportional to level

// at time 0, the target nodes starts burning
// at time 1, all nodes at distances one starts buring (left, right and parent)
// at time 2, all nodes at distance 2 start burning

// so if we dont add any new level or node then we dont increment time also, simple

// No Increment if Fire Doesn't Spread: You only increment the time when you successfully "burn" a new level of nodes. If you process a level of burning nodes but find no new, unburnt neighbors, it means the fire has reached every possible node (we have completely burn the entire tree). The process is over. Incrementing the time again would be incorrect because the fire didn't advance.


int main() {
    
    return 0;
}