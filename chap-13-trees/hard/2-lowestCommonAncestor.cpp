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

// the lowest common ancestor of two nodes is the lowest or deepest common node after which no common node is found in the path from root to respective nodes

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

// we find the path of both p and q and then traverse both paths and find the last common ancestor and return it (since that is the definition of lowest common ancestor)

Node* lcaBrute(Node *root, Node *p, Node *q) {
    
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
} // O(3N) time for three traversals and O(2N) space ignoring O(N) recursion stack space
 
///////////////////////////////////////////////////////////////////////////

// but instead of calculating the path from root to node separately for both p and q and then traversing the path to find the last common node, we can simply compute the path from root to node for both p and q simultaneously on the fly and the node from which we felt that the path is getting diverged and wont remain common anymore, the last such node is our LCA

// so we continue till both nodes are either present in left subtree or right subtree and but as soon as they get diverged like one on left and one on right or vice versa we return that node to be answer

// so we our solution is as soon as we hit either p or q or null we return that, this means we are searching for our nodes p, q
// we recursively search for p and q in left and right subtree
// if both left and right return non null values means divergence case (p in left, q in right or vice versa) and hence current root is lca (last common node)
// if left is non null means right is null means, both p and q on left so we return left
// else right has to be non null and we return that

Node *lcaOptimal(Node *root, Node *p, Node *q) {

    // found node which we were searching
    if(root == nullptr || root == p || root == q) return root; 

    // we need to search and know about both left and right subtrees before we make a decision
    
    Node *leftLCA = lcaOptimal(root->left, p, q);
    Node *rightLCA = lcaOptimal(root->right, p, q);

    // as soon as we find divergence we return else continue which means we will reach the last common node then only we will have divergence possible

    if(leftLCA != nullptr && rightLCA != nullptr) return root; // root is our lca
    else if(leftLCA != nullptr) return leftLCA; // search on left for lca
    return rightLCA; // search on right

} // O(N) time and O(N) space


int main() {
    
    return 0;
}