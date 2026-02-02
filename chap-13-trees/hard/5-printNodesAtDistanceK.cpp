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

//////////////////////////////////////////////////////////////////////////////

// here we will use level order traversal or BFS to go radially outward from each node level by level initially level == 0, we are at the same node, level == 1, all the nodes that are at a radial distance of 1 and so on we increase it till we reach K thus covering all nodes at distance K as they would be placed in queue at that time

// now to travel a distance of k in the tree in radially outward direction you need to have parent pointers also because how else can we traverse upwards, we would be able to traverse only downwards using left and right pointers
// all the node->data are unique, so we can use a map to store the parent of a node, we will be using unordered_map since we dont need the nodes in any particular order

// the code is sort of difficult to understand so have patience
// step 1 => set up parent pointers using map
// step 2 => perform bfs traversal from the given target by inserting nodes in queue and maintaining a visited hashh until the radial distance == k, at that point the nodes in queue are the nodes at distance of K from target

// This is extremely similar to what we do in graphs in BFS 

// set parent pointers using any traversal here we are using BFS

void setParentPointers(Node *root, unordered_map<Node*,Node*> &mpp) {

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        int size = q.size();

        for(int i = 0; i < size; i++) {

            Node *node = q.front(); q.pop();

            // the parent of node->left is node 

            if(node->left) {
                q.push(node->left);
                mpp[node->left] = node; 
            }

            // the parent of node->right is node

            if(node->right) {
                q.push(node->right);
                mpp[node->right] = node; 
            }
        }
    }

} // O(N) time to mark all parent pointers 

vector<int> nodesAtDistanceK(Node *root, Node *target, int k) {

    // to maintain child parent relation, we make mpp[node] now store the location of parent of node

    unordered_map<Node*, Node*> mpp; 
    setParentPointers(root, mpp);

    // now we will do BFS from target from level == 0 to level == k

    queue<Node*> q;
    q.push(target); 
    
    // very important so we know where to go now

    unordered_map<Node*, bool> visited; 
    visited[target] = true;

    int dis = 0;

    while(dis < k) {

        int size = q.size();

        for(int i = 0; i < size; i++) {

            Node *node = q.front(); 
            q.pop();

            // visiting left child

            if(node->left && !visited[node->left]) { 
                q.push(node->left);
                visited[node->left] = true;
            }

            // visiting right child
            
            if(node->right && !visited[node->right]) { 
                q.push(node->right);
                visited[node->right] = true;
            }

            // visiting parent

            if(mpp.find(node) != mpp.end() && !visited[mpp[node]]) { 
                q.push(mpp[node]);
                visited[mpp[node]] = true;
            }
        }

        dis++; 

        // now after first iteration we went from level 0 to level 1, since all nodes in queue now are at a distance of 1, similarly after k iterations we would have all nodes in queue at distance k and then we would stop right then and there and simply add them to answer

    }

    // will terminate loop when dis == k, so now all the nodes in our queue are actually the nodes at a radial distance of k and hence simply pop them and add in the answer

    vector<int> ans;

    while(!q.empty()) {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;

} // O(2N) time since O(N) in setting parent pointers and O(N) for traversing nodes at distance k in worst case and O(3N) space for queue and map and visited array

/////////////////////////////////////////////////////////////////////////////////////

// we can also solve this using the dfs traversal and that would save us from extra memory of map and visited array and would only take O(H) recursion stack space

// complete this approach when you have time

class Solution {
    vector<int> result;

    // Helper: Adds nodes at distance 'k' downwards from 'node'
    void addSubtreeNodes(Node* node, int k) {
        if (!node || k < 0) return;
        
        // If distance is 0, we found a node!
        if (k == 0) {
            result.push_back(node->data);
            return;
        }

        addSubtreeNodes(node->left, k - 1);
        addSubtreeNodes(node->right, k - 1);
    }

    // Main Recursive Function
    // Returns distance of target from 'root', or -1 if target not found
    int solve(Node* root, Node* target, int k) {
        if (!root) return -1;

        // Case 1: We found the target
        if (root == target) {
            addSubtreeNodes(root, k); // Look strictly downwards
            return 0; // Distance from target to itself is 0
        }

        // Case 2: Target is in the Left Subtree
        int dl = solve(root->left, target, k);
        if (dl != -1) {
            // Check current ancestor distance
            if (dl + 1 == k) {
                result.push_back(root->data);
            } else {
                // Target is in Left, so we look in Right subtree
                // Remaining distance = K - (distance to ancestor) - 1 (to step into right child)
                addSubtreeNodes(root->right, k - dl - 2);
            }
            return dl + 1; // Return distance to parent
        }

        // Case 3: Target is in the Right Subtree
        int dr = solve(root->right, target, k);
        if (dr != -1) {
            if (dr + 1 == k) {
                result.push_back(root->data);
            } else {
                // Target is in Right, so we look in Left subtree
                addSubtreeNodes(root->left, k - dr - 2);
            }
            return dr + 1;
        }

        return -1; // Target not found in this branch
    }

public:
    vector<int> distanceK(Node* root, Node* target, int k) {
        result.clear();
        solve(root, target, k);
        return result;
    }
};
// Time: O(N), Space: O(H) recursion stack

int main() {
    
    return 0;
}