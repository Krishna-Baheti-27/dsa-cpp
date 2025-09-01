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

bool rootToNodePathHelper(Node *root, Node *target, vector<int> &arr) {
    if(root == nullptr) return false;
    arr.push_back(root->data);
    if(root == target) {
        return true;
    }
    if(rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) return true;
    arr.pop_back();
    return false;
}

vector<int> rootToNodePath(Node *root, Node*target) {
    vector<int> res;
    if(!root) return res;
    rootToNodePathHelper(root, target, res);
    return res;
}

int main() {
    
    return 0;
}