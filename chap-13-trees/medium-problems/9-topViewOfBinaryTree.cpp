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

// same as in vertical order traversal of binary tree, here we want to find the top view, which basically means we do not have to maintain level of each node, but instead we only store the vertical for topmost node and when we traverse in the map we simply get those node (each vertical will store only one node since we are talking about top view)

////////////////////////////////////////////////////////////////////////////////////////

// so again same procedure to mark verticals and then iterate them from left to right and insert in our answer to get the top view

vector<int> topViewBrute(Node *root) {

    if(!root) {
        return {};
    }

    // very important to use ordered map so we store vertical in sorted order from minimum vertical

    map<int, int> mpp; // (vertical, node)
    

    queue<pair<Node*, int>> q;  // (node, vertical), queue for BFS traversal
    q.push({root, 0});

    while(!q.empty()) {

        auto p = q.front(); q.pop();

        Node *node = p.first;
        int vertical = p.second;

        // this makes sure we insert only the first occurence of the vertical, which means only the first node which appears for the vertical and since we doing traversal level by level we are guranteed that the first node which will appear for a particular vertical will be the top most node for that vertical

        if(mpp.find(vertical) == mpp.end()) {
            mpp[vertical] = node->data; 
        }
        
        if(node->left) {
            q.push({node->left, vertical - 1}); // decrease vertical by 1 if we go left
        }

        if(node->right) {
            q.push({node->right, vertical + 1}); // increase vertical by 1 if we go right
        }
    }

    vector<int> ans;

    // for each vertical in mpp in increasing order from left to right

    for(auto vertical : mpp) { 
        ans.push_back(vertical.second); // store the only node or top most node
    }

    return ans;

} // O(nlogn) since while loop runs n times and insertion in map takes O(logn) time
// O(2n) space for queue + map in worst case

///////////////////////////////////////////////////////////////////////////////////

// the main time here is dominated by insertion in map which takes logN time and hence total complexity is O(NlogN) but we were using map to store the verticals in sorted order, but we dont have to do that, instead we can use unordered_map to store the verticals and their top nodes, and maintain two variables as minVertical and maxVertical which will store the min and max vertical encountered so far, so after BFS, we simply iterate from minVertical to maxVertical and take out value from unordered_map and its guaranteed that every vertical will exist between minVertical and maxVertical so we wont be missing anything

// we iterate from minVertical to maxVertical because we have to find the topView from left to right and not from right to left

vector<int> topViewOptimal(Node *root) {

    if(!root) {
        return {};
    }

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

        if(mpp.find(vertical) == mpp.end()) {
            mpp[vertical] = node->data;
        }

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

//////////////////////////////////////////////////////////////////////////////////////

// now here the collision would not occur since verticals or keys are distinct and hence unordere map would take O(1) time for insertion in avg but if you want guaranteed O(1) use a vector of size max - min + 1 and shift all verticals as vertical + abs(minvertical)

// but that is not needed as unordered_map works just as fine

////////////////////////////////////////////////////////////////////////////////////////

// another approach is to use the code for vertical order traversal where we do the same thing but only store the first node in the y level for each unique x thats it, but that maybe a overkill here

// Reuse the simple struct or just pair<int, pair<int, int>>
// {x, {y, val}}

vector<int> topViewSorting(Node* root) {

    if(!root) {
        return {};
    }

    vector<pair<int, pair<int, int>>> nodes;
    
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {

        auto p = q.front(); q.pop();

        Node* curr = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes.push_back({x, {y, curr->data}});

        if (curr->left) q.push({curr->left, {x - 1, y + 1}});
        if (curr->right) q.push({curr->right, {x + 1, y + 1}});
    }

    // sort in order of x, y and val (very important)

    sort(nodes.begin(), nodes.end());

    vector<int> ans;

    for(int i = 0; i < nodes.size(); i++) {
        if(i == 0 || nodes[i].first != nodes[i-1].first) {
            ans.push_back(nodes[i].second.second);
        }
    }

    return ans;

} // O(nlogn) time and O(n) space

int main() {
    
    return 0;
}