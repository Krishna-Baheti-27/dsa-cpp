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
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
} // root is considered at an height = 1

bool checkForBalancedTreeBrute(Node *root) {
    if(root == nullptr) return true; // a tree having root as nullptr or a single node will always be balanced
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    if(abs(heightLeft - heightRight) > 1) return false;
    // now check recursively for all left and right subtrees
    bool left = checkForBalancedTreeBrute(root->left);
    bool right = checkForBalancedTreeBrute(root->right);
    if(!left || !right) return false; // if any of the left or right subtrees is not balanced then our answer is false
    return true; // else true
} // O(N) for traversal but each time we are finding height of left and right subtree and hence O(N) there
// so total O(N^2)



// here we are tweaking the height function to return -1 if the tree is not balanced and return the actual height if the tree is balanced, we are returning actual height for balanced since we want to calculate abs(lh - rh) to decide whether tree is balanced or not
int heightTweaked(Node *root) {
    if(root == nullptr) return 0;
    int heightLeft = heightTweaked(root->left);
    int heighRight = heightTweaked(root->right);
    if(heighRight == -1 || heightLeft == -1) return -1; // then also not balanced, if any one or both from left and right subtree are returning -1
    if(abs(heighRight - heightLeft) > 1) return -1; // not balanced
    return 1 + max(heightTweaked(root->left), heightTweaked(root->right)); 
}

int checkForBalancedTreeOptimal(Node *root) {
    if(heightTweaked(root) == -1) return false;
    return true;
}

int main() {
    
    return 0;
}