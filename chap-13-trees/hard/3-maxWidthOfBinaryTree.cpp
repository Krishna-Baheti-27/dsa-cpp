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

// max width of the binary tree is the maximum width among all levels
// width of the level is defined as the maximum number of nodes between two nodes
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// to find the width of binary tree we want to index the nodes so that our answer at each level would be rightMost - leftMost + 1
// now how to index to also calculate for width of missing nodes is by 2*i + 1 and 2*i + 2, (since its a binary tree and each node can have atmost 2 children)
// but that would cause overflow in case of skewed trees and hence we smartly index each node by using
// i = i - min index of that level and use this new value of i for computing newer indices

int widthOfBinaryTree(Node *root) {
    // since we going at each level therefore we choose level order traversal
    if(!root) return 0;
    int width = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0}); // we start of with zero based indexing
    while(!q.empty()) {
        int size = q.size();
        int first, last;
        int minIdx = q.front().second; // this will be min used in i - min
        for(int i = 0; i < size; i++) {
            int currId = q.front().second - minIdx; // this is what is our i - min, and starts with zero 
            Node *node = q.front().first;
            q.pop(); // we discard that node
            if(i == 0) first = currId; // this is the current index to store which will be used for finding answer later using last - first + 1
            if(i == size - 1) last = currId;
            if(node->left) q.push({node->left, 2*currId + 1});
            if(node->right) q.push({node->right, 2*currId + 2});
        }
        width = max(width, last-first + 1);
        // this will thus keep max width by finding width of each level and comparing it with max width
    }
    return width;
} // will give us run time error even though we have normalised indices and thus use long long

int widthOfBinaryTreeBetter(Node *root) {
    if (!root) return 0;
    int width = 0;
    queue<pair<Node*, long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long minIdx = q.front().second;
        long long first = 0, last = 0;

        for (int i = 0; i < size; i++) {
            long long currId = q.front().second - minIdx;  // normalize
            Node* node = q.front().first;
            q.pop();

            if (i == 0) first = currId;
            if (i == size - 1) last = currId;

            if (node->left) q.push({node->left, 2 * currId + 1});
            if (node->right) q.push({node->right, 2 * currId + 2});
        }

        width = max(width, (int)(last - first + 1));
    }
    return width;
} // O(n) time and O(n) space

// you dont have to simulate heap indices, instead we can count the relative number of nodes at each level and then again use same last - firs + 1, without maintaining or simulating indices
// But there is problem it just counts the number of nodes at a level which is q.size() and does not calculate the actual width of binary tree and hence incorrect

// int widthOfBinaryTreeIncorrect(Node *root) {
//     if(!root) return 0;
//     queue<Node*> q;
//     int width = 0;
//     q.push(root);
//     while(!q.empty()) {
//         int size = q.size();
//         int firstOcc = -1, lastOcc = -1;
//         for(int i = 1; i <= size; i++) {
//             Node *node = q.front(); q.pop();
//             if(firstOcc == -1) {
//                 firstOcc = i;
//             }
//             lastOcc = i;
//             if(node->left) q.push(node->left);
//             if(node->right) q.push(node->right);
//         }
//         width = max(width, lastOcc - firstOcc + 1);
//         // moreover if you want to calculate width on this basis then you dont even have to maintain the firstOcc and lastOcc variables since the size will always be given by q.size()
//     }
//     return width;    
// }

int main() {
    
    return 0;
}