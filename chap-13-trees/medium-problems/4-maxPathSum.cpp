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

// path is a route connecting two different nodes of a binary tree
// The path sum of a path is the sum of the node's values in the path.
// a same node cannot occur twice in a path

// the naive approach would be to go through each node, and for every node calculate its path sum with every other node and thus find the max path sum for that node, this way find for everyone else and reture maxSum but very complicated to find the distance of every pair since we cant traverse up the tree and that would be O(N^2) time consuming also

//////////////////////////////////////////////////////////////////////////

// this is a much better solution using the concept of height and width(diameter) of binary tree
// what we use is => maxPathSum = node->data + maxSumLeft + maxSumRight
// and if we find the maximum of all such maxPathSum then we would have the maxPathSum of binary tree, but it is subject to condition that the node given is the curving point and maxSumLeft != 0 and maxSumRight != 0.

int maxPathHelperOptimal(Node *root, int &maxPathSum) {

    if(root == nullptr) return 0; // when no node, there is no path and hence maxPathSum = 0
    
    // ignore negative path sums, since they only make the answer worst and do not help in improving maxPathSum, hence for negative path sums we simply return 0
    // similar to kadane algo where we dont consider the sum < 0, since that would only hamper our max subarray sum 

    // return max possible sum from left subtree
    int leftSum = max(0,maxPathHelperOptimal(root->left, maxPathSum));

    // return max possible sum from right subtree
    int rightSum = max(0,maxPathHelperOptimal(root->right, maxPathSum));

    maxPathSum = max(maxPathSum, root->data + leftSum + rightSum); 
    // update maxPathSum, so we actually have the max possible path sum through particular node

    // here we return root->data + either leftSum or rightSum whichever is max since it has to be a straight extendable path downwards and only parent node for which we are calculating maxPathSum will form arch and hence we dont return root->data + leftSum + rightSum, if we return both leftSum + rightSum then how would we know which path to take for maxPathSum

   return root->data + max(leftSum, rightSum); 

} 

int maxPathSumOptimal(Node *root) {
    int maxPathSum = INT_MIN;
    maxPathHelperOptimal(root, maxPathSum);
    return maxPathSum;
} // O(N) time and O(N) space
 
int main() {
    
    return 0;
}