#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    queue<int> q;
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 1; i <= s; i++) {
            q.push(q.front());
            q.pop(); 
        }
        // O(N) time for push
    }
    int size() {
        return q.size();
    }
    void pop() {
        q.pop();
    }
    int top() {
        return q.front();
    }
};

class Stack2 {
    // making deletion or pop costly
    public:
    queue<int> q1,q2;
    void push(int x) {
        q1.push(x);
    }
    void pop() {
        // move all elements from q1 to q2 except last element
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // we delete the topmost or front element now (pop achieved)
        swap(q1,q2); // since now all elements of q1 are in q2
    }
    int top() {
        // move all elements from q1 to q2 except last element
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topMost = q1.front();
        // now push the top most element now in q2
        q2.push(topMost);
        q1.pop();
        swap(q1,q2);
        return topMost;
    }
};

class Stack3 {
    // making insertion or push costly
    public:
    queue<int> q1,q2;
    void push(int x) {
        // move elements from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // push the element to be inserted in q1
        q1.push(x);
        // move all elements from q2 to q1 back
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    } // takes O(2N) time
    int top() {
        return q1.front();
    }
    void pop() {
        q1.pop();
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}