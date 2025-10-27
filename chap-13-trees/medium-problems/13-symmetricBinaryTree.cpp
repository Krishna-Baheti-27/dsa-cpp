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

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// we can do this pretty easily using BFS, when at a level, when we insert nodes we only have to check if the that level is like a palindrome, or simply if first and last nodes are same then, check if second and last second are same

// to check true symmetricity we also insert nullptr for non existent nodes so that we can check if the tree is true mirror image or not 

bool isSymmetricIterative(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> arr;
        for(int i = 0; i < size; i++) {
            Node *node = q.front(); q.pop();
            if(node) {
                arr.push_back(node->data);
                if(node->left)  q.push(node->left);
                else q.push(nullptr);
                if(node->right)  q.push(node->right);
                else q.push(nullptr);
           } else {
                arr.push_back(-200); 
                // a remark for nullptr since we know node.val is in [-100, 100]
           }
            
        }
        for(int i = 0, j = size - 1; i < j; i++, j--) {
            if(arr[i] != arr[j]) return false;
        }
    }
    return true; // if every level checked
} // O(N) time and O(2N) space for queue + array

// we can solve this without using extra array

bool isSymmetricRecursive(Node *root) {

}

int main() {
    
    return 0;
}