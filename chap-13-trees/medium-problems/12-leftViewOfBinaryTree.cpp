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

// same logic as right view only consider the left nodes first (simple preorder traversal)

///////////////////////////////////////////////////////////////////////////////////////

vector<int> leftViewIterative(Node *root) {

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

            // this is the first element for that level, and for left view we only have to add the first element of that level

            if(i == 0) {
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

////////////////////////////////////////////////////////////////////////////////////

void helper(Node *root, int level, vector<int> &ds) {

    if(!root) {
        return;
    }

    // this makes sure that you add into the vector only when that level was reach for the first time and not after backtracking or returning

    if(level == ds.size()) {
        ds.push_back(root->data);
    }

    helper(root->left, level + 1, ds);

    helper(root->right, level + 1, ds);
}

vector<int> leftViewRecursive(Node *root) {

    vector<int> ans;

    helper(root, 0, ans);

    return ans;

} // O(n) time and O(n) space

int main() {
    
    return 0;
}