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

// You are given the root of a BST and an integer key. You need to find the inorder predecessor and successor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note: In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

/////////////////////////////////////////////////////////////////////////////////////////

// in the brute force we simply generate the inorder and then using linear or binary search find the value just greater and just smaller than the key

void inorderHelper(Node *root, vector<Node*> &inorder) {

    if(!root) {
        return;
    }

    inorderHelper(root->left, inorder);

    inorder.push_back(root);

    inorderHelper(root->right, inorder);
}

vector<Node*> inorderTrav(Node *root) {

    vector<Node*> inorder;
    inorderHelper(root, inorder);

    return inorder;
}

vector<Node*> findPreSucBrute(Node* root, int key) {
    
    vector<Node*> inorder = inorderTrav(root);

    vector<Node*> ans;

    // we know this will be sorted and the following if-else condition take benefit of that

    for(int i = 0; i < inorder.size(); i++) {

        if(inorder[i]->data < key) {

            if(i + 1 < inorder.size()) {
                if(inorder[i + 1]->data > key) {
                    ans.push_back(inorder[i]);
                    ans.push_back(inorder[i + 1]);
                    break;
                } 
            } else {
                ans.push_back(inorder[i]);
                ans.push_back(nullptr);
                break;
            }

        } else if(inorder[i]->data > key) {

            ans.push_back(nullptr);
            ans.push_back(inorder[i]);
            break;

        } else {

            if(i - 1 >= 0) {
                ans.push_back(inorder[i - 1]);
            } else {
                ans.push_back(nullptr);
            }

            if(i + 1 < inorder.size()) {
                ans.push_back(inorder[i + 1]);
            } else {
                ans.push_back(nullptr);
            }

            break;
        }
    }

    return ans;
}

// the more readable version of the above code is here where we dont use the i - 1 or i + 1 checks since we know the vector is sorted

vector<Node*> findPreSucBrute(Node* root, int key) {
    
    vector<Node*> inorder;
    inorderHelper(root, inorder);

    Node* pre = nullptr;
    Node* suc = nullptr;

   
    for (Node* node : inorder) {
        
        if (node->data < key) {
            pre = node;
        } else if (node->data > key) {
            suc = node;
            break; 
        }
    }

    return {pre, suc};

} // O(N) time and space

//////////////////////////////////////////////////////////////////////////////////////

// the better solution is doing the preorder and maintaining a prev pointer by reference for finding inorder predecessor and also succ for inorder successor

void betterHelper(Node *root, Node* &prev, Node* &succ, int key) {

    if(!root) {
        return;
    }

    betterHelper(root->left, prev, succ, key);

    // if we havent found the succ yet and the value is greater than key

    if(root->data > key && succ == nullptr) {
        succ = root;
    }

    // update each time to get the least smallest element from key

    if(root->data < key) {
        prev = root;
    }

    betterHelper(root->right, prev, succ, key);
}

vector<Node*> findPreSucBetter(Node *root, int key) {

    Node *prev = nullptr;
    Node *succ = nullptr;

    betterHelper(root, prev, succ, key);

    return {prev, succ};

} // O(N) time and space

/////////////////////////////////////////////////////////////////////////////////////

// the most optimal approach is to use the property of bst that is greater on right and smaller on left (similar to how we apply binary search by simply removing each side in each iteration)

vector<Node*> findPreSucOptimal(Node *root, int key) {

    Node *prev = nullptr, *succ = nullptr;

    Node *temp = root;

    while(temp) {

        if(temp->data < key) {
            prev = temp;
            temp = temp->right; // look for better (just smaller)
        } else {
            temp = temp->left;
        }
    }

    temp = root;

    while(temp) {

        if(temp->data > key) {
            succ = temp;
            temp = temp->left; // look for better (just greater)
        } else {
            temp = temp->right;
        }
    }

    return {prev, succ};

} // O(h) time and no extra space

int main() {
    
    return 0;
}