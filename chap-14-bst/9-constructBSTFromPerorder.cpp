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

// the naive approach is simply inserting the nodes one by one as we traverse the preorder array, we know first element is the root, and all subsequent elements are inserted in a way to they follow property of BST, insertion takes approx O(n) for n nodes that is O(n^2) time, best time O(nlogn)

Node *insertInBSTIterative(Node *root, int val) {

    if(!root) {
        root = new Node(val);
        return root; // handling the edge case of inserting the root itself
    }

    Node *trueRoot = root; // preserve the root since it will be lost in traversal

    while(true) {

        // so insert in the right

        if(val > root->data) {

            if(root->right) {

                // traverse further only if right exists
                root = root->right;

            } else {
                
                // if root->right is null, then insert the node to root->right and break
                root->right = new Node(val);
                break;
            }

        } else {  // (we wont have any case of root->data == val)

            if(root->left) {

                // traverse further only if left exists
                root = root->left; 

            } else { 

                root->left = new Node(val);
                break;
            } 
        }
    }

    return trueRoot;

} // O(logN) time and O(1) space

Node *bstFromPreorderBrute(vector<int> &preorder) {
    
    Node *root = nullptr;

    for(int i = 0; i < preorder.size(); i++) {
        root = insertInBSTIterative(root, preorder[i]);
    }

    return root;

} // O(n^2) time and O(n) recursion stack space (not considering the space to return answer)

////////////////////////////////////////////////////////////////////////////////////////

// the better approach is where we sort the preorder to get the inorder and then using preorder + inorder we can construct a BT in O(n) which will be a unique BST
// O(NlogN + N) time and O(N) space

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

Node *bstFromPreorderBetter(vector<int> &preorder) {
   
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    
    return buildTreeOptimal(preorder, inorder);

} // O(nlogn) time and O(2n) space

////////////////////////////////////////////////////////////////////////////////////

// the most optimal way is to use property of bst, similar to what we did in the question to check if the tree is BT or BST, we maintained the range that each node must obey, similarly here we maintain the upper bound that the node must be less than upper bound to be insert else we return and then backtracking takes care of it

// when we go left the upper bound is current nodes value since all the values in the left must be strictly lesser than that and when we go right the upper bound is the previously maintained upper bound (since it must be lesser than the parent from which we went right)

Node *optimalHelper(int &idx, vector<int> &preorder, int upper) {

    if(idx == preorder.size()) {
        return nullptr;
    } 

    if(preorder[idx] >= upper) {
        return nullptr;
    }

    Node *root = new Node(preorder[idx]);

    idx++;

    root->left = optimalHelper(idx, preorder, root->data);
    root->right = optimalHelper(idx, preorder, upper);

    return root;
}

Node *bstFromPreorderOptimal(vector<int> &preorder) {

    int idx = 0;
    return optimalHelper(idx, preorder, INT_MAX);

} // O(3N) time in worst case (since each node maybe visited atmax 3 times) and O(N) recursion stack space 

////////////////////////////////////////////////////////////////////////////////////

// using this we can say that even in standard preorder traversal where we simply print the values there also in worst case we going 3 times hence O(3N) but we ignore it and say it as O(N)

int main() {
    
    return 0;
}