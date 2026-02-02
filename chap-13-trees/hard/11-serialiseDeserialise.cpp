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

// we have to write the code to first serialise or encode the binary tree into a string and then write code to deserialise or decode the binary tree again
// there can be various approaches and traversals possible for doing this here we are using level order traversal

//////////////////////////////////////////////////////////////////////////////////////

// now how can we uniquely determine the tree using only a single traversal, and hence we also account for null nodes in our serialise function so that we can deserialize it to a unique tree

string serialise(Node *root) {

    if(!root) {
        return "";
    }

    queue<Node*> q;
    q.push(root);

    string s = "";

    while(!q.empty()) {

        Node *node = q.front(); q.pop();

        if(!node) {
            s += "#,";
        } else {

            s += to_string(node->data) + ',';

            // push the nodes even if they are null since we are processing them

            q.push(node->left); 
            q.push(node->right);
        }
    }

    return s; // this is the encoded or serialised binary tree
}

Node *deserialise(string data) {

    if(data.length() == 0) {
        return nullptr;
    }

    stringstream s(data);
    string str; // we will use this initialise it again and again with new values
    getline(s, str, ','); // this means get the next guy from the string s which is separated by ',' in the string s and put it into str
    Node *root = new Node(stoi(str)); // string to integer function
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *node = q.front(); q.pop();
        // we are constructing using level order and on each level of each node first root then left then right
        // now get the next guy which woudld be left child of node
        getline(s,str,',');
        if(str == "#") node->left = nullptr; // left is nullptr
        else {
            // create a new node since it not null and that would be left child of our root
            Node *newNode = new Node(stoi(str));
            node->left = newNode;
            q.push(newNode); // push in the queue since its not nullptr
        }
        // now the get the next guy which woudld be right child of node
        getline(s,str,',');
        if(str == "#") node->right = nullptr;
        else {
            Node *newNode = new Node(stoi(str));
            node->right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

int main() {
    
    return 0;
}