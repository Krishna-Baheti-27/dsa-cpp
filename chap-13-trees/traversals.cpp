#include<bits/stdc++.h>
using namespace std;

// Full Binary tree -> every node has either 0 or 2 children 
// Complete Binary Tree -> all levels are filled except possibly the last level which has nodes as left as possible  (this also balanced and has height of logN)
// Perfect Binary tree -> All leaf nodes are at the same level
// Balanced Binary tree -> Height of tree is at max logN (min height possible)
// Degenerate tree -> Essentially a singly linked list (every node has single child)

////////////////////////////////////////////////////////////////////////////////////

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

} // O(N) time to traverse all the nodes and O(N) recursion stack space 
// not considering the space to return the answer

// Option 2 (Purely recursive but less readable)

vector<int> preorderTraversalRecursive(Node *root) {

    if(root == nullptr) return {};

     // we have inserted the root in main result array, basically insert current node's data

    vector<int> result = {root->data};

    // find the left subarray for leftsubtree

    vector<int> left = preorderTraversalRecursive(root->left); 

    // find the right subarray for rightsubree

    vector<int> right = preorderTraversalRecursive(root->right); 

    // insert in the order root left right, so now insert left at the end of root

    result.insert(result.end(), left.begin(), left.end()); // inserting left, // O(N)

    result.insert(result.end(), right.begin(), right.end()); // inserting right // O(N)

    return result;

} // O(N^2) time in worst case since O(2N) for insertion of left and right subtree for one node and total N nodes and O(N) recursion stack space 


// Preorder traversal like this very we only print:

// similarly for postorder and inorder traversal

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

    left.push_back(result); // to maintain Left Root Right first insert root at end of left

    left.insert(left.end(), right.begin(), right.end());

    return left;

} // O(N^2) time in worst case and O(N) stack space

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

} // O(N^2) time in worst case and O(N) recursion stack space

///////////////////////////////////////////////////////////////////////////////////////

// VVIP Level order traversal

// here we use a queue to go level by level in which we store the children from left to right if they exist

