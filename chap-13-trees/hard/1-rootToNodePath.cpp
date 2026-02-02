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

// we have to find the path from root to the particular target node which is given to us, if only have the value then we can search it and then apply the algorithm

////////////////////////////////////////////////////////////////////////////////////////

// if the tree had parent pointers where we could traverse up the tree then this problem would have been super simple but we dont have that so we have devise a solution using what we have

// here we are using preorder traversal which is super simple and intuitive

bool rootToNodePathHelper(Node *root, Node *target, vector<int> &arr) {

    if(!root) {
        return false; // did not found as node doesnt exist
    }

    arr.push_back(root->data); // if root is not null add it to the answer

    if(root == target) {
        return true; // found the node , no need to go to left or right
    }

    // if any one of left or right subtrees return true means we have found the target their and hence return true

    if(rootToNodePathHelper(root->left, target, arr) || rootToNodePathHelper(root->right, target, arr)) {
        return true; 
    }

    // since the target was not found on the left or right subtree and also on current node which means that this node is not present in the path from root to target and hence we initially inserted it because it was assumed it was present but since its not present we remove it

    // the backtracking step

    arr.pop_back(); // remove the inserted node and return false
    return false; 
}

vector<int> rootToNodePath(Node *root, Node *target) {

    vector<int> res;

    rootToNodePathHelper(root, target, res);

    return res;

} // O(N) time, O(N) recursion stack space in worst case, we dont consider space to return answer

/////////////////////////////////////////////////////////////////////////////////////

// we can apply the same logic if only the value is given to us and not the target since we can still search like this but then the question should state that tree only consists of unique values else we would have two different paths for which our code would fail, would return the first target which appears in preorder traversal

bool rootToNodePathValHelper(Node *root, vector<int> &arr, int target) {

    if(!root) {
        return false;
    }

    arr.push_back(root->data);

    if(root->data == target) {
        return true;
    }

    if(rootToNodePathValHelper(root->left, arr, target) || rootToNodePathValHelper(root->right, arr, target)) {
        return true;
    }

    arr.pop_back();

    return false;
}

vector<int> rootToNodePathVal(Node *root, int target) {

    vector<int> res;

    rootToNodePathValHelper(root, res, target);

    return res;

} // O(N) time and O(N) space

////////////////////////////////////////////////////////////////////////////////////////

// 2. Can we do this using BFS?
// Technically Yes, but it is inefficient. You are right to doubt it. Standard BFS does not keep a "history" of how you got to a node. To make BFS work for paths, you have two messy options:

// Heavy Queue: Store the entire path in the queue: queue<pair<Node*, vector<int>>>. This consumes massive memory.

// Parent Map: Use a map<Node*, Node*> parent to store where you came from. Once you find the target, you use the map to trace back up to the root.

// Verdict: Do not use BFS for pathfinding in trees unless you need the shortest path in a graph with cycles (which a tree is not). Stick to DFS.

////////////////////////////////////////////////////////////////////////////////////////

// now we generalise this for finding path from root to all nodes (from left to right as in preorder traversal)

// we have to store the path for each node and then with that stored check its left and right subtree and then when we backtrack we remove that and do this for all other nodes

void rootToAllHelper(Node *root, vector<vector<int>> &ans, vector<int> &arr) {

    if(!root) {
        return;
    }

    arr.push_back(root->data);

    ans.push_back(arr);

    rootToAllHelper(root->left, ans, arr);
    rootToAllHelper(root->right, ans, arr);

    arr.pop_back();
}

vector<vector<int>> rootToAll(Node *root) {

    vector<vector<int>> ans;
    vector<int> arr;

    rootToAllHelper(root, ans, arr);

    return ans;

} // O(N^2) time and O(N) space

// The traversal itself visits every node once, which is O(N). However, constructing and storing the path for every node requires copying the vector. In a skewed tree, the sum of all path lengths is O(N²), so the total time complexity is dominated by the output size, making it O(N²).

// for root to all with or without backtracking the time is O(N^2) but backstracking also saves memory and hence use it

//////////////////////////////////////////////////////////////////////////////////////

// in order for finding root to leaf only we save the path for leaf nodes only and the backtracking steps remain same

void rootToLeafHelper(Node *root, vector<vector<int>> &ans, vector<int> &arr) {

    if(!root) {
        return;
    }

    arr.push_back(root->data);

    if(!root->left && !root->right) {
        ans.push_back(arr);
    } else {
        rootToLeafHelper(root->left, ans, arr);
        rootToLeafHelper(root->right, ans, arr);
    }

    arr.pop_back();
}

vector<vector<int>> rootToLeaf(Node *root) {

    vector<vector<int>> ans;
    vector<int> arr;

    rootToLeafHelper(root, ans, arr);

    return ans;

} // O(NlogN) time and O(N) space

// since we insert only for leaves and there can be at max N / 2 leaves and in that case path length is simply height or logN and hence NlogN and in best case only O(N) (single leaf)

/////////////////////////////////////////////////////////////////////////////////////

// the leetcode stlye output solution of returning the path as string
// the solution is to not pass by reference but instead by value and hence thus we would not have to do any modification to our string s since that variable will be exclusive to that function call

void solve(Node *root, string s, vector<string> &ans) {

    if(!root) {
        return;
    }

    s += to_string(root->data);

    // here if its a leaf we add to the answer and return safely because here is no backtracking step hence return right away no need to make any modifications to the string since those are exlusive to this function call only

    if(!root->left && !root->right) {
        ans.push_back(s);
        return;
    }

    // if it is not the leaf then add the '->' since you dont want to add it for the first or the last node

    if(root->left) {
        solve(root->left, s + "->", ans);
    }

    if(root->right) {
        solve(root->right, s + "->", ans);
    }
}

vector<string> binaryTreePaths(Node *root) {

    vector<string> ans;
    string s = ""; 

    solve(root, s, ans);

    return ans;

} // O(N^2) time and O(N) space

// even though we are only going to insert for leaves but the time to copy the string (no reference) is O(N) at each step and hence O(N^2) time and not O(NlogN)

//////////////////////////////////////////////////////////////////////////////////////

// but the above code is bad since we are using excessive memory in each function call by copying the string into a new string so inefficient both memory and time wise and is bad for large constraints

// so we want to use the backstracking logic but since the integer can have more than one digit and hence using pop_back() does not work and hence we use .length() and resize() to properly clean up by finding length initially before function call and then resizing it to original during the backtracking step

void backTrackingHelper(Node *root, string &s, vector<string> &ans) {

    if(!root) {
        return;
    }

    int len = s.length();

    if(len > 0) {
        s += "->";
    }

    s += to_string(root->data);

    if(!root->left && !root->right) {
        ans.push_back(s);
    } else {
        backTrackingHelper(root->left, s, ans);
        backTrackingHelper(root->right, s, ans);
    }

    // the backtracking step of resizing the string back into its original length

    s.resize(len);
}

vector<string> binaryTreePathsBacktracking(Node *root) {

    vector<string> ans;
    string s = "";

    backTrackingHelper(root, s, ans);

    return ans;

} // O(NlogN) time and O(N) space

/////////////////////////////////////////////////////////////////////////////////////////

// The Confusion: People often confuse s += "x" with s = s + "x".

// s += "x": Modifies in place (Fast).

// s = s + "x": Creates a new temporary string, copies the old data, appends, and reassigns. (Slow).

// and also s.resize(len) does not create a new string but simply sets the internal pointer to point to len - 1 
  
int main() {
    
    return 0;
}