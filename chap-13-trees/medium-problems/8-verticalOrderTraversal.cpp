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

// what we have to do is assign a vertical or x coordinate and also level ory corrdinate so that each node can be uniquely identified
// once we have done that, then we traverse in ascending order of vertical or x and for each vertical we travel in ascending order or top to bottom from level = 0 to the last level

// to asign this we can use any traversal but here we are using level-order traversal

 

vector<vector<int>> verticalTraversal(Node *root) {
    vector<vector<int>> ans; // to return the traversal

    map<int, map<int, multiset<int>>> mpp; 
    // the map to store the vertical, and each vertical has some levels and each level can have multiple occurrences of same or duplicate elements in which we have to maintain the sorted order and hence multiset since it stores in sorted order and also allows for unique elemets

    queue<pair<Node*, pair<int,int>>> q; // this will be the queue using which we will do level order traversal and queue will store the element, its vertical and its level
    q.push({root, {0,0}}); // pushing the root node which will have vertical = 0 and level = 0
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto p = q.front(); q.pop();
            Node *node = p.first;
            int x = p.second.first, y = p.second.second;
            mpp[x][y].insert(node->data); // insert the given node at vertical x and level y
            if(node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
    }
    // now we have all the nodes stored in mpp in level by level fashion so we simply have to put those in ans
    for(auto it : mpp) { 
        // it.first refers to the vertical and it.second refers to map which is collection of levels and keys and multiset of nodes as vlaues 
        vector<int> temp;
        for(auto mp : it.second) {
            // here mp.first means level and mp.second means multiset which holds the nodes in that level for given vertical
            temp.insert(temp.end(), mp.second.begin(), mp.second.end());
            // here we are inserting the entire multiset which begins from mp.second.begin() to mp.second.end() always at the end of temp since we want to maintain the order level wise so first nodes of intial levels will be stored for the given vertical
            // it takes O(n) time
        }
        ans.push_back(temp);
    }
    return ans;
} // O(nlogn) time since while loop runs n times and insertion in multiset takes O(logn) time

// We can also do this without using level order traversal (without using queue) but rather a DFS traversal like preorder ti get around using less spaceks, but you must track level explicitly, because unlike BFS you don’t naturally know which node is higher/lower.

// but for those we would have to track the level and vetical explicitly, basically maintain it in function calls and that woudld do

// here is that approach and using preorder (root, left, right)



int main() {
    
    return 0;
}