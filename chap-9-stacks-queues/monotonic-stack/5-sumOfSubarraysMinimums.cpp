#include<bits/stdc++.h>
using namespace std;

int sumSubarraysMinsBrute(vector<int> &arr) {
    int sum = 0;
    int mod = 1e9 + 7; // for large answers
    for(int i = 0; i < arr.size(); i++) {
        int minEl = arr[i];
        for(int j = i; j < arr.size(); j++) {
            minEl = min(minEl, arr[j]);
            sum = (sum + minEl) % mod;
        }
    }
    return sum;
} // O(N^2) time and O(1) space

// for the array if we can find contribution of each element in the naswer then we can easily figure out the answer by summation of (contribution * element)
// now how to find contribution of each element, its pretty easy, you have to play with number of element on left and right which are just smaller than the element of each you want to find contribution
// For ex : 1 4 6 7 3 7 8 1, for 3 the next smaller element is at index 7 and the previous smaller element it at index 0 so contribution = (7 - index of 3) * (index of 3 - 0) = (7 - 4)*(4 - 0) = 12
// so 12 contribution of 3 so final contribution in aswer = 12*3 = 36

// to handle edge cases if there is no previous smaller index then return -1 and if there is not next smaller index then return n

vector<int> nextSmallerIdx(vector<int> &arr) {
    stack<int> st; // monotonic stack, we will be storing indexes not elemments because thats what we need
    vector<int> ans(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = arr.size();
        } else {
            ans[i] = st.top();
        } 
        st.push(i);
    }
    return ans;
}

vector<int> previousSmallerOrEqualIdx(vector<int> &arr) {
    stack<int> st;
    vector<int> ans(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop(); // just remove the greater ones not smaller or equal since we want 
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
  
int sumSubarraysMinsOptimal(vector<int> &arr) {
    int sum = 0, mod = 1e9 + 7;    
    vector<int> nextSmaller = nextSmallerIdx(arr);
    vector<int> prevSmaller = previousSmallerOrEqualIdx(arr);
    for(int i = 0; i < arr.size(); i++) {
        int left = i - prevSmaller[i];
        int right = nextSmaller[i] - i;
        sum  = (sum + (right * left * 1ll * arr[i]) % mod) % mod;
    }
    return sum;
} // O(2N + 2N + N) time and O(2N + 2N + 2N) space

int main() {
    
    return 0;
}