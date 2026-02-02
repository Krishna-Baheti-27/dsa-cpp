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

// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// again they have unique values

//////////////////////////////////////////////////////////////////////////////////////

// this question is very similar to the last one just a little change but concept is same

Node *buildTreeBruteHelper(int start, int end, vector<int> &inorder, vector<int> &postorder, int &idx) {

    if(start > end) {
        return nullptr;
    }

    Node *root = new Node(postorder[idx]);

    idx--;

    int i = start;

    while(i <= end) {
        if(inorder[i] == root->data) {
            break;
        }
        i++;
    }

    // here we build right first then left since the idx iterates from the back and hence we would encounter right subtree first

    root->right = buildTreeBruteHelper(i + 1, end, inorder, postorder, idx);
    root->left = buildTreeBruteHelper(start, i - 1, inorder, postorder, idx);

    return root;

} // O(N^2) time and O(N) recursion stack space

Node *buildTreeBrute(vector<int> &inorder, vector<int> &postorder) {
    int idx = inorder.size() - 1;
    return buildTreeBruteHelper(0, inorder.size() - 1, inorder, postorder, idx);
}

////////////////////////////////////////////////////////////////////////////////////

// here order does not matter since we are not using global idx and have range for each

Node *buildTreeOptimalHelper(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, unordered_map<int,int> &mpp) {

    if(inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }

    Node *root = new Node(postorder[postEnd]);

    int rootIdx = mpp[root->data];
    int nodesLeft = rootIdx - inStart;

    root->left = buildTreeOptimalHelper(inStart, rootIdx - 1, inorder, postStart, postStart + nodesLeft - 1, postorder, mpp);

    root->right = buildTreeOptimalHelper(rootIdx + 1, inEnd, inorder, postStart + nodesLeft, postEnd - 1, postorder, mpp);

    return root;
}

Node *buildTreeOptimal(vector<int> &inorder, vector<int> &postorder) {

    unordered_map<int,int> mpp;

    for(int i = 0; i < inorder.size(); i++) {
        mpp[inorder[i]] = i;
    }

    return buildTreeOptimalHelper(0, inorder.size() - 1, inorder, 0, postorder.size() - 1, postorder, mpp);

} // O(N) time and space

int main() {
    
    return 0;
}