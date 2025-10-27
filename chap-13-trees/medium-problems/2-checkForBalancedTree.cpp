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

// balanced BT is tree such that for every node height(left subtree) - height(right subtree) = 1. take absolute value or difference of height(left) - height(right)

int height(Node *root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
} // root is considered at an height = 1

bool checkForBalancedTreeBrute(Node *root) {

    if(root == nullptr) return true; 
    // a tree having root as nullptr or a single node will always be balanced

    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    if(abs(heightLeft - heightRight) > 1) return false; 
    // check if balanced, if not return false right away else check recursively for left and right 

    bool checkLeft = checkForBalancedTreeBrute(root->left);
    if(!checkLeft) return false;

    bool checkRight = checkForBalancedTreeBrute(root->right);
    if(!checkRight) return false;

    // we checked for current node, left subtree and right subtree, if all are valid then return true
    return true; 

} // O(N^2) since for each node we are finding height of left and right so N * N time
// O(N) recursion stack space in worst case

///////////////////////////////////////////////////////////////////////////////

// se where we are taking extra time is in the step of finding left and right height
// how can we solve the problem, for that we need to know the left and right height and then only we can compare them by abs(left - right), but the thing is, after checking for this node whether its balanced or not we again have to check recursively for left and right subtree

// what if our height function which already traverse left and right is so that it returns us true or false about if the left and right subtree are balanced or not, this way we would be able to get both the height of left and right and also info about whether left and right subtree are balanced or not, this is killing two birds with same stone, but how to achieve that

// we make our function return -1, if left or right subtree is in balanced are return the true hegiht if they are balanced, thus we have both info, whether they are balanced or not and if balanced then what is their height

int balancedHelper(Node *root) {

    if(!root) return 0; // balanced and hence return height

    // now check for left and right subtree

    int leftCheck = balancedHelper(root->left);
    if(leftCheck == -1) return -1; // left is not balanced so we return -1
    int rightCheck = balancedHelper(root->right);
    if(rightCheck == -1) return -1;  // right is not balanced so we return -1

    // now we know both left and right subtree are balanced so leftCheck and rightCheck actually contain height of left and right subtree so now we check if current node is balanced or not

    if(abs(leftCheck - rightCheck) > 1) return -1; // current is not balanced so we return -1

    // now left subtree, right subtree and current node is balanced and according to our logic we should now return the height of this tree which is 1 + max(leftHeight, rightHeight) and we already now leftHeight = leftCheck, rightHeight = rightCheck

    return 1 + max(leftCheck, rightCheck);
} 

int checkForBalancedTreeOptimal(Node *root) {
    if(balancedHelper(root) == -1) return false;
    return true;
} // O(N) time and O(N) space

int main() {
    
    return 0;
}