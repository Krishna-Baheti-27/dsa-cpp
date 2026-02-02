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

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

//////////////////////////////////////////////////////////////////////////////////////

vector<int> rightViewIterative(Node *root) {

    if(!root) {
        return {};
    }

    queue<Node*> q; // (node, level)
    q.push(root); // 0th level

    vector<int> ans;

    while(!q.empty()) {

        int size = q.size();

        for(int i = 0; i < size; i++) {

            Node *node = q.front(); q.pop();

            // this is the last element for that level, and for right view we only have to add the last element of that level

            if(i == size - 1) {
                ans.push_back(node->data);
            }

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }
    }

    return ans;

} // O(n) time and O(n) space

//////////////////////////////////////////////////////////////////////////////////

// using the reverse preorder traversal or preorder in which we visit right before left of Root Right left in place of Root Left right, because we have to traverse right most nodes first

void helper(Node *root, int level, vector<int> &ds) {

    if(!root) {
        return;
    }

    if(level == ds.size()) {
        ds.push_back(root->data);
    }

    // this makes sure that you add into the vector only when that level was reach for the first time and not after backtracking or returning, and since we visit the rightmost nodes first we are bound to get in the right view only those nodes to be added 

    helper(root->right, level + 1, ds); 

    // we did right first since we want the rightmost node for a particular level in rightView and now right got exhausted hence we go left because it may happen the our right most node lies on the left subtree of our root

    helper(root->left, level + 1, ds);
}

vector<int> rightViewRecursive(Node *root) {

    vector<int> ans;
    
    helper(root, 0, ans);

    return ans;

} // O(n) time and O(n) space

int main() {
    
    return 0;
}