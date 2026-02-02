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

// literally do any traversal of your choice and if both are exactly identical then the trees are same else not, here we are doing preorder traversal, that is root, left, right

////////////////////////////////////////////////////////////////////////////////////

bool areSameTrees(Node *root1, Node *root2) {
    
    if(root1 == nullptr && root2 == nullptr) return true; // both are same as they are null

    if(root1 && root2) {

        if(root1->data != root2->data) {
            return false; // roots dont have same value
        }

        if(areSameTrees(root1->left, root2->left) == false) {
            return false; // they dont have same left subtrees
        } 
        
        if(areSameTrees(root1->right, root2->right) == false) {
            return false; // they dont have same right subtrees
        }

        return true; // if everything satisfies then they are same or identical
    } 

    // this hits means either root1 == null and root2 != null and vice-versa which means they are not same as one of them exists and other is simply null which doesnt make sense to be same tree

    return false; 

} // O(N) time and O(N) space

/////////////////////////////////////////////////////////////////////////////

// a more elegant way to write the same above conditions

bool areSameTreesReadable(Node *root1, Node *root2) {

    if(!root1 || !root2) return (root1 == root2);

    return root1->data == root2->data && areSameTreesReadable(root1->left, root2->left) && areSameTreesReadable(root1->right, root2->right);

} // O(N) time and O(N) space

////////////////////////////////////////////////////////////////////////////

// if you want to solve it using bfs then use queue with pairs but make sure to check left with left and right with right

// SEE THIS CONCEPT IN GREAT DETAIL IN QUESTION 13 SYMMETRIC TREE

bool areSameTreesIterative(Node *p, Node *q) {

    queue<Node*> qu;

    qu.push(p);
    qu.push(q);

    while(!qu.empty()) {

        Node *node1 = qu.front(); qu.pop();
        Node *node2 = qu.front(); qu.pop();

        if(!node1 && !node2) {
            continue;
        }

        if(!node1 || !node2) {
            return false;
        }

        if(node1->data != node2->data) {
            return false;
        }

        // now push children but in order left-left and right-right

        qu.push(node1->left);
        qu.push(node2->left);

        qu.push(node1->right);
        qu.push(node2->right);
    }

    return true;

} // O(N) time and space

int main() {
    
    return 0;
}