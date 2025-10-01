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

bool rootToNodePathHelper(Node *root, Node *target, vector<int> &arr) {
    if(!root) return false; // did not found
    arr.push_back(root->data);
    if(root == target) return true; // found the node 
    if(rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) {
        return true; 
        // if any one of left or right subtrees return true means we have found the target and hence return true;
    }
    arr.pop_back(); 
    // since the target was not found on the left or right subtree which means that this node is not present in the path from root to target and hence we initially inserted it becuase it was assumed it was present but since its not present we remove it

    return false; // not found on this path (both left and right subtree hence return false and look for different paths)
}

vector<int> rootToNodePath(Node *root, Node *target) {
    vector<int> res;
    rootToNodePathHelper(root, target, res);
    return res;
}

int main() {
    
    return 0;
}