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

int height(Node *root) {
    if(root == nullptr) return 0; // if no nodes then zero height, if a single node then 1 height
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    
    return 0;
}