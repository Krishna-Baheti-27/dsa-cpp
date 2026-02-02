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

//////////////////////////////////////////////////////////////////////////////////////////

// the naive approach would be to go through each node, and for every node calculate its path sum with every other node and thus find the max path sum for that node, this way find for everyone else and reture maxSum but very complicated to find the distance of every pair since we cant traverse up the tree and that would be O(N^2) time consuming also

/////////////////////////////////////////////////////////////////////////////////////////

// this is a much better solution using the concept of height and width(diameter) of binary tree
// what we use is => maxPathSum = node->data + maxSumLeft + maxSumRight
// and if we find the maximum of all such maxPathSum then we would have the maxPathSum of binary tree, but it is subject to condition that the node given is the curving point and maxSumLeft != 0 and maxSumRight != 0.

// ok so what do we mean the parent must form a arch and then only apply this formula

// Every node's helper function does TWO jobs:

// Job 1 (The Return Value): Calculate the best "straight" path sum that starts at the current root and goes downwards. This path can only include the root and one of its children (either left or right, whichever is greater).

// This is the line: return root->data + max(maxLeftSum, maxRightSum);

// We return this value so that the parent node can use it to build its own straight path.

// Job 2 (The Side Effect): Calculate the best "arch" path sum that has the current root as its highest point (the "curving point"). This path can include the root, its left child's path, and its right child's path.

// This is the line: maxPathSum = max(maxPathSum, root->data + maxLeftSum + maxRightSum);

// This value is a candidate for the final answer. It cannot be returned to the parent, because a path can't fork. If you returned this "arch" to the parent, it would create a "Y" shape, which isn't a valid path.

int maxPathHelperOptimal(Node *root, int &maxPathSum) {

    if(root == nullptr) return 0; // when no node, there is no path and hence maxPathSum = 0
    
    // ignore negative path sums, since they only make the answer worst and do not help in improving maxPathSum, hence for negative path sums we simply return 0 and stop our path then and there since no point going in that path it would reduce our current maxLeftSum or maxRightSum
    // similar to kadane algo where we dont consider the sum < 0, since that would only hamper our max subarray sum 

    // return max possible sum from left subtree

    int maxLeftSum = max(0,maxPathHelperOptimal(root->left, maxPathSum));

    // return max possible sum from right subtree

    int maxRightSum = max(0,maxPathHelperOptimal(root->right, maxPathSum));

    // update maxPathSum, so we actually have the max possible path sum through particular node which according to our formula is node->data + max sum from left + max possible from right

    maxPathSum = max(maxPathSum, root->data + maxLeftSum + maxRightSum); 
    
    // here we return root->data + either leftSum or rightSum whichever is max since it has to be a straight extendable path downwards and only parent node for which we are calculating maxPathSum will form arch and hence we dont return root->data + leftSum + rightSum, if we return both leftSum + rightSum then how would we know which path to take for maxPathSum

   return root->data + max(maxLeftSum, maxRightSum); 

} 

int maxPathSumOptimal(Node *root) {

    int maxPathSum = INT_MIN;

    maxPathHelperOptimal(root, maxPathSum);

    return maxPathSum;

} // O(N) time and O(N) space

/////////////////////////////////////////////////////////////////////////////////////

// we cant use bfs here because it is starting from level 0 we have no idea whats happening below and hence dfs is better (preferably postorder like in here where we have info from both left and right subtree and then compute our answer)
 
int main() {
    
    return 0;
}