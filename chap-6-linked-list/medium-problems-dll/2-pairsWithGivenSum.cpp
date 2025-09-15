#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

// return all the pair which add up to sum in a sorted doubly linked list

vector<vector<int>> findAllPairsBrute(Node *head, int sum) {
    // check all pairs is the brute force solution
    if(!head) return {};
    vector<vector<int>> ans;
    Node *temp1 = head;
    while(temp1) {
        Node *temp2 = temp1->next;
        while(temp2) {
            int s = temp1->data + temp2->data;
            if(s == sum) ans.push_back({temp1->data, temp2->data});
            else if(s > sum) break;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
} // O(n^2) time and O(1) space

vector<vector<int>> findAllPairsOptimal(Node *head, int sum) {
    // since the list is sorted, we will use two pointer algo to solve it 
    Node *left = head, *right = head;
    vector<vector<int>> ans;
    while(right->next) right = right->next;
    // right now points ot last node
    while(left->data < right->data) {
        int s = left->data + right->data;
        if(s == sum) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(s > sum) right = right->prev;
        else left = left->next;
    } 
    return ans;
} // O(n + n) time and O(1) space
// since we are visiting evey element hence O(n) for while loop unlike in array reversal where we simply traverse half elementa simultaneously, but here also we are travesing half by left and half by right but not together or simultaneously but individually and hence O(N) time

int main() {
    
    return 0;
}