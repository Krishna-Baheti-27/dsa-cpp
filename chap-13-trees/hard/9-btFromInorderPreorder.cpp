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

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// here every node in preorder and inorder has unique value

////////////////////////////////////////////////////////////////////////////////////////



Node* solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx) {

    if(start > end) {
        return nullptr;
    }

    Node *root = new Node(preorder[idx]);

    int i = start;

    while(i <= end) {
        if(inorder[i] == root->data) {
            break;
        }
        i++;
    }

    idx++;

    root->left = solve(preorder, inorder, start, i - 1, idx);
    root->right = solve(preorder, inorder, i + 1, end, idx);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    int n = preorder.size();
    
    int idx = 0;
    return solve(preorder, inorder, 0, n - 1, idx);

} // O(N^2) time for skewed trees due to linear scan and O(N) recursion stack space

/////////////////////////////////////////////////////////////////////////////////////

// so how does this work

// we first store or hash the entire inorder array so that we can know the index of any value in constant time

// using this we determine the index of root and from that the nodes on the left subtree and the new preorder for left is from preStart + 1 to preStart + nodesLeft (take exactly that many nodes) and the new inorder for left is inStart to rootIdx - 1

// similarly to construct the right subtree we need right preorder and inorder, the right preorder is from preStart + nodesLeft + 1 (right after where left preorder ends) and ends at preEnd and right inorder is from rootIdx + 1 (right of root in inorder) to inEnd

// thats it just construct the tree and return root

Node *buildTreeOptimalHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mpp) {

    if(preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    Node *root = new Node(preorder[preStart]);

    int rootIdx = mpp[root->data];
    int nodesLeft = rootIdx - inStart; // on left subtree

    root->left = buildTreeOptimalHelper(preorder, preStart + 1, preStart + nodesLeft, inorder, inStart, rootIdx - 1, mpp);

    root->right = buildTreeOptimalHelper(preorder, preStart + nodesLeft + 1, preEnd, inorder, rootIdx + 1, inEnd, mpp);

    return root;
}

Node *buildTreeOptimal(vector<int> &preorder, vector<int> &inorder) {

    unordered_map<int,int> mpp;

    for(int i = 0; i < inorder.size(); i++) {
        mpp[inorder[i]] = i;
    }

    return buildTreeOptimalHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    
} // O(N) time and O(2N) space for map and recursion

int main() {
    
    return 0;
}