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

// vector<int> arr = {};
// vector<int> preorderTraversal(Node *root) {
//     if(root == nullptr) return arr;
//     arr.push_back(root->data);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
//     return arr; // did complete traversal
// }
// WORST METHOD TO USE GLOBAL VARIABLE AS THE CODE IS NOT REUSABLE

// Option 1

void preorderHelper(Node *root, vector<int> &result) {
    if(root == nullptr) return;
    result.push_back(root->data);
    preorderHelper(root->left,result);
    preorderHelper(root->right,result);
}

vector<int> preorderTraversal(Node *root) {
    vector<int> result;
    preorderHelper(root,result);
    return result;
}

// Option 2 (Purely recursive but less readable)

vector<int> preorderTraversalRecursive(Node *root) {
    if(root == nullptr) return {};
    vector<int> result = {root->data}; // we have inserted the root in main result array, basically insert current node's data
    vector<int> left = preorderTraversalRecursive(root->left); // find the left subarray for leftsubtree
    vector<int> right = preorderTraversalRecursive(root->right); // find the right subarray for rightsubree
    result.insert(result.end(), left.begin(), left.end()); // inserting left , because root left right
    result.insert(result.end(), right.begin(), right.end()); // inserting right at end because root left right
    return result;
} // less efficient also since multiple insertions and merge


// Preorder traversal like this : 
void preorder(Node *root) {
    if(root == nullptr) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
// Takes O(N) time since N nodes and each node is traversed exactly N times and O(H) recursion stack space where H is height of tree and in worst case it can be O(N) since h = N in case of degenerate tree

/////////// for INORDER
vector<int> inorderTraversal(Node *root) {
    if(root == nullptr) return {};
    vector<int> left = inorderTraversal(root->left);
    int result = root->data; // here root can be simply stored as an int and not a vector
    vector<int> right = inorderTraversal(root->right);
    left.push_back(result); // to maintain Left Root Right
    // left.insert(left.end(), result.begin(), result.end()); use this if you want result to be a vector, but need not be
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
// again the use of helper function is a better approach

/////////////// for postOrder
vector<int> postorderTraversal(Node *root) {
    if(root == nullptr) return {};
    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);
    // answer would be left right root
    left.insert(left.end(), right.begin(), right.end());
    left.push_back(root->data);
    return left;
}

// void levelorderHelper(Node *root, vector<vector<int>> &result,queue<Node*> &q) {
//     if(q.empty()) return;
//     vector<Node*> temp;
//     vector<int> level;
//     while(!q.empty()) {
//         temp.push_back(q.front());
//         level.push_back(q.front()->data);
//         q.pop();
//     }
//     for(int i = 0; i < temp.size(); i++) {
//         if(temp[i]->left) q.push(temp[i]->left);
//         if(temp[i]->right) q.push(temp[i]->right);
//     }
//     result.push_back(level);
// }

// vector<vector<int>> levelorderTraversal(Node *root) {
//     if(root == nullptr) return {};
//     vector<vector<int>> result; // main result;
//     queue<Node *> q;
//     q.push(root);
//     levelorderHelper(root,result,q);
//     return result;
// }

// HERE WE DONT HAVE RECURSION SO NO NEED TO USE HELPER FUNCTION
vector<vector<int>> levelorderTraversal(Node *root) {
    if(!root) return {};
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    int size;
    while(!q.empty()) {
        size = q.size();
        vector<int> levelTraversal; // vector for that level
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop(); // pop the node after you have got it
            levelTraversal.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(levelTraversal); // push_back works on vector of vectors
    }
    return result;
}

// Setting size = q.size(); at the start of each level ensures that you process only the nodes that are currently in the queue—which are exactly the nodes at the current level.

// Any children you add during this iteration are pushed to the back of the queue and will be processed in the next level (i.e., in the next iteration of the while loop).

// This keeps each level’s processing clean and separated, so you never accidentally process nodes from the next level too early.

// so we dont need a temporary vector to keep the elements of that level since adding children changes size of queue, so we sotre size first and insertion in queue happens from back so they dont distort the order

vector<int> iterativePreorder(Node *root) {
    if(!root) return {};
    stack<Node*> st; // explicit stack
    // Root Left Right
    vector<int> result;
    st.push(root);
    while(!st.empty()) {
        Node *node = st.top(); st.pop();
        result.push_back(node->data); // Root
        if(node->right) st.push(node->right); // push right first since stack is LIFO so right should be after left
        if(node->left) st.push(node->left); // then left
    }
    return result;
}

vector<int> iterativeInorder(Node *root) {
    if(!root) return {};
    stack<Node*> st;
    Node *node = root;
    vector<int> result;
    while(node != nullptr || !st.empty()) {
        if(node) {
            st.push(node);
            node = node->left;
        } else {
            // now we cnt go anymore left then we print because left root right
            node = st.top(); st.pop();
            result.push_back(node->data);
            node = node->right; // check for right
        }
    }
    return result;
}

vector<int> iterativeInorderUsing2Stacks(Node *root) {
    if(!root) return {};
    stack<Node*> st1, st2;
    vector<int> result;
    st1.push(root);
    while(!st1.empty()) {
        Node *node = st.top(); 
    }
}

vector<int> iterativePostorder(Node *root) {
    if(!root) return {};
    stack<Node*> st;
    st.push(root);
    vector<int> result;
    while(!st.empty()) {
        Node *node = st.top(); st.pop();
        result.push_back(node->data); 
        if(node->left) st.push(node->left); 
        if(node->right) st.push(node->right); 
    }
    reverse(result.begin(), result.end());
    return result;
}

// How Does This Help Achieve Postorder (Left, Right, Root)?
// Iterative postorder traversal using one stack works like this:

// Traverse as Root, Right, Left (by pushing left first, then right).

// Reverse the result at the end to get Left, Right, Root (postorder).

// Why Reverse?
// If you process nodes as Root, Right, Left and collect them in a result vector, reversing that vector gives you Left, Right, Root.



int main() {
    
    return 0;
}
