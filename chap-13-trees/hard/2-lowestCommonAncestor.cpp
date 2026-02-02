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

/////////////////////////////////////////////////////////////////////////////////////////

// in the brute force we find the path of both p and q from the root and then traverse both paths and find the last common ancestor or element and return it (since that is the definition of lowest common ancestor)

bool rootToNodePathHelper(Node *root, Node *target, vector<Node*> &arr) {

    if(root == nullptr) {
        return false;
    }

    arr.push_back(root);

    if(root == target || rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) {
        return true;
    }

    arr.pop_back();

    return false;
}

vector<Node*> rootToNodePath(Node *root, Node*target) {

    vector<Node*> res;

    rootToNodePathHelper(root, target, res);

    return res;
}

Node* lcaBrute(Node *root, Node *p, Node *q) {

    vector<Node*> pathRootP = rootToNodePath(root, p);
    vector<Node*> pathRootq = rootToNodePath(root, q);

    int n = min(pathRootP.size(), pathRootq.size());

    Node *lca = nullptr;

    for(int i = 0; i < n; i++) {

        // update lca at each step and if they dont match then return 

        if(pathRootP[i] == pathRootq[i]) {
            lca = pathRootP[i]; 
        } else {
            break;
        }
    } 

    return lca;

} // O(3N) time for three traversals and O(2N) space ignoring O(N) recursion stack space
 
///////////////////////////////////////////////////////////////////////////

// but instead of calculating the path from root to node separately for both p and q and then traversing the path to find the last common node, we can simply compute the path from root to node for both p and q simultaneously on the fly and the first node from which we felt that the path is getting diverged and wont remain common anymore, that node is LCA

// so we continue till both nodes are either present in left subtree or right subtree and but as soon as they get diverged like one on left and one on right or vice versa we return that node to be answer

// so we our solution is as soon as we hit either p or q or null we return that, this means we are searching for our nodes p, q
// we recursively search for p and q in left and right subtree
// if both left and right return non null values means divergence case (p in left, q in right or vice versa) and hence current root is lca (last common node)
// if left is non null means right is null means, both p and q on left so we return left
// else right has to be non null and we return that

Node *lcaOptimal(Node *root, Node *p, Node *q) {

    // found node which we were searching or null means no node

    if(root == nullptr || root == p || root == q) {
        return root; 
    }

    // we need to search and know about both left and right subtrees before we make a decision
    
    Node *leftLCA = lcaOptimal(root->left, p, q);
    Node *rightLCA = lcaOptimal(root->right, p, q);

    // as soon as we find divergence we return else continue which means we will reach the last common node then only we will have divergence possible

    // the current node is LCA because from both left and right we have non null values which means p and q are in different subtrees and hence current node is our LCA

    if(leftLCA != nullptr && rightLCA != nullptr) {
        return root; 
    }

    // from left we got null means both p and q on right and hence return that

    if(!leftLCA) {
        return rightLCA;
    }

    // from right we got null which means both p and q on left and hence return that

    return leftLCA;

} // O(N) time and O(N) space

///////////////////////////////////////////////////////////////////////////////////////

// we also have another intermediate approach of finding lca in which for each function call we find if p and q are in the same subtree and if yes then recurse down there and if no then we return current node as lca

// this is O(N^2) because for each node we searching for remaining - 1 times that is

// N + (N - 1) + (N - 2) + .. 1 => O(N^2) time

// and hence we kill two birds by one stone by making our lca function do both searching and finding the lca, similar to how we check if tree is balanced or not

/////////////////////////////////////////////////////////////////////////////////////////

// we cant write iterative version here without a stack since we need to simulate backtracking as in recursion

Node* lowestCommonAncestorIterative(Node* root, Node* p, Node* q) {
    // Stack for Iterative Traversal
    stack<Node*> st;
    
    // Map to store parent pointers: parent[node] = its_parent
    unordered_map<Node*, Node*> parent;

    st.push(root);
    parent[root] = nullptr; // Root has no parent

    // 1. Iterate until we have found BOTH p and q
    while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
        
        Node* node = st.top();
        st.pop();

        if (node->left) {
            parent[node->left] = node; // Record parent
            st.push(node->left);
        }
        
        if (node->right) {
            parent[node->right] = node; // Record parent
            st.push(node->right);
        }
    }

    // 2. Create a set of all ancestors of P
    unordered_set<Node*> ancestors;
    while (p != nullptr) {
        ancestors.insert(p);
        p = parent[p]; // Move up using the map
    }

    // 3. Travel up from Q until we hit the first common ancestor
    while (ancestors.find(q) == ancestors.end()) {
        q = parent[q]; // Move up
    }

    return q;
}

int main() {
    
    return 0;
}