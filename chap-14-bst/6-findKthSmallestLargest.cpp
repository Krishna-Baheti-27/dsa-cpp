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

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree (which means return the (k - 1)th index element from the sorted array)

/////////////////////////////////////////////////////////////////////////////////////////

// the brute force would involve traversing across the tree and then inserting all the nodes in the container and then sorting that vector and returning the Kth element from beginning
// O(N) + O(NlogN) time and O(N) space for container

/////////////////////////////////////////////////////////////////////////////////////////

// the better approach would be to store the entire inorder traversal of the bst in a container and then return the Kth element from that container since the inorder traversal of a binary tree is always sorted
// this is the property of bst that inorder would always be sorted 
// O(N) time and O(N) space for container

//////////////////////////////////////////////////////////////////////////////////////////

// here is the optimal approach
// we use a counter and we increment it each time we visit a node when count == k we have our answer which means the (k - 1)th visited node is our answer from 0 based indexing

void inorderHelper(Node *root, int k, int &count, int &result) {

    if(!root || count >= k) {
        return;
    }

    inorderHelper(root->left, k, count, result); // go left

    // we came on root of this node after left so count it as a visit

    count++; 

    // we visited exactly k element, so this node is our answer

    if(count == k) {
        result = root->data;
        return;
    } 

    inorderHelper(root->right, k, count, result); // right
}

int kthSmallestBetter(Node *root, int k) {

    int count = 0, result = root->data;

    inorderHelper(root, k, count, result);

    return result;

} // O(N) time and O(N) recursion stack space

//////////////////////////////////////////////////////////////////////////////////////

// we can do this purely recursively without the need to maintain the result as reference

int kthSmallestMoreBetterHelper(Node *root, int &k) {

    if(!root) {
        return -1;
    }

    int leftCheck = kthSmallestMoreBetterHelper(root->left, k);
    
    if(leftCheck != -1) {
        return leftCheck;
    }

    k--;

    if(k == 0) {
        return root->data;
    }

    return kthSmallestMoreBetterHelper(root->right, k);
}

int kthSmallestMoreBetter(Node *root, int k) {

    return kthSmallestMoreBetterHelper(root, k);

} // O(N) time and space

///////////////////////////////////////////////////////////////////////////////////////

// Even more optimised is using the morris traversal, so O(N) time and O(1) space and everything remains same just add this counter logic

// here we check as soon as we increment count because once we do increment count after that we move away from the curr node and hence if count == k we can return the answer immediately but leaves the tree with loops and doesnt get accepted on leetcode and hence simply store the answer

int kthSmallestOptimal(Node *root, int k) {

    int count = 0;

    Node *curr = root;

    int ans = -1;

    while(curr) {

        if(curr->left == nullptr) {

            count++;

            // check if count == k before moving away

            if(count == k) {
                ans = curr->data;
            }

            curr = curr->right;

        } else {

            Node *prev = curr->left;

            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;

            } else {

                prev->right = nullptr;
                count++;

                if(count == k) {
                    ans = curr->data;
                }

                curr = curr->right;
            }
        }
    }

    return ans;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////////

// To find the kth largest, first do any traversal and count the number of nodes, let it be N
// so kth largest is same as (N - k)th smallest

int main() {
    
    return 0;
}