vector<vector<int>> levelorderTraversal(Node *root) {

    if(!root) return {};

    vector<vector<int>> result;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {

        // size of the queue is the number of elements in queue in that level

        int size = q.size(); 

        vector<int> levelTraversal; // traversal for that level

        for(int i = 0; i < size; i++) {

            Node *node = q.front();

            q.pop(); // pop the node after you have got it

            levelTraversal.push_back(node->data);

            // we dont insert null values in our queue and insert in order from left to right and hence left first

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        result.push_back(levelTraversal); 
    }

    return result;

} // O(N) time since total N nodes are processed and O(N) space for queue

// Setting size = q.size(); at the start of each level ensures that you process only the nodes that are currently in the queue—which are exactly the nodes at the current level.
// Any children you add during this iteration are pushed to the back of the queue and will be processed in the next level (i.e., in the next iteration of the while loop).

////////////////////////////////////////////////////////////////////////////////////////////

// here we want to maintain the order of Root Left Right, so we go adding root->data to iur answer and first pushing root->right if exists then root->left so that if we have a left it will be popped out and processed first

vector<int> iterativePreorder(Node *root) {

    if(!root) return {};

    stack<Node*> st; // explicit stack to simulate recursion in an iterative algorithm
    vector<int> result;

    st.push(root);

    while(!st.empty()) {

        Node *node = st.top(); st.pop();

        result.push_back(node->data); // Root

        // push right first since we want to process left before right and stack is LIFO so right should be after left, so we would eventually traverse the left first

        if(node->right) st.push(node->right); // first right
        if(node->left) st.push(node->left); // then left
    }

    return result;

} // O(N) time since all nodes are processed and O(N) space for explicit stack

// this can also be done in other way since we are always popping the left node as soon as its inserted rather we keeping on inserting the left node while its not null and keeping pushing right and if it becomes null then we pop from the stack and set the right node popped to be current

// uses lesser space as we only push right nodes but still O(N) in worst case

vector<int> iterativePreorderBetter(Node *root) {

    if(!root) return {};

    vector<int> result;
    stack<Node *> st;

    Node *curr = root;

    while(curr != nullptr || !st.empty()) {

        while(curr != nullptr) {
            result.push_back(curr->data);
            if(curr->right) {
                st.push(curr->right);
            }
            curr = curr->left;
        }

        if(!st.empty()) {
            curr = st.top();
            st.pop();
        }
    }

    return result;
}

// instead of using this inner while loop we can write it simply in the below inorder stlye of if-else

vector<int> iterativePreorderUnified(Node *root) {
    if(!root) return {};

    stack<Node*> st;
    vector<int> result;
    Node *node = root;

    while(node != nullptr || !st.empty()) {

        if(node) {
            // PREORDER: Print/Process BEFORE going left
            result.push_back(node->data); 
            
            st.push(node);
            node = node->left;
        } else {
            // We have explored left, now backtrack
            node = st.top(); 
            st.pop();
            
            // In Preorder, we already printed 'node', so we just move right
            node = node->right;
        }
    }

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////////

// in the recursive version we went absolutely left and then printed and then moved right, so here we are doing exactly that of moving left till node is not null and pushing into the stack, once node becomes null we pop and add to the answer then we go on right

vector<int> iterativeInorder(Node *root) {

    if(!root) return {};

    stack<Node*> st;
    vector<int> result;

    Node *node = root;

    // do the iteration while either the node is not null or the stack still has elements to pop

    while(node != nullptr || !st.empty()) { 

        // if node is not null then push into the stack keep moving left

        if(node) {
            st.push(node);
            node = node->left;
        } else {

            // now we cnt go anymore left sp we pop and print and now left is done, then go right by node = node->right

            node = st.top(); st.pop();

            // we process node here at the backtracking stage and not while pushing like in preorder

            result.push_back(node->data);

            node = node->right; // check for right subtree
        }
    }

    return result;

} // O(N) time and O(N) space for explicit stack

/////////////////////////////////////////////////////////////////////////////////////////

// you have to remember the method or approach here there is nothing much we can do

// so we take 2 stacks st1 and st2 and we push root to st1
// so while st1 is not empty we pop from st1 and push the node in st2
// if node has left then we push it and if node has right then we push it after left

// once st1 is empty we simply pop from st2 and append to our answer

vector<int> iterativePostorderUsing2Stacks(Node *root) {

    if(!root) return {};

    vector<int> result; 
    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {

        Node *curr = st1.top(); st1.pop();

        st2.push(curr);

        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }  

    while(!st2.empty()) {

        result.push_back(st2.top()->data);
        st2.pop();
    }

    return result;

} // O(N) time and O(2N) space

//////////////////////////////////////////////////////////////////////////////////////

// but we dont actually need the extra stack, single stack would suffice, just store the answer in vector in reverse fashion if you know the number of nodes or store the answer as it is and reverse the result later

vector<int> iterativePostorderUsing1StackOptimal(Node *root) {

    if(!root) return {};

    vector<int> result; 
    stack<Node*> st1;
    st1.push(root);

    while(!st1.empty()) {

        Node *curr = st1.top(); st1.pop();

        result.push_back(curr->data);

        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }  

    reverse(result.begin(), result.end());

    return result;

} // O(N + N/2) time and O(N) space for stack (not considering the space to return the answer)

///////////////////////////////////////////////////////////////////////////////////////

// THE SUMMARY OF ENTIRE ITERATIVE TREE TRAVERSALS

// PRINT THIS SNIPPET IN YOUR BRAIN

// For preorder and inorder, Drive as far left as possible, then backtrack.

// Node* node = root;
// stack<Node*> st;

// while (node != NULL || !st.empty()) {
//     if (node != NULL) {
//         // WE ARE MOVING DOWN (LEFT)
//         // [Place A]
//         st.push(node);
//         node = node->left;
//     } else {
//         // WE ARE MOVING UP (BACKTRACKING)
//         node = st.top(); 
//         st.pop();
//         // [Place B]
//         node = node->right;
//     }
// }

// For Preorder (Root -> Left -> Right): You want to print the node as soon as you see it (before going left).

// Action: Insert print(node->data) at [Place A].

// For Inorder (Left -> Root -> Right): You want to print the node after you finish the left side and come back up.

// Action: Insert print(node->data) at [Place B].

// For postorder

// The Logic:

// Postorder is: Left -> Right -> Root

// Reverse of Postorder is: Root -> Right -> Left

// Root -> Right -> Left is just Preorder, but you visit the Right child before the Left child!

// so just modify the preorder to visit the right before left by pushing right later (to maintain LIFO) and then reverse the obtained traversal to get postorder

/////////////////////////////////////////////////////////////////////////////////////////////////

// THESE ARE TWO COMPLEX CODES BELOW AND NO NEED TO BE WRITTEN IN THE INTERVIEW SETTING, JUST UNDERSTAND, THE ABOVE MENTIONED TEMPLATE IS EASY TO WRITE AND EXPLAIN

////////////////////////////////////////////////////////////////////////////////////////

// the code using single stack and going like we do in recursion that is first all the way till left then print then go right and then again all the left of right, is a bit complex so i refrain from using it

// but still this is the code written in same style as in iterative preorder and inorder

vector<int> iterativePostorderUsing1Stack(Node *root) {
    
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

                temp = st.top(); st.pop(); // now make temp point to its parent

                result.push_back(temp->data); 

                while(temp == st.top()->right && !st.empty()) {
                    temp = st.top(); st.pop();
                    result.push_back(temp->data);
                } 

            } else {

                // if the right is not null then we check for left of right because it is left right root
                curr = temp; 
            }
        }
    }

    return result;

} // O(2N) time and O(N) space for explicit stack

