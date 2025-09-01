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

Node* searchInBSTRecursive(Node *root, int target) {
    if(!root) return nullptr;
    if(root->data == target) return root;
    else if(root->data > target) return searchInBSTRecursive(root->left, target);
    else return searchInBSTRecursive(root->right, target);
} // you are not traversing the entire tree but in zig zag fashion sometimes on left or right so essentially only traversing height of the tree and hence time will be O(H) or O(logN)
// O(logN) space since height of tree is O(logN)

Node* searchInBSTIterative(Node *root, int target) {
    while(root != nullptr && root->data != target) {
        root = root->data > target ? root->left : root->right;
    }
    return root; // either nullptr or the required node
} // O(logN) time and O(1) space

int main() {
     
    return 0;
}