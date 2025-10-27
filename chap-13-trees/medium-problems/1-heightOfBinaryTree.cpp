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

int height(Node *root) {
    if(root == nullptr) return 0; // if no nodes then zero height, if a single node then 1 height
    return 1 + max(height(root->left), height(root->right)); 
    // this means 1 + max(from left or right subtree)
} // O(N) time and O(H) recursion stack space

int heightIterative(Node *root) {
    if(!root) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while(!q.empty()) {
        int size = q.size();
        height++;
        for(int i = 0; i < size; i++) { // traversing a level
            Node *node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return height;
} // O(N) time and O(N) space in worst case in case of full binary tree (since last level will have nearly n / 2 nodes)

int main() {
    
    return 0;
}