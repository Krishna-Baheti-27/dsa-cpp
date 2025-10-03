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

// the brute force would involve traversing across the tree and then inserting all the nodes in the container and then sorting that vector and returning the Kth element from first
// O(N) + O(NlogN) time and O(N) space for container

// the better approach would be to store the entire inorder traversal of the bst in a container and then return the Kth element from that container since the inorder traversal of a binary tree is always sorted
// O(N) time and O(N) space for container

// here is the optimal approach
// we use a counter and we increment it each time we visit a node when count == k we have our answer

void inorderHelper(Node *root, int k, int &count, int &result) {
    if(!root || count >= k) return;
    inorderHelper(root->left, k, count, result); // left
    count++; // we came on root of this node after left so count it as a visit
    if(count == k) {
        result = root->data;
        return;
    } // we visited exactly k element, so this node is our answer
    inorderHelper(root->right, k, count, result); // right
}

int kthSmallestBetter(Node *root, int k) {
    int count = 0, result = root->data;
    inorderHelper(root, k, count, result);
    return result;
} // O(N) time and O(N) recursion stack space

// To find the kth largest, first do any traversal and count the number of nodes, let it be N
// so kth largest is same as N- k th smallest

// Even more optimised is using the morris traversal, so O(N) time and O(1) space and everything remains same just add this counter logic

int main() {
    
    return 0;
}