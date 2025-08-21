#include<bits/stdc++.h>
using namespace std;

// Brute solution involves traversing through entire stack each time for finding min hence O(N)

class minStackBetter {
    int min;
    stack<pair<int,int>> st;
    public:
    minStackBetter() {
        min = INT_MAX;
    }
    void push(int x) {
        if(x < min) min = x;
        st.push({x,min});
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
};

class minStackBetter2 {
    stack<int> st;
    stack<int> minStack;
    public:
    void push(int x) {
        st.push(x);
        if(minStack.empty() || x <= minStack.top()) minStack.push(x);
        // we only the store the minimum or lesser values in minStack so we dont have to delete every element when we pop from main stack
    }
    void pop() {
        if(st.top() == minStack.top()) {
            // you are actually deletinh the minimum element from main stack and hence also remove from minStack
            minStack.pop();
        }
        st.pop(); // remove from main stack regardless
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minStack.top();
    }
};

class minStackOptimal {
    stack<long long> st;
    long long min;
    public:
    void push(int x) {
        if(st.empty()) {
            min = x;
            push(x);
        } else if(x >= min) {
            st.push(x);
        } else {
            push(2LL*x - min); // when we are pushing a new minimum in the stack, instead of pushing it as it is, we store the encoded value which is 2*newMin - existinMin, this is done so that later we can get the previousMin or exisitingMin from this encoded value
            min = x;
        }
    }
    void pop() {
        if(st.top() >= min) st.pop(); // we havent done any encoding simply pop
        else {
            // st.top() < min which means we are popping a minimum element and we need to go back to previosMin or existingMin
            // now st.top() = 2*newMin - existingMin
            // we want know existingMin or previousMin (both are same)
            // existingMin = 2*newMin - st.top()
            min = 2*min - st.top(); // go back to the previousMin or existingMin
            st.pop(); // now safely pop
        }
    }
    int top() {
        if(st.top() >= min) return st.top(); // actual top stored
        else {
            // in this case we didnt store the actual number which wa minimum and we encoded it, so we cannot directly return st.top(), we return min (which was actual top)
            return min;
        }
    }
    int getMin() {
        return min;
    }
};

int main() {
    
    return 0;
}