////////////////////////////////////////////////////////////////////////////////////////

// this is the algorithm created which tracks the occurence or repeatition using which we can identify whether element is 

vector<vector<int>> allTraversals(Node *root) {

    if(!root) return {};

    vector<int> preorder, inorder, postorder;
    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()) {
        
        auto it = st.top(); st.pop();

        if(it.second == 1) {

            // this is the first time we are seeing this node since it.second == 1 and hence push into the preorder since in preorder we add the node as soon as we see it 

            preorder.push_back(it.first->data);
            it.second++; 
            st.push(it);

            // if there is left then go left (to complete seeing all nodes on left, same logic of driving as far left as possible then backtrack)

            if(it.first->left) {
                st.push({it.first->left, 1});
            }

        } else if(it.second == 2) {

            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            // this is the second time we are seeing this node and hence add it to the inorder because in inorder we add the node after we traverse its left subtree

            if(it.first->right) {
                st.push({it.first->right, 1});
            }

        } else {

            // this is the third time we are seeing this node and we have completed both left and right subtree traversals and hence add to the postorder

            postorder.push_back(it.first->data); 
        }
    }

    return {preorder, inorder, postorder};
    
}

//////////////////////////////////////////////////////////////////////////////////////

// using this trick of all traversals we find the simplified no reverse way of finding postorder iteratively by keeping the state of when the node was visited and it literally copies the cpu handling of recursion

// The Logic (easy to remember): We store {Node, State} in the stack.

// State 1: First time seeing node. -> Go Left.

// State 2: Second time (coming back from Left). -> Go Right.

// State 3: Third time (coming back from Right). -> Print Root (Postorder) & Pop.

vector<int> iterativePostorder(Node* root) {

    if (!root) return {};

    vector<int> result;
    stack<pair<Node*, int>> st; // Node and "State"

    st.push({root, 1}); // Start at state 1, every fresh node starts at 1

    while (!st.empty()) {

        // Get reference to modify state without having to pop and insert the updated state by just peeking at the top value and updating its state and we pop only when we are done with the traversal 

        auto& [node, state] = st.top(); 

        if (state == 1) { 

            state++; 
            if(node->left) {
                st.push({node->left, 1});
            }

        } else if(state == 2) {

            state++;
            if(node->right) {
                st.push({node->right, 1});
            }

        } else { 

            result.push_back(node->data); 

            // now delete the node since we are done with its traversal 

            st.pop();
        }
    }

    return result;

}


int main() {
    
    return 0;
}