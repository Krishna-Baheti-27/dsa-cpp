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

void hashhInorder(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mpp) {
    for(int i = 0; i < inorder.size(); i++) {
        mpp[inorder[i]] = i;
    }
}

Node* buildTree(vector<int> &preorder, vector<int> &inorder) {
    // here we know that preorder and inorder are unique and hence we can hashh the inorder to look for the root obtained from first element of preorder quickly
    unordered_map<int,int> hashh;
    hashhInorder(preorder, inorder, hashh);

}

int main() {
    
    return 0;
}