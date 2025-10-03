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

Node *findRightMost(Node *root) {
    while(root->right) root = root->right;
    return root; 
}

// but some edge cases are there
Node *deleteHelper(Node *nodeToDelete) {
    
    // Case 1:
    // if the nodeToDelete has neither left nor right then simply attach parent to nullptr
    if(!nodeToDelete->left && !nodeToDelete->right) return nullptr;

    // Case 2:
    // if the nodeToDelete doesnt have a left then simply attach the parent to its right
    if(!nodeToDelete->left) return nodeToDelete->right; 

    // Case 3:
    // if the nodeToDelete doesnt have a right then simply attach the parent to its left
    if(!nodeToDelete->right) return nodeToDelete->left; 

    // Case 4:
    // if both left and right exists then, rightMost node of nodeToDelete->left subtree right should point to noteToDelete->right
    Node *rightMostChild = findRightMost(nodeToDelete->left); 
    rightMostChild->right = nodeToDelete->right; // vvip step

    // now return the nodeToDelete->left node which will be connected to parent depending on left or right subtree, we have successfully modified all the links
    return nodeToDelete->left; 
}

Node *deleteInBST(Node *root, int key) {
    if(!root) return root; // we cant delete since there is no node to delete

    if(root->data == key) {
        // here we want to delete the root itself
        Node *toDelete = root;
        root = deleteHelper(root); // would return the new Node
        delete toDelete; // delete old root
        return root;
    }

    // we now search for node to delete, basically the parent of node to delete since we want to mainatain links and we cannot traverse up the tree

    Node *parent = root;
    while(parent) {
        if(parent->data > key) {
            // found the node to be deleted
            if(parent->left && parent->left->data == key) {
    
                Node *toDelete = parent->left; // now we know the node to delete
                // make the necessary change in links
                parent->left = deleteHelper(toDelete); // now simply connect the parent

                delete toDelete; // remove that node
                break; // since we are done no need to traverse whole tree

            } else {
                parent = parent->left; // try to get to the node to be deleted
            } 
        } else {
            // found the node to be deleted
            if(parent->right && parent->right->data == key) {
                Node *toDelete = parent->right;
                // do our modification
                parent->right = deleteHelper(parent->right);

                delete toDelete; // remove that node
                break;

            } else {
                parent = parent->right; // try to get to the node to be deleted
            }
        }
    }

    return root; // return the root of the updated tree
} // O(logN) time and O(1) space for iterative version

// The above method does not ensure that tree remains in logn height, instead its a just method to change the links
// the recursive method actually deleted in tree recursively maintaining the logn height


/////////////////////////////////////////////////////////////////////////////////

// The recursive version is more easier to understand,but does take O(logN) recursion stack space

// So there are 3 cases in total : 
// 1) the node to be deleted doesnt have any child, then simply remove it and make parent point to  nullptr
// 2) the node to be deleted has only a left or right child then simply attach the parent to the only child present
// 3) the node to be deleted has both left and right child
// then we have two options:
// first is find the min in right subtree of node to be deleted and then copy its value in node to be deleted, and then recursively delete the duplicate node in right subtree
// second is find the max in left subtree of node to de deleted and then copy its value in node to deleted, and then recursively delete the duplicate node in left subtree


Node *findMin(Node *root) {
    while(root && root->left) root = root->left;
    return root;
}

Node* deleteInBSTRecursive(Node *root, int key) {
    if(!root) return root; 
    if(root->data < key) root->right = deleteInBSTRecursive(root->right, key);
    else if(root->data > key) root->left = deleteInBSTRecursive(root->left, key);
    else {
        // we found the node to be deleted

        if(root->left == nullptr && root->right == nullptr) { // no child case
            delete root;
            root = nullptr;
        } else if(root->left == nullptr) { // only right child
            Node *temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == nullptr) { // only left child
            Node *temp = root;
            root = root->left;
            delete temp;
        } else { // both left and right child
            // here we find min in right substree and copy its value in root and then delete that node
            Node *toDelete = findMin(root->right); // similary you can use the findMax version
            root->data = toDelete->data;
            root->right = deleteInBSTRecursive(root->right, root->data);
            // now we have to delete the duplicate node in right subtree and hence we call it with root->right and root->data
        }
    }
    return root;
} // O(logn) time and O(h) space
// but here we are copying values and not changing actual links unlike iterative one, so that is con if you storing more fields other than data

int main() {
    
    return 0;
}