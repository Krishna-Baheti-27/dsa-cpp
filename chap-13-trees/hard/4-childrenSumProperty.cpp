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

Node *treeWithChildrenSumBrute(Node *root) {
    if(!root) return root;
    if(root->left->data + root->right->data < root->data) {
        
    } else if(root->left->data + root->right->data > root->data) {
        root->data = root->left->data + root->right->data;
    }
}

void treeWithChildrenSumOptimal(Node *root) {
    if(!root) return;
    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;
    if(childSum < root->data) {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    treeWithChildrenSumOptimal(root->left); // we go left
    treeWithChildrenSumOptimal(root->right); // we go right
    // when we comeback we enforce the child sum property by 
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total; // if atleast the root is not leaf node and atleast once child exists in on either left or right then we enforce the children sum property else not
}

int main() {
    
    return 0;
}