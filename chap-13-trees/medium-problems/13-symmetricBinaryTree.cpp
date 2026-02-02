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

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

///////////////////////////////////////////////////////////////////////////////////////

// we can do this pretty easily using BFS, when at a level, when we insert nodes we only have to check if the that level is like a palindrome, or simply if first and last nodes are same then, check if second and last second are same

// to check true symmetricity we also insert nullptr for non existent nodes so that we can check if the tree is true mirror image or not 

bool isSymmetricIterative(Node* root) {

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        int size = q.size();

        vector<int> arr;

        for(int i = 0; i < size; i++) {

            Node *node = q.front(); q.pop();

            if(node) {

                arr.push_back(node->data);

                if(node->left) {
                    q.push(node->left);
                } else {
                    q.push(nullptr);
                }

                if(node->right) {
                    q.push(node->right);
                } else {
                    q.push(nullptr);
                }

           } else {

                // a remark for nullptr since we know node.val is in [-100, 100] so this -200 is to tell in our traversal that its a null that is added but since its vector of int and hence use a int out of our range of nodes' values 

                arr.push_back(-200); 
            }
        }

        for(int i = 0, j = size - 1; i < j; i++, j--) {
            if(arr[i] != arr[j]) {
                return false;
            }
        }
    }

    // if every level checked and all same 

    return true; 

} // O(N) time and O(2N) space for queue + array

//////////////////////////////////////////////////////////////////////////////////////

// we can solve this without using extra array

// and iteratively we do this by inserting in queue the pairs and then comparing them for equality

bool isSymmetricIterativeOptimal(Node *root) {

    if(!root) {
        return true;
    }

    queue<Node*> q;

    // insert the pair (both left and right)

    q.push(root->left);
    q.push(root->right);

    while(!q.empty()) {

        Node *leftNode = q.front(); q.pop();
        Node *rightNode = q.front(); q.pop();

        // if both are null continue from next iteration, we cant return true since we havent checked all nodes yet

        if(!leftNode && !rightNode) {
            continue; 
        }

        // when one of them is null and other is not null then return false

        if(!leftNode || !rightNode) {
            return false;
        }

        // both not null but have different value

        if(leftNode->data != rightNode->data) {
            return false;
        }

        // now there values match and hence now push their children but again in pairs so that we can compare effectively like palindrome

        // outer - outer nodes

        q.push(leftNode->left);
        q.push(rightNode->right);

        // inner - inner nodes

        q.push(leftNode->right);
        q.push(rightNode->left);
    }

    // after processing and checking all of tree

    return true;

} // O(N) time and space

//////////////////////////////////////////////////////////////////////////////////////

// to simulate this recursively similar to iterative logic we need a helper to function to check about the palindromic nature and then if they satisfy we recurse into subtrees and check those

bool isSymmetricHelper(Node *p, Node *q) {

    if(!p && !q) {
        return true;
    }

    if(!p || !q) {
        return false;
    }

    // the above two conditions can also be written as

    // if(!p || !q) return (p == q);

    return (p->data == q->data) && isSymmetricHelper(p->left, q->right) && isSymmetricHelper(p->right, q->left);
}

bool isSymmetricRecursive(Node *root) {

    if(!root) {
        return true;
    }

    return isSymmetricHelper(root->left, root->right);

} // O(N) time and space

////////////////////////////////////////////////////////////////////////////////////

// this exact logic whether of iterative or recursive is used in same trees or not but there we check left with left and right with right instead of outer left with outer right and then inner right with innner left

int main() {
    
    return 0;
}