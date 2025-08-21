#include<bits/stdc++.h>
using namespace std;

// using single queue
class Stack1 {
    queue<int> q;
    public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 1; i <= size; i++) {
            int el = q.front();
            q.pop();
            q.push(el);
        }
    } // making push costly takes O(N) time, where N is the number of elements in queue 
    void pop() {
        q.pop();
    }
    int size() {
        return q.size();
    }
    int top() {
        return q.front();
    }
};

int main() {
    
    return 0;
}