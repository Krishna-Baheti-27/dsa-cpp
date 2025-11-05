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

// literally do any traversal of your choice and if both are exactly identical then the trees are same else not, here we are doing preorder traversal, that is root, left, right

////////////////////////////////////////////////////////////////////////////////////

bool areSameTrees(Node *root1, Node *root2) {
    
    if(root1 == nullptr && root2 == nullptr) return true; // both are same as they are null

    if(root1 && root2) {

        if(root1->data != root2->data) {
            return false; // roots dont have same value
        }

        if(areSameTrees(root1->left, root2->left) == false) {
            return false; // they dont have same left subtrees
        } 
        
        if(areSameTrees(root1->right, root2->right) == false) {
            return false; // they dont have same right subtrees
        }

        return true; // if everything satisfies then they are same or identical
    } 

    // this hits means either root1 == null and root2 != null and vice-versa which means they are not same as one of them exists and other is simply null which doesnt make sense to be same tree

    return false; 

} // O(N) time and O(N) space

/////////////////////////////////////////////////////////////////////////////

// a more elegant way to write the same above conditions

bool areSameTreesReadable(Node *root1, Node *root2) {

    if(!root1 || !root2) return (root1 == root2);

    return root1->data == root2->data && areSameTreesReadable(root1->left, root2->left) && areSameTreesReadable(root1->right, root2->right);

} // O(N) time and O(N) space

int main() {
    
    return 0;
}