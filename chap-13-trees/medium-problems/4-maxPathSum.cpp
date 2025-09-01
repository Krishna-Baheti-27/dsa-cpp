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

// The path sum of a path is the sum of the node's values in the path.
// a node cannot occur twice in the same path

// the naive approach would be to go through each node, and for every node calculate its path sum with every other node and thus find the max path sum for that node, this way find for everyone else and reture maxSum but very complicated to find the distance of every pair and that would be O(N^N)

// this is a much better solution using the concept of height and width(diameter) of binary tree
// what we use is => maxPathSum = node->data + maxSumLeft + maxSumRight
// and if we find the maximum of all such maxPathSum then we would have the maxPathSum of binary tree
int maxPathHelper(Node *root, int &maxPathSum) {
    if(root == nullptr) return 0; // when no node, there is no path
    int leftSum = max(0,maxPathHelper(root->left, maxPathSum)); // ignore negative path sums, since they only make the answer worst and do not help in improving maxPathSum
    int rightSum = max(0,maxPathHelper(root->right, maxPathSum));
    maxPathSum = max(maxPathSum, root->data + leftSum + rightSum); // what we discussed
    return root->data + max(leftSum, rightSum); // indeed returning the maxLeftSum / maxRightSum
}

int maxPathSumOptimal(Node *root) {
    int maxPathSum = INT_MIN;
    maxPathHelper(root, maxPathSum);
    return maxPathSum;
}
 
int main() {
    
    return 0;
}