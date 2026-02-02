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

// the height or depth of the binary tree is defined as the number of max levels down from the root where the root is considered to be at level 1

////////////////////////////////////////////////////////////////////////////////////////

int height(Node *root) {

    if(root == nullptr) return 0; // if no nodes then zero height, if a single node then 1 height

    // so height = 1 + max(from left or right subtree)

    return 1 + max(height(root->left), height(root->right)); 
    
} // O(N) time and O(N) recursion stack space

int heightAnotherWayToWrite(Node *root) {

    if(!root) return 0;

    int leftHeight = heightAnotherWayToWrite(root->left);
    int rightHeight = heightAnotherWayToWrite(root->right);

    return 1 + max(leftHeight, rightHeight);

    // here 1 means the height of current root + height of whichever of left or right subtree which is maximum

} // O(N) time and O(N) recursion stack space

int heightIterative(Node *root) {

    if(!root) return 0;

    queue<Node*> q;
    q.push(root);

    int height = 0;

    while(!q.empty()) {

        int size = q.size();

        height++; // incrementing the height as we began new level

        // traversing a level

        for(int i = 0; i < size; i++) {

            Node *node = q.front(); q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return height;

} // O(N) time and O(N) space in worst case

// in case of fully filled binary tree (since last level will have nearly n / 2 nodes) and hence O(N/2) or O(N) space

int main() {
    
    return 0;
}