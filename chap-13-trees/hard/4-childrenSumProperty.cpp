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

// we given a binary tree and we have to modify it such that if satisfies children sum property, that is sum of left child + sum of right child must be equal to sum of parent for all nodes, and for that we can increment the value of any node by any number of times and there is no constraint to that but we can not decrement we can only increment so keep that in mind

////////////////////////////////////////////////////////////////////////////////////

// simple rule, if sum of left child and right child for a given node is greater than node->data, then you will have to update node->data = node->left->data + node->right->data but we would do that while returning because even if you update right now but you would go for below nodes and those might change your answer as they might change value of node->left and node->right and hence we update while returning, else if they are lesser then we update the value of both left and right child to the value of current node and then again go left and right 


void treeWithChildrenSumOptimal(Node *root) {

    if(!root) return;

    int childSum = 0;

    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum < root->data) { // for lesser update left and right child to have parent's value
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    } 
    
    // we handle the > case while returning

    treeWithChildrenSumOptimal(root->left); // do same for left subtree
    treeWithChildrenSumOptimal(root->right); // for right

    // when we comeback we enforce the child sum property by 

    int total = 0;

    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;

    // if root is a left node then it would already be obeying children sum property but it its not then we make it equal to total so that it does 
    if(root->left || root->right) root->data = total;

} // O(N) time and O(H) recursion stack space

int main() {
    
    return 0;
}