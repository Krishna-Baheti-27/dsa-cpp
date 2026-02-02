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

////////////////////////////////////////////////////////////////////////////////////////

// given the key you have to delete it from the bst

//////////////////////////////////////////////////////////////////////////////////////////

Node *findRightMost(Node *root) {
    while(root->right) root = root->right;
    return root; 
}

// but some edge cases are there

Node *deleteHelper(Node *nodeToDelete) {
    
    // Case 1:
    // if the nodeToDelete has neither left nor right then simply attach parent to nullptr

    if(!nodeToDelete->left && !nodeToDelete->right) {
        return nullptr;
    }

    // Case 2:
    // if the nodeToDelete doesnt have a left then simply attach the parent to its right

    if(!nodeToDelete->left) {
        return nodeToDelete->right; 
    }

    // Case 3:
    // if the nodeToDelete doesnt have a right then simply attach the parent to its left

    if(!nodeToDelete->right) {
        return nodeToDelete->left; 
    }

    // Case 4:
    // if both left and right exists then, rightMost node of nodeToDelete->left subtree should point to noteToDelete->right

    // we are essentially taking the entire Right Subtree and attaching it to the bottom-right of the Left Subtree

    Node *rightMostChild = findRightMost(nodeToDelete->left); 
    rightMostChild->right = nodeToDelete->right; // vvip step

    // now return the nodeToDelete->left node which will be connected to parent depending on left or right subtree, we have successfully modified all the links

    return nodeToDelete->left; 
}

Node *deleteInBST(Node *root, int key) {

    if(!root) {
        return root; // we cant delete since there is no node to delete
    }

    // here we want to delete the root itself

    if(root->data == key) {

        Node *toDelete = root;
        root = deleteHelper(root); // would return the new Node after deleting root

        delete toDelete; // delete old root

        return root;
    }

    // we now search for node to delete, basically the parent of node to delete since we want to mainatain links and we cannot traverse up the tree

    Node *parent = root;

    while(parent) {

        if(parent->data > key) { // check on left 

            // found the node to be deleted

            if(parent->left && parent->left->data == key) {
    
                // now we know the node to delete

                Node *toDelete = parent->left; 

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

                parent->right = deleteHelper(toDelete);

                delete toDelete; // remove that node

                break;

            } else {
                parent = parent->right; // try to get to the node to be deleted
            }
        }
    }

    // return the root of the updated tree

    return root; 

} // O(logN) time and O(1) space for iterative version

// The above method does not ensure that tree remains in logn height, instead its a just method to change the links and the height can go to O(N) in worst case
// the recursive method actually deleted in tree recursively maintaining the logn height or the original height and hence maintains the structure and height of logn

//////////////////////////////////////////////////////////////////////////////////////

// the above method was actually going and changing the links

// now we have two methods which are actually just changing or swapping the values and not references

// 1) the first one is recursive swap

////////////////////////////////////////////////////////////////////////////////////////

// The recursive version is more easier to understand,but does take O(logN) recursion stack space

// first search the node to be deleted in the bst

// So there are 3 cases in total : 

// 1) the node to be deleted doesnt have any child, then simply remove it and make parent point to nullptr

// 2) the node to be deleted has only a left or right child then simply attach the parent to the only child present

// 3) the node to be deleted has both left and right child
// then we have two options:

// first is find the min in right subtree of node to be deleted and then copy its value in node to be deleted, and then recursively delete the duplicate node in right subtree
// second is find the max in left subtree of node to de deleted and then copy its value in node to deleted, and then recursively delete the duplicate node in left subtree

Node *findMin(Node *root) {

    while(root && root->left) {
        root = root->left;
    }

    return root;
}

Node* deleteInBSTRecursive(Node *root, int key) {

    // no tree exists
    if(!root) {
        return root; 
    }

    if(root->data < key) {
        root->right = deleteInBSTRecursive(root->right, key);
    } else if(root->data > key) {
        root->left = deleteInBSTRecursive(root->left, key);
    } else {

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

        } else { // both left and right child exist

            // here we find min of right substree (inorder successor) and copy its value in the node to be deleted and then delete that node

            // similary you can use the findMax version which max of left subtree

            // replacing the root with one of the above two values makes it possible to maintain the bst property

            Node *toDelete = findMin(root->right);

            root->data = toDelete->data;

            // now we have to delete the duplicate node in right subtree and hence we call it with root->right and root->data

            root->right = deleteInBSTRecursive(root->right, toDelete->data);
        }
    }

    return root;

} // O(logn) time and space

// but here we are copying values and not changing actual links unlike iterative one, so that is con if you storing more fields other than data

/////////////////////////////////////////////////////////////////////////////////////

// 2) second one is iterative swap

// The logic is simple:

// Find the node to delete.

// If it has two children, find its Successor (min in right subtree) and the Successor's Parent.

// Copy the Successor's value to the target node.

// Now, simply update your target pointers to point to the Successor node instead of the original node.

// Proceed to delete that Successor node (which is guaranteed to have 0 or 1 child).

Node* deleteNodeIterativeSwap(Node* root, int key) {

    Node *curr = root;
    Node *parent = nullptr;

    // 1. Search for the node to delete

    while(curr != nullptr && curr->data != key) {

        parent = curr;

        if(key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if(curr == nullptr) {
        return root; // Key not found and hence cant delete
    }

    // 2. Handle the "Two Children" case by transforming it into a "0/1 Child" case

    if(curr->left != nullptr && curr->right != nullptr) {
        
        // Find the Inorder Successor (Min of Right Subtree)
        // AND keep track of its parent

        Node *succParent = curr;
        Node *succ = curr->right;

        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }

        // same as in recursive solution of changing the value of node to be deleted by inorder successor or min of right subtree

        curr->data = succ->data;

        // now we change our node to be deleted (curr) as succ since that is what we delete recursively after changing the value and similarly also change the parent

        curr = succ;
        parent = succParent;
    }

    // now every case either has 0 or 1 child

    Node *child = (curr->left != nullptr) ? curr->left : curr->right;

    // when we have the case to delete the root and its has only 1 child then the above if block will not be executed and parent remains null hence return child as that is left over

    if(parent == nullptr) {
        delete curr;
        return child;
    }

    // now the parent is not null means it is the inorder successor's parent and the child which is curr has to be deleted and whatever left as the child of curr gets attached to parent

    if(parent->left == curr) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete curr;

    return root;

} // O(logn) time and O(1) space best solution so far

int main() {
    
    return 0;
}