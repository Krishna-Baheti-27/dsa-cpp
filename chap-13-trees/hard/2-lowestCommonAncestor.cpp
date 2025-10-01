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

bool rootToNodePathHelper(Node *root, Node *target, vector<Node*> &arr) {
    if(root == nullptr) return false;
    arr.push_back(root);
    if(root == target) {
        return true;
    }
    if(rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) return true;
    arr.pop_back();
    return false;
}

vector<Node*> rootToNodePath(Node *root, Node*target) {
    vector<Node*> res;
    if(!root) return res;
    rootToNodePathHelper(root, target, res);
    return res;
}

Node* lcaBrute(Node *root, Node *p, Node *q) {
    // we find the path of both p and q and then traverse both paths and find the last common ancestor and return it
    if(!root) return root;
    vector<Node*> pathRootP = rootToNodePath(root, p);
    vector<Node*> pathRootq = rootToNodePath(root, q);
    int n = min(pathRootP.size(), pathRootq.size());
    Node *lca = nullptr;
    for(int i = 0; i < n; i++) {
        if(pathRootP[i] == pathRootq[i]) {
            lca = pathRootP[i]; // update lca at each step
        } else break;
    } 
    return lca;
} // O(3N) time for three traversals and O(2N) space
 

// same technique as in root to node path, where we first go all the way till left unless we find root == p or q and, and then go right once left is null
Node* lcaOptimal(Node *root, Node *p, Node *q) {
    if(root == nullptr || root == p || root == q) return root; // we have three options to return
    // in case it is not null but has value other than p or q in that case we again try to find p and q by going in left and right subtree of current node
    Node* leftFind = lcaOptimal(root->left, p, q);
    Node *rightFind = lcaOptimal(root->right, p, q);
    // this also handles the case where both leftFind and rightFind return nullptr
    if(!leftFind) return rightFind; 
    else if(!rightFind) return leftFind;
    else return root; // both left and right are not null and this is our answer for current lca and hence instead of returning leftFind or rightFind we return the root
}

int main() {
    
    return 0;
}