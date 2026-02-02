#include <bits/stdc++.h>
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

// Implement the BSTIteratorOptimal class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIteratorOptimal(TreeNode root) Initializes an object of the BSTIteratorOptimal class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

/////////////////////////////////////////////////////////////////////////////////////

// we simply maintain the inorder of bst in vector and have the pointer as the index of vector 

class BSTIteratorBrute {

    void inorderHelper(Node *root, vector<int> &inorder) {

        if(!root) {
            return;
        }

        inorderHelper(root->left, inorder);

        inorder.push_back(root->data);

        inorderHelper(root->right, inorder);
    }

    vector<int> inorderTrav(Node *root) {

        vector<int> inorder;
        inorderHelper(root, inorder);

        return inorder;
    }

    vector<int> inorder;
    int idx = -1;

public:

    BSTIteratorBrute(Node *root) {
        inorder = inorderTrav(root); // O(N) time and space
    }
    
    int next() { // O(1) time
        idx++;
        return inorder[idx];
    }
    
    bool hasNext() { // O(1) time
        return idx + 1 < inorder.size();
    }
};

/////////////////////////////////////////////////////////////////////////////////////

// the better solution without storing the entire inorder of bst  instead only use O(h) as the space and still make next and hasNext() run in O(1) avg time

// to do this in O(h) space we use the iterative inorder which we have already covered using the stack data structure

class BSTIteratorBetter {

    stack<Node*> st;

public:

    BSTIteratorBetter(Node *root) {

        Node *temp = root;

        while(temp) {
            st.push(temp);
            temp = temp->left;
        }
    }
    
    // O(N/N) time which is on avg O(1) time since total N nodes will be inserted and it will be called total of N times

    int next() {
        
        Node *topNode = st.top();

        st.pop();

        int val = topNode->data;

        if(topNode->right) {

            topNode = topNode->right;
            while(topNode) {
                st.push(topNode);
                topNode = topNode->left;
            }
        } 

        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

///////////////////////////////////////////////////////////////////////////////////////////

// the most optimal solution uses morris inorder so that we do it in O(1) space

class BSTIteratorOptimal {

    Node *curr = nullptr;

public:

    BSTIteratorOptimal(Node *root) {
        curr = root;
    }
    
    // Check if there are more nodes to visit

    bool hasNext() {
        return curr != nullptr;
    }

    // Find the next inorder node and stop the traversal there not till we make curr null

    int next() {

        int res = -1; // Variable to store the result

        while (curr != nullptr) {
            
            if(curr->left == nullptr) {
                
                // found the node so store result and next node to begin traversal from on and break

                res = curr->data;
                curr = curr->right; 
                break; 

            } else {
                
                Node *prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == nullptr) {

                    prev->right = curr;
                    curr = curr->left;

                } else {

                    // the thread already exists means we have traversed and the node so now store result and move to next node and stop the traversal
                    
                    prev->right = nullptr; 
                    res = curr->data;      
                    curr = curr->right;    
                    break; 
                }
            }
        }
        
        return res;
    }
};

int main() {
    
    return 0;
}