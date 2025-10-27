#include<bits/stdc++.h>
using namespace std;

// next greater element is simply the first occuring element on the right which is just greater than the current element, next greater doesnt mean that it has to be consecutive
// 5 9 7 2, for 5 next greater is 9 even though 7 is least greater but here we are looking for the first occuring element which is just greater than 5

// single array
vector<int> nextGreaterElBrute(const vector<int> &arr) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        int j;
        for(j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                break;
            }
        }
        if(j < arr.size()) ans.push_back(arr[j]);
        else ans.push_back(-1);
    }
    return ans;
} // O(N^2) time and O(N) space

// using a monotonic stack
// a monotonic stack is something which stores the elements in a specific order according to the question and also obeys our LIFO Principle

// for next greater element we have to know the future elements which is not possible if we start our traversal from left to right and hence we start traversing from end to front (from back)

vector<int> nextGreaterElOptimal(const vector<int> &arr) {
    
    vector<int> ans(arr.size(), 0);
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        // we do this to maintain our monotonic order
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop(); // pop while stack is not empty or the top of stack is greater
        } 
        if(st.empty()) {
            ans[i] = -1; // entire stack became empty but we didnt find anything greater
            // no next greater element and hence -1
        } else {
            ans[i] = st.top(); // always handle the answer case at last
        }
        st.push(arr[i]); // always push into the stack regardless since  we have to keep track of next element
    }
    return ans;
} // O(2N) time is worst case since the outer loop runs for N times and the inner loop can run atmax total of N times in the whole iteration of outer loop, because from stack we are removing elements of array which cannot exceed N

// here we are using a monotonic stack because the elements are always stored in decreasing order and if the order is distorted we pop from stack, thus we are maintaining the monotonic order of the stack

/////////////////////   NOW NEXT GREATER LEETCODE STYLE FOR TWO ARRAYS

vector<int> nextGreaterEl2Brute(const vector<int> &arr1, const vector<int> &arr2) {
    // for each query in arr1, you have to find the nextgreater element of that query from arr2
    vector<int> ans;
    for(int i = 0; i < arr1.size(); i++) {
        int j;
        for(j = 0; j < arr2.size(); j++) {
            if(arr2[j] == arr1[i]) break;
        } // because it is guaranteed that each query in arr1 will be present in arr2
        // now we start looking from j + 1 th index for nextGreaterElement, and if not then -1
        while(j < arr2.size() - 1) {
            if(arr2[j + 1] > arr1[i]) {
                break;
            }
            j++;
        }
        if(j < arr2.size() - 1) ans.push_back(arr2[j + 1]);
        else ans.push_back(-1);
    }
    return ans;
} // O(N^2) time

// here we find the next greater element for every element in arr2 since that is what we have to do, 
// but we have to return them in the order that is mentioned in arr1 and hence then we iterate through arr1 and for each key arr1[i] we get the corresponding next greater stored

vector<int> nextGreaterEl2Optimal(const vector<int> &arr1, const vector<int> &arr2) {

    stack<int> st;
    unordered_map<int,int> mpp;
    for(int i = arr2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr2[i]) {
            st.pop();
        }
        if(st.empty()) mpp[arr2[i]] = -1; 
        else mpp[arr2[i]] = st.top();// here we find the next greater element for every element in arr2 since that is what we have to do, 
    // but we have to return them in the order that is mentioned in arr1 and hence then we iterate through arr1 and for each key arr1[i] we get the corresponding next greater stored
        st.push(arr2[i]);
    }
    
    vector<int> ans;
    for(int i = 0; i < arr1.size(); i++) {
        ans.push_back(mpp[arr1[i]]);
    }
    return ans;
} // O(2N + N) time and O(2N) space for stack and map

int main() {
    
    return 0;
}