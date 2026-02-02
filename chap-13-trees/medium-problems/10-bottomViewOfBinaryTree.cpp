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

// same as top view but allow overwriting of the map for each x, till the last level

vector<int> bottomViewBrute(Node *root) {

    if(!root) {
        return {};
    }

    // very important to use ordered map so we store vertical in sorted order from minimum vertical

    map<int, int> mpp; // (vertical, node)
    
    queue<pair<Node*, int>> q;  // (node, vertical)
    q.push({root, 0});

    while(!q.empty()) {

        auto p = q.front(); q.pop();

        Node *node = p.first;
        int vertical = p.second;

        // let new nodes at bottom levels overwrite the data for a given vertical since we actually want the last node for that level

        mpp[vertical] = node->data;

        if(node->left) {
            q.push({node->left, vertical - 1});
        }

        if(node->right) {
            q.push({node->right, vertical + 1});
        }
    }

    vector<int> ans;

    for(auto &it : mpp) {
        ans.push_back(it.second);
    }

    return ans;

} // O(nlogn) since while loop runs n times and insertion in map takes O(logn) time
// O(2n) space for queue + map in worst case

/////////////////////////////////////////////////////////////////////////////////////

vector<int> bottomViewOptimal(Node *root) {

    if(!root) return {};

    unordered_map<int, int> mpp; // (vertical, node)

    int minVertical = 0, maxVertical = 0;

    queue<pair<Node*, int>> q; // (node, vertical) for BFS
    q.push({root, 0});

    while(!q.empty()) {

        auto p = q.front(); q.pop();

        Node *node = p.first;
        int vertical = p.second;

        minVertical = min(minVertical, vertical);
        maxVertical = max(maxVertical, vertical);

        mpp[vertical] = node->data; // allow overwriting to get last possible node as answer

        if(node->left) {
            q.push({node->left, vertical - 1});
        }

        if(node->right) {
            q.push({node->right, vertical + 1});
        }
    }

    // building the answer

    vector<int> ans; 

    for(int vertical = minVertical; vertical <= maxVertical; vertical++) {
        ans.push_back(mpp[vertical]);
    }

    return ans; 

} // O(N) time since O(1) for insertion in unordered_map and O(2N) space for queue + map

int main() {
    
    return 0;
}