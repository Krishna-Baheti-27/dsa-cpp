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

// same as level order traversal, but here on every level we change our traversal order
// so on first level left to right then on second level right to left and so on

///////////////////////////////////////////////////////////////////////////////////

// so its pretty easy, we just have to create a flag which will tell us what order to follow for a particular level like flag == 0 means left to right and flag == 1 means right to left

// so depending on left to right or right to left we change our traversal order to fill accordingly

vector<vector<int>> zigZagTraversal(Node *root) {

    queue<Node*> q;
    vector<vector<int>> ans;

    int flag = 0; // depicts left to right (flag == 1, depicts right to left)

    q.push(root);
    
    while(!q.empty()) {

        int size = q.size();

        vector<int> temp(size); // to store traversal of that level
        
        for(int i = 0; i < size; i++) {

            Node *root = q.front(); q.pop();

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);

            int index = flag == 1 ? size - i - 1 : i; // insert in the order according to the flag
           
            temp[index] = root->data;        
        }

        ans.push_back(temp); // store traversal for that level

        flag = 1 - flag; // changes 0 to 1 and 1 to 0
    }

    return ans;

} // O(N) time and O(N) space

int main() {
    
    return 0;
}