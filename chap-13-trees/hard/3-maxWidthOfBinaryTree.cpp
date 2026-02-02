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

///////////////////////////////////////////////////////////////////////////////////////

// if the question was to exclude the null nodes then we would simply do a level order traversal and width of each level is simply q.size() and max widht is basically max size of the queue at any instant, but here we want to account for null nodes also between any two nodes

// very important thing to note is that we have to also count null nodes between any two NON-NULL nodes so there have to be two non-null nodes, for us to count null nodes between them 

// to find the width of binary tree we want to index the nodes so that our answer at each level would be rightMost - leftMost + 1
// now how to index to also calculate for width of missing nodes is by 2*i + 1 and 2*i + 2, (since its a binary tree and each node can have atmost 2 children, inspired from HEAPS)
// but that would cause overflow in case of skewed trees and hence we smartly index each node by using
// i = i - min index of that level and use this new value of i for computing newer indices

/////////////////////////////////////////////////////////////////////////

// since we going at each level therefore we choose level order traversal

int widthOfBinaryTreeDoesntWorks(Node *root) {

    if(!root) {
        return 0;
    }

    int width = 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0}); // we start of with zero based indexing

    while(!q.empty()) {

        int size = q.size();

        int first = 0, last = 0;

        // this will be min used in i - min, since min idx would obvioulsy be index of the first node of that level

        int minIdx = q.front().second; 

        for(int i = 0; i < size; i++) {

            // this is what is our i - min, and starts with zero 

            int currId = q.front().second - minIdx; 
            Node *node = q.front().first;

            q.pop(); // we discard that node

            if(i == 0) {
                first = currId; // storing the index of first element
            }
            
            if(i == size - 1) {
                last = currId; // storing the index of last element
            }

            // and we cant generate these first and last indices beforehand since we dont know how many nodes are present (including null) since while creating indices we are also accounting for null, if we only had to consider non-null nodes then it was simple and their difference would always be q.size()
            
            if(node->left) {
                q.push({node->left, 2 * currId + 1});
            }

            if(node->right) {
                q.push({node->right, 2 * currId + 2});
            }

        }

        width = max(width, last - first + 1); // keeping track of max width thus far
    }

    return width;

} // O(N) time and O(N) space 

/////////////////////////////////////////////////////////////////////////////////////

// will give us run time error even though we have normalised indices and thus use long long

int widthOfBinaryTreeWorks(Node *root) {

    if(!root) {
        return 0;
    }

    int width = 0;

    queue<pair<Node*, long long>> q; // use long long to store indices
    q.push({root, 0});

    while(!q.empty()) {

        int size = q.size();
        long long minIdx = q.front().second;
        long long first = 0, last = 0;

        for(int i = 0; i < size; i++) {

            long long currId = q.front().second - minIdx;  // normalize =>  i = i - minIdx  
            Node* node = q.front().first;

            q.pop();

            if(i == 0) {
                first = currId;
            }

            if(i == size - 1) {
                last = currId;
            }

            if(node->left) {
                q.push({node->left, 2 * currId + 1}); // 2 * i + 1
            }

            if(node->right) {
                q.push({node->right, 2 * currId + 2}); // 2 * i + 2
            }
        }

        width = max(width, (int)(last - first + 1)); // typecast long long back to int
    }

    return width;
    
} // O(n) time and O(n) space

int main() {
    
    return 0;
}