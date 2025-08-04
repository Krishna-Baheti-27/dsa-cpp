#include<bits/stdc++.h>
using namespace std;

// you can implement it by scanning the whole stack and finding minimum but it will take O(N) so we maintain a el variable so with each push operation we update el so that we get el in O(1) time

class StackBrute {
    public:
    stack<pair<int,int>> st;
    void push(int x) {
        if(st.empty()) st.push({x,x});
        else st.push({x,min(x,st.top().second)});
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
    int size() {
        return st.size();
    }
};

// class StackOptimised {
//     public:
//     int minel = INT_MAX;
//     stack<int> st;
//     void push(int x) {
//         if(x < minel) minel = x;
//         st.push(x);
//     }
//     void pop() {
//         if(st.top() == minel) {
            // INCORRECT AS YOU DONT KNOW WHAT HAPPENS WHEN YOU DELETE THE MIN ELEMENT, YOU CANT FIND THE NEW MIN
//         } else st.pop();
//     }
//     int top() {
//         return st.top();
//     }
//     int getMin() {
//         return minel;
//     }
//     int size() {
//         return st.size();
//     }
// };

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            // found a new min hence push it
            minSt.push(val);
        } else {
            minSt.push(minSt.top()); // else Maintain previous min
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop(); // Always pop from minSt to preserve history, basically who was the element at each step is preserved by minST just like it was preserved by second value of pair
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
}; // BUT STILL THIS IS O(2N) solution

class StackOptimal {
    stack<int> st;
    int minel = INT_MAX;
    public:
    // optimal solution taking only O(N) time
    void push(int x) {
        if(st.empty()) {
            minel = x;
            st.push(x);
        } else {
            if(x < minel) {
                // insert the modified value
                st.push(2*x - minel);
                minel = x;
            } else st.push(x);
        }
    }
    void pop() {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < minel) {
            // we know x is modified value and not the original value pushed, hence set the min to newMin in stack
            minel = 2*minel - x;
        }   
    }
    int top() {
        if(st.empty()) return -1;
        int x = st.top();
        if(x < minel) {
            return minel; // since x was not original, and actual element was minel 
        } 
        return x; // if it was original
    }
};

int main() {
    
    return 0;
}