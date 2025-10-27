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

bool isLeaf(Node *root) {
    if(!root->left && !root->right) return true;
    return false;
}

void leftBoundary(Node *root, vector<int> &arr) {

    Node *rootLeft = root->left;

    while(rootLeft) {

        // insert if not leaf since we add leaf nodes separately
        if(!isLeaf(rootLeft)) arr.push_back(rootLeft->data); 

        // since left boundary we try to take left nodes only (as left as possible)
        if(rootLeft->left) rootLeft = rootLeft->left; 
        else rootLeft = rootLeft->right; // take right if left nodes are exhausted
    }
}

// preorder traversal using root left right and adding all leaves, any traversal would work for addin the leaves that explores the left subtree first before right subtree, so inorder and postorder would also work

void addLeaves(Node *root, vector<int> &arr) {
   
    if(isLeaf(root)) { // we only add the leaf nodes when doing preorder traversal
        arr.push_back(root->data);
        return;
    }

    if(root->left) addLeaves(root->left, arr); // check for left subtree
    if(root->right) addLeaves(root->right, arr); // check for right subtree
}

void rightBoundary(Node *root, vector<int> &arr) { // same as for calculating leftBoundary

    Node *rootRight = root->right;

    vector<int> temp; // since we travel from up to down but we want right boundary in reverse fashion hence we use temp and later copy it in reverse order in our main array

    while(rootRight) {

        if(!isLeaf(rootRight)) temp.push_back(rootRight->data); // isnert if not leaf

        // since rightt boundary we try to take right nodes only (as right as possible)
        if(rootRight->right) rootRight = rootRight->right;
        else rootRight = rootRight->left; // if right nodes exhausted then take left
    }

    for(int i = temp.size() - 1; i >= 0; i--) {
        arr.push_back(temp[i]); // copy to main array in reverse order
    }
}

vector<int> boundaryTraversal(Node *root) {
    if(!root) return {};

    vector<int> ans; 

    if(!isLeaf(root)) ans.push_back(root->data); // adding the root separately, if is not leaf since if its a leaf node then addLeaves would add it correctly

    leftBoundary(root, ans); // adding the left boundary
    addLeaves(root, ans); // adding the leaves
    rightBoundary(root, ans); // adding the right boundary

    return ans; // return our traversal
} // O(N) time and O(H) space, we are not actually traversing all nodes but in worst case we would

// only this order would change for clockwise nothing new

int main() {
    
    return 0;
}