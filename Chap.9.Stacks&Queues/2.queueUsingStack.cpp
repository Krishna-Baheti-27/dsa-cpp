#include<bits/stdc++.h>
using namespace std;

class Queue1 {
    // making push or enqueue costly
    public:
    stack<int> s1,s2;
    void push(int x) {
        // move all from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // push the new element in s1
        s1.push(x);
        // move all elements from s2 to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        // push takes O(2N)
    }
    int size() {
        return s1.size();
    }
    int pop() {
        s1.pop();
    }
    int front() {
        return s1.top();
    }
};

class Queue2 {
    // making front and pop more expensive but still better 
    public:
    stack<int> s1,s2;
    void push(int x) {
        s1.push(x);
    }
    void pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        } else {
            s2.pop();
        }
    }
    int front() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        } else {
            return s2.top();
        }
    }

    int size() {
        return s1.size() + s2.size();
    }
};


int main() {
    
    return 0;
}