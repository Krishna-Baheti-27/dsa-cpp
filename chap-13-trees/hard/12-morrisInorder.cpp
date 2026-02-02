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

// it is the traversal which takes O(N) time but no extra space using the concept of threaded binary trees

//////////////////////////////////////////////////////////////////////////////////////

// for inorder

// in the morris traversal we have two primary cases
// when the left is null then we simply print the curr node and move to its right
// when the left is not null we try to find the right most guy of the left subtree (curr->left) if its null then we make the thread by attaching it to curr
// if its not null means thread already exists so we break the thread add curr to inorder and move right

// we do this while its not null

// in inorder before adding the root we complete the left traversal (that is when the thread already exists then we add the root else we do left traversal first by attaching the thread)

vector<int> morrisInorder(Node *root) {

    vector<int> inorder;
    Node *curr = root;

    while(curr != nullptr) {

        if(curr->left == nullptr) {

            inorder.push_back(curr->data);
            curr = curr->right;

        } else {

            Node *prev = curr->left;

            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {   // no thread then attach it

                prev->right = curr;
                curr = curr->left;

            } else {    // thread exists then break it and add to inorder and move right

                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;

} // O(2N) time and O(1) space (we can atmax visit each node twice and no extra space)

// The time complexity is technically amortized O(N) (specifically O(2N) or O(3N) since edges are traversed at most 2-3 times) because finding the predecessor takes steps, but overall it is linear.

int main() {
    
    return 0;
}