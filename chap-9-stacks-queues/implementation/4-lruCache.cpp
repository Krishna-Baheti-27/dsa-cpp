#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    class Node {
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, Node*> mpp;
    int cap;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    void insertAfterHead(Node *newNode) {
        Node *headNext = head->next;
        newNode->next = head->next;
        newNode->prev = head;
        head->next = newNode;
        headNext->prev = newNode;
    }

    void deleteNode(Node *delNode) {
        Node *delprev = delNode->prev;
        Node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        // we dont actually delete but just disconnect since we want to insert this after head
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1; // does not exist
        Node *node = mpp[key];
        // now delete this node and move it right next to head
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node *node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if(mpp.size() == cap) {
                // if cache is full then delete the least recently used node
                Node *node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            // now insert the new node after the head
            Node *newNode = new Node(key,value);
            mpp[key] = newNode; // insert in map
            insertAfterHead(newNode); // insert in cache
        }
    }
};

int main() {
    
    return 0;
}