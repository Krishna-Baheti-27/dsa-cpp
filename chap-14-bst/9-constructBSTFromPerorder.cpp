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

// the naive approach is simply inserting the nodes one by one as we traverse the preorder array, we know first element is the root, and all subsequent elements are inserted in a way to they follow property of BST, insertion takes approx O(n) for n nodes that is O(n^2) time, best time O(nlogn)

Node *bstFromPreorderBrute(vector<int> &preorder) {
    
}

// the better approach is where we sort the preorder to get the inorder and then using preorder + inorder we can construct a BT in O(n) which will be a unique BST
// O(NlogN + N) time and O(N) space



int main() {
    
    return 0;
}