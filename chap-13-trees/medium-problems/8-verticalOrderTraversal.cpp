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

// we have to write a vertical order from left to right and top to bottom, in case of overlapping nodes, take the smaller value first and in case of duplicate nodes take both the value

//////////////////////////////////////////////////////////////////////////////////

// what we have to do is assign a vertical or x coordinate (for root we have x = 0 and y = 0) and also level or y corrdinate so that each node can be uniquely identified
// once we have done that, then we traverse in ascending order of vertical or x and for each vertical we travel in ascending order of level or top to bottom from level = 0 to the last level

// to asign the coordinates to all the nodes we can use any traversal of choice and here we are using level order traversal since its bit easy to maintain level there in place of any recursive traversal

// marking coordinates using BFS or level order traversal

void markCoordinates(Node *root, map<int, map<int, multiset<int>>> &mpp) {

    queue<pair<Node*, pair<int,int>>> q;
    q.push({root, {0,0}}); // will store {node, {vertical, level}}

    while(!q.empty()) {

        int size = q.size();

        for(int i = 0; i < size; i++) {

            auto p = q.front(); q.pop();

            Node *node = p.first;
            int x = p.second.first, y = p.second.second;

            mpp[x][y].insert(node->data); // insert the given node at vertical x and level y

            if(node->left) {
                q.push({node->left, {x - 1, y + 1}}); // if we go left then x - 1
            }

            if(node->right) {
                q.push({node->right, {x + 1, y + 1}}); // if we go right then x + 1
            }
        }
    }
} // O(NlogN) time since O(logN + logN + logN) to insert in the map of map of multiset

 vector<vector<int>> verticalOrderTraversal(Node *root) {

    vector<vector<int>> ans; // to return the traversal

    // the map will store all verticals in sorted order from left to right, each vertical will have some levels, and each level can have more than one elements and we have to store them in sorted order and this may also contain duplicates and thats why we use multiset

    map<int, map<int, multiset<int>>> mpp; 

    // for vertical x we have y levels and each level has can have n number of elements (can have duplicates) which we have to store in sorted order using multiset

    markCoordinates(root, mpp); // mark all the nodes in map according to x, y and n

    // now we traverse the map in increasing order of vertical, and for each vertical in increasing order of level and we store our traversal for each vertical

    // verticals.first refers to the vertical and verticals.second refers to map which is collection of levels for that vertical
    
    for(auto verticals : mpp) { 
       
        vector<int> vertiTrav; // to store traversal for this vertical

        // here levels.first refers to a particular level from the levels in verticals.second, and levels.second refers to the multiset of nodes for that level and vertical, so we have to insert each multiset of nodes in incresing order of level for a given vertical

        for(auto levels : verticals.second) {

            // always insert in end since we have maintain the order of level by level

            vertiTrav.insert(vertiTrav.end(), levels.second.begin(), levels.second.end());  
        }

        ans.push_back(vertiTrav); // in ans we maintain the traversal vertical by vertical
    }

    return ans;

} // if you take a close look we are essentially traversing every single node once when forming this traversal and hence O(NlogN) for marking coordinates + O(N) for creating traversal
// O(2N) space for queue + map

//////////////////////////////////////////////////////////////////////////////////////

// but this approach is not faster in practice although does work beacause maps are scattered points in memory where memory allocation and deallocation of pointers make it a bit slow on real hardware

// the solution is to use a vector instead of map which is not as complex and extremely fast

// The Logic:

// Traverse the tree (BFS or DFS).

// Store every node as a tuple: {x, y, value}.

// Sort the list using a custom comparator that follows the rules:

// Rule 1: Smallest x first (Left to Right).

// Rule 2: Smallest y first (Top to Bottom).

// Rule 3: Smallest value first (For overlapping nodes).

// the above code is much easier to write and reason about in an interview setting

// now instead of using a vector of pairs (and sort it) we use struct just to make code readable and a comparator but this adds extra lines of code so be careful

struct Point {
    int x, y, val;
};

bool comp(Point a, Point b) {
    
    if(a.x != b.x) {
        return a.x < b.x;
    }

    if(a.y != b.y) {
        return a.y < b.y;
    }

    return a.val < b.val;
}

vector<vector<int>> verticalOrderTraversalReadable(Node *root) {

    if(!root) {
        return {};
    }

    // flatten the tree into the list of Points or tuples {x,y,val}

    vector<Point> nodes;

    // use the bfs to store the flattened tree into our list of Points
    
    queue<pair<Node*, pair<int,int>>> q;
    q.push({root, {0,0}});

    while(!q.empty()) {

        auto p = q.front(); q.pop();

        Node *node = p.first;
        int x = p.second.first, y = p.second.second;

        nodes.push_back({x, y, node->data});

        if(node->left) {
            q.push({node->left, {x - 1, y + 1}});
        } 

        if(node->right) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    sort(nodes.begin(), nodes.end(), comp);  // O(NlogN) time

    vector<vector<int>> ans;

    for(int i = 0; i < nodes.size(); i++) {

        if(i == 0 || nodes[i].x != nodes[i - 1].x) {
            ans.push_back({});
        }

        ans.back().push_back(nodes[i].val);
    }

    return ans;

} // O(NlogN) time and O(3N) space for queue and O(3N) space for Points array not considering the space to return the answer

int main() {
    
    return 0;
}