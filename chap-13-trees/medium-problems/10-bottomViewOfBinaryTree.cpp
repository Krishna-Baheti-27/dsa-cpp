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

// same as in vertical order traversal of binary tree, here we want to find the bottom view, which basically means we do not have to maintain level of each node, but instead we only store the vertical for a node and when we traverse in the map we simply get those node (each vertical will only store the node at the last level since we are talking about bottom view)

vector<int> bottomView(Node *root) {
    if(!root) return {};
    map<int, int> mpp; // (vertical, node)
    // very important to use ordered map so we store vertical in sorted order from minimum vertical
    queue<pair<Node*, int>> q;  // (node, vertical)
    q.push({root, 0});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        Node *node = p.first;
        int vertical = p.second;
        mpp[vertical] = node->data;
        // let new nodes at bottom levels overwrite the data for a given vertical since we actually want the last node for that level
        if(node->left) {
            q.push({node->left, vertical - 1});
        }
        if(node->right) {
            q.push({node->right, vertical + 1});
        }
    }
    vector<int> ans;
    for(auto it : mpp) {
        // it.second points to our nodes
        ans.push_back(it.second);
    }
    return ans;
} // O(nlogn) since while loop runs n times and insertion in map takes O(logn) time
// O(2n) space for queue + map in worst case


int main() {
    
    return 0;
}