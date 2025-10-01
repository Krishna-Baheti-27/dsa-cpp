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

vector<vector<int>> zigZagTraversal(Node *root) {
    queue<Node*> q;
    vector<vector<int>> ans;
    int flag = 0; // depicts left to right (flag == 1. depicts right to left)
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp(size); // to store traversal of that level
        for(int i = 0; i < size; i++) {
            Node *root = q.front(); q.pop();
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            int index = flag ? size - i - 1 : i; // insert in the order according to the flag
            // flad == 1 means insert from back and hence size - i - 1, else insert from front and hence index = i
            temp[index] = root->data;        
        }
        ans.push_back(temp);
        flag = 1 - flag; // changes 0 to 1 and 1 to 0
    }
    return ans;
} // O(N) time and O(N) space

int main() {
    
    return 0;
}