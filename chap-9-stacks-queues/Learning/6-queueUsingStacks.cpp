#include<bits/stdc++.h>
using namespace std;

class Queue1 {
    stack<int> s1, s2;
    public:
    void push(int x) {
        // copy from s1 to s2
        while(!s1.empty()) {
            int el = s1.top(); s1.pop();
            s2.push(el);
        }
        // push into s1
        s1.push(x);
        // move from s2 to s1
        while(!s2.empty()) {
            int el = s2.top(); s2.pop();
            s1.push(el);
        }
    } // O(2n) time and O(2n) space for stacks
    void pop() {
        s1.pop();
    }
    int front() {
        return s1.top();
    }
    int back() {
        // copy from s1 to s2, then return s2.top() and then again copy from s2 to s1
        while(!s1.empty()) {
            int el = s1.top(); s1.pop();
            s2.push(el);
        }
        int backEl = s2.top();
        while(!s2.empty()) {
            int el = s2.top(); s2.pop();
            s1.push(el);
        }
        return backEl;
    }
    int size() {
        return s1.size();
    }
};

class Queue2 {
    stack<int> s1,s2;
    public:
    void push(int x) {
        s1.push(x); // directly push into s1
    }
    void pop() {
        if(!s2.empty()) {
            s2.pop();
        } else {
            // move from s1 to s2 and then pop
            while(!s1.empty()) {
                int el = s1.top(); s1.pop();
                s2.push(el);
            }
            s2.pop();
        }
    }
    int front() {
        if(!s2.empty()) {
            return s2.top();
        } else {
            // move from s1 to s2 then return
            while(!s1.empty()) {
                int el = s1.top(); s1.pop();
                s2.push(el);
            }
            return s2.top();
        }
    }
    int back() {
        if(!s1.empty()) {
            return s1.top();
        } else {
            // move from s2 to s1
            while(!s2.empty()) {
                int el = s2.top(); s2.pop();
                s1.push(el);
            }
            return s1.top();
        }
    }
    int size() {
        return s1.size() + s2.size();
    }
};
 
int main() {
    
    return 0;
}