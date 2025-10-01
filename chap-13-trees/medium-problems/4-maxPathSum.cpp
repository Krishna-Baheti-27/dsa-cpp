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
// a node cannot occur twice in the same path

// the naive approach would be to go through each node, and for every node calculate its path sum with every other node and thus find the max path sum for that node, this way find for everyone else and reture maxSum but very complicated to find the distance of every pair and that would be O(N^2)

// this is a much better solution using the concept of height and width(diameter) of binary tree
// what we use is => maxPathSum = node->data + maxSumLeft + maxSumRight
// and if we find the maximum of all such maxPathSum then we would have the maxPathSum of binary tree, but it is subject to condition that the node given is the curving point and maxSumLeft != 0 and maxSumRight != 0.
int maxPathHelper(Node *root, int &maxPathSum) {
    if(root == nullptr) return 0; // when no node, there is no path and hence maxPathSum = 0
    
    // ignore negative path sums, since they only make the answer worst and do not help in improving maxPathSum, hence for negative path sums we simply return 0
    // similar to kadane algo where we dont consider the sum < 0, since that would only hamper our max subarray sum 
    int leftSum = max(0,maxPathHelper(root->left, maxPathSum)); 
    int rightSum = max(0,maxPathHelper(root->right, maxPathSum));
    maxPathSum = max(maxPathSum, root->data + leftSum + rightSum); 
    // here we are actually calculating the sum in that path and comparing it wiht maxPathSum to check if we have new max path sum

    // so this line tells that in our function we simply return the path having maxPathSum and real magic lies in maxPathSum variables which stores any new max path sum found
    return root->data + max(leftSum, rightSum); 
    // indeed returning the maxLeftSum / maxRightSum
    // the last line really tells which path to take to get the maxSum
}

int maxPathSumOptimal(Node *root) {
    int maxPathSum = INT_MIN;
    maxPathHelper(root, maxPathSum);
    return maxPathSum;
}
 
int main() {
    
    return 0;
}