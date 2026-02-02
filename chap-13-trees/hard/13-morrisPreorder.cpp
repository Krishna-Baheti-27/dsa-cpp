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

// same as in inorder just a slight change

// in inorder before adding the root we complete the left traversal (that is when the thread already exists then we add the root else we do left traversal first by attaching the thread)

// in preorder we mark the node immediately the first time we see it and hencd here we add the value to our list at the time of attaching the thread not removing it

vector<int> morrisPreorder(Node *root) {

    vector<int> preorder;
    Node *curr = root;

    while(curr != nullptr) {

        if(curr->left == nullptr) {

            preorder.push_back(curr->data);
            curr = curr->right;

        } else {

            Node *prev = curr->left;

            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {   // no thread then attach it and add to traversal

                preorder.push_back(curr->data);
                prev->right = curr;
                curr = curr->left;

            } else {   // thread exists then break it and move to right

                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return preorder;

} // O(2N) time and O(1) space (we can atmax visit each node twice and no extra space)

// The time complexity is technically amortized O(N) (specifically O(2N) or O(3N) since edges are traversed at most 2-3 times) because finding the predecessor takes steps, but overall it is linear.

int main() {
    
    return 0;
}