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

// to get the boundary traversal of a tree in anticlockwise fashion we must first get the root of the tree then the left boundary of tree excluding the leaf, then the leaf nodes and then the right boundary of the tree in reverse fashion excluding the leaf nodes and thus it will give us the entire boundary traversal of the tree in anticlockwise sense since we are going from root -> left -> leaf -> right (in reverse)

// for clockwise it would be root -> right -> leaft -> left (in reverse)

//////////////////////////////////////////////////////////////////////////////////////

// so we solve this problem by following exactly what it states

bool isLeaf(Node *root) {
    if(!root->left && !root->right) return true;
    return false;
}

void leftBoundary(Node *root, vector<int> &arr) {

    Node *rootLeft = root->left; // we have to start from root->left even though we have passed root

    while(rootLeft) {

        // insert if not leaf since we add leaf nodes separately

        if(!isLeaf(rootLeft)) {
            arr.push_back(rootLeft->data); 
        }

        // since left boundary we try to take left nodes only (as left as possible)

        if(rootLeft->left) {
            rootLeft = rootLeft->left; 
        } else {
            rootLeft = rootLeft->right; // take right if left nodes are exhausted
        }
    }
}

// here we are using preorder traversal using root left right for adding all leaves, any traversal would work that explores the left subtree first before right subtree, so inorder and postorder would also work since they also visit left subtree before right subtree

void addLeaves(Node *root, vector<int> &arr) {
   
    // we only add the leaf nodes when doing traversal since thats what we want, we dont want any internal nodes

    if(isLeaf(root)) { 
        arr.push_back(root->data);
        return;
    }

    // we are checking here that if root->left and right->right exists or not because if they dont do then no point in trying to call function for them as they cant be leaf node if they are nullptr 

    if(root->left) {
        addLeaves(root->left, arr); // check for left subtree
    }

    if(root->right) {
        addLeaves(root->right, arr); // check for right subtree
    }
}

// better way to write addLeaves which avoid this if else checks is to make the null pointer as the base case

void addLeavesBetter(Node *root, vector<int> &arr) {
    
    if(root == nullptr) {
        return;
    }

    if (isLeaf(root)) {
        arr.push_back(root->data);
        return;
    }

    // no need to check if children exists, the base case handles it

    addLeaves(root->left, arr);
    addLeaves(root->right, arr);
}

// also we cant use bfs to add the leaves since it explores level by level which means it will add a shallow right leaf first then adding a deep left leaf and this violates our order or adding leaves from left to right

// same procedure as for calculating leftBoundary

void rightBoundary(Node *root, vector<int> &arr) { 

    // we have to start from root->right even though we have passed root

    Node *rootRight = root->right;

    // since we travel from up to down (in tree you can only go down and not up) but we want right boundary in reverse fashion hence we use temp and later copy it in reverse order in our main array

    vector<int> temp; 

    while(rootRight) {

        if(!isLeaf(rootRight)) {
            temp.push_back(rootRight->data); // insert if not leaf
        }

        // since right boundary we try to take right nodes only (as right as possible)

        if(rootRight->right) {
            rootRight = rootRight->right;
        } else {
            rootRight = rootRight->left; // if right nodes exhausted then take left
        } 
    }

    // copy to main array in reverse order (so that we get right boundary in a bottom to up fashion)

    for(int i = temp.size() - 1; i >= 0; i--) {
        arr.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node *root) {

    if(!root) return {};

    vector<int> ans; 

    // adding the root separately, if it is not leaf since if its a leaf node then addLeaves would add it correctly and we shouldnt do it outside of that function 

    if(!isLeaf(root)) {
        ans.push_back(root->data); 
    }

    // adding the left boundary, we dont pass root->left but root instead

    leftBoundary(root, ans); 

    // adding the leaves

    addLeaves(root, ans); 

    // adding the right boundary, we dont pass root->right but root instead

    rightBoundary(root, ans); 

    return ans; 

} // O(N) time and O(N) space for temp array in right boundary and O(N) recursion stack space for addLeaves function, we are not actually traversing all nodes but in worst case we would

// only this order would change for clockwise nothing new

int main() {
    
    return 0;
}