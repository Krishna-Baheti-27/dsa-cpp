#include<bits/stdc++.h>
using namespace std;

// Full Binary tree -> either 0 or 2 children for all nodes
// Complete Binary Tree -> all levels are filled except possibly the last level which has nodes as left as possible
// Perfect Binary tree -> All leaf nodes are at the same level
// Balanced Binary tree -> Height of tree is at max logN (min height possible)
// Degenerte tree -> Essentially a linked list (every node has single child in one direction)

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
} // similarly fro postorder and inorder
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

// level order
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

vector<int> iterativePreorder(Node *root) {
    if(!root) return {};
    stack<Node*> st; // explicit stack to simulate recursion in an iterative algorithm
    // Root Left Right
    vector<int> result;
    st.push(root);
    while(!st.empty()) {
        Node *node = st.top(); st.pop();
        result.push_back(node->data); // Root
        if(node->right) st.push(node->right); // push right first since stack is LIFO so right should be after left, so we would eventually traverse the left first
        if(node->left) st.push(node->left); // then left
    }
    return result;
}

vector<int> iterativeInorder(Node *root) {
    if(!root) return {};
    stack<Node*> st;
    Node *node = root;
    vector<int> result;
    // in the recursive version we went absolutely left and then printed and then moved right, so here we are doing that
    while(node != nullptr || !st.empty()) { // do the iteration while either the node is not null or the stack still has elements
        if(node) {
            st.push(node);
            node = node->left;
        } else {
            // now we cnt go anymore left then we print because left done, by printing root, and then if right exists then make node = node->right
            node = st.top(); st.pop();
            result.push_back(node->data);
            node = node->right; // check for right
        }
    }
    return result;
}

vector<int> iterativePostorderUsing2Stacks(Node *root) {
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        Node *curr = st1.top(); st1.pop();
        st2.push(curr);
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }  
    vector<int> result; 
    while(!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }
    return result;
} // O(N) time and O(2N) space, but we dont actually need the extra stack, single stack would suffice, just store the answer in vector in reverse fashion if you know the number of nodes or store the answer as it is and reverse the result later


vector<int> iterativePostorderUsing1StackOptimal(Node *root) {
    stack<Node*> st1;
    vector<int> result; 
    st1.push(root);
    while(!st1.empty()) {
        Node *curr = st1.top(); st1.pop();
        if(curr) {
            result.push_back(curr->data);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
    }  
    reverse(result.begin(), result.end());
    return result;
}


vector<int> iterativePostorderUsing1Stack(Node *root) {
    // it says Left Right root, so what we have to do in go till absolute left, putting everything in stack, then go to right and again check for left, if no left then we add it to the answer and again check if right exists then add and so on
    if(!root) return {};
    stack<Node*> st;
    vector<int> result;
    Node *curr = root, *temp;
    while(curr != nullptr || !st.empty()) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            temp = st.top()->right;
            if(temp == nullptr) {
                temp = st.top(); st.pop(); // we have traverse all left then right and then we pop, but we keep the parent in mind
                result.push_back(temp->data); // finally adding root (once both left and right checked)
                while(temp == st.top()->right && !st.empty()) {
                    temp = st.top(); st.pop();
                    result.push_back(temp->data);
                } 
            } else {
                curr = temp; // if the right is not null then we check for left of right because it is left right root
            }
        }
    }
    return result; // O(2N) time
}

vector<vector<int>> allTraversals(Node *root) {
    if(!root) return {{}};
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> preorder, inorder, postorder;
    while(!st.empty()) {
        // this is the algorithm created which tracks the occurence or repeatition using which we can identify whether element is 
        auto it = st.top();
        st.pop();
        if(it.second == 1) {
            preorder.push_back(it.first->data);
            it.second++; 
            st.push(it);
            // this is preorder hence we push left
            if(it.first->left) st.push({it.first->left, 1});
        } else if(it.second == 2) {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            // this is inorder and hence we push right
            if(it.first->right) st.push({it.first->right, 1});
        } else {
            postorder.push_back(it.first->data); // hence at the last we have root and we dont push it anywhere
        }
    }
    return {preorder, inorder, postorder};
}


int main() {
    
    return 0;
}