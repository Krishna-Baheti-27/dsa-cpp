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

// we have to find the path from root to the particular target node which is given to us, if only have the value then we can search it and then apply the algorithm

// if the tree had parent pointers where we could traverse up the tree then this problem would have been super simple but we dont have that so we have devise a solution using what we have

// here we are using preorder traversal which is super simple and intuitive

bool rootToNodePathHelper(Node *root, Node *target, vector<int> &arr) {

    if(!root) return false; // did not found

    arr.push_back(root->data); // if root is not null add it to the answer

    if(root == target) return true; // found the node , no need to go to left or right

    if(rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) {
        return true; 
        // if any one of left or right subtrees return true means we have found the target and hence return true;
    }

    // since the target was not found on the left or right subtree and also on current node which means that this node is not present in the path from root to target and hence we initially inserted it becuase it was assumed it was present but since its not present we remove it

    arr.pop_back(); // remove the inserted node and return false
    return false; 
}

vector<int> rootToNodePath(Node *root, Node *target) {
    vector<int> res;
    rootToNodePathHelper(root, target, res);
    return res;
} // O(N) time, O(N) recursion stack space in worst case, we dont consider space to return answer

// we can apply the same logic if only the value is given to us and not the target since we can still search like this but then the question should state that tree only consists of unique values else we would have two different paths for which our code would fail, would return the first target which appears in preorder traversal

bool rootToNodePathValHelper(Node *root, vector<int> &arr, int target) {
    if(!root) return false;

    arr.push_back(root->data);

    if(root->data == target) return true;

    if(rootToNodePathValHelper(root->left, arr, target) || rootToNodePathValHelper(root->right, arr, target)) return true;

    arr.pop_back();
    return false;
}

vector<int> rootToNodePathVal(Node *root, int target) {
    vector<int> res;
    rootToNodePathValHelper(root, res, target);
    return res;
} // O(N) time and O(N) space

int main() {
    
    return 0;
}