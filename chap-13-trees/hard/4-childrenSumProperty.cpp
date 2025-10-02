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

// simple rule, if sum of left child and right child for a given node is greater than node->data, then you will have to update node->data = node->left->data + node->right->data but we would do that while returning , else if they are lesser then we update the value of both left and right child to the value of current node and then again go left and right and when returning we set root->data = left->data + right->data


void treeWithChildrenSumOptimal(Node *root) {
    if(!root) return;
    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;
    if(childSum < root->data) {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    // we handle the > case while returning
    treeWithChildrenSumOptimal(root->left); // we go left
    treeWithChildrenSumOptimal(root->right); // we go right
    // when we comeback we enforce the child sum property by 
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total; // if atleast the root is not leaf node and atleast once child exists in on either left or right then we enforce the children sum property else not as for leaft node it already obeys the children sum property
} // O(N) time and O(H) recursion stack space

int main() {
    
    return 0;
}