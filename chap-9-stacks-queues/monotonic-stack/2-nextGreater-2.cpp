#include<bits/stdc++.h>
using namespace std;

// here we have to check all the way considering the array is circular

// the most naive solution would be using a outer loop from 0 to n - 1 and then for each element, run loop from i + 1 to n - 1 and if not found then from 0 to i - 1 this basically does what they asked, that is to check around the array in circular fashion

// the more better approach is for each element we have to check next n - 1 elements in circular fashion so for ith element, start checking from i + 1 to i + n - 1 (next n - 1 elements) and if you dont find anyone greater than thats -1

vector<int> nextGreater2Brute(const vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        // starting for each element arr[i], we will start from i + 1 and search next n - 1 elements since n is size of array so, it is i + 1 + n - 1, so i + n elements or index wise till i + n - 1 index
        int index, j;
        bool found = false;
        for(j = i + 1; j < i + n; j++) {
            index = j % n; 
            if(arr[index] > arr[i]) { // found the next greater
                ans.push_back(arr[index]);
                found = true;
                break;
            }
        }
        if(!found) ans.push_back(-1);
    }
    return ans;
} // O(N^2) time

// now the optimal using montonic stack, we traversed from the back since we needed to know future elements, here for array 2 10 12 1 11, if we start from 11, according to circular definition we would have to check from 2 10 12 1, so its better to assume we have hypothetically doubled the array, 2 10 12 1 11 2 10 12 1 11 so we have indexes from 0 to 9 (2*n - 1) and we start maintaining the order of our monotonic stack from back but we find the nge only for elements having index < n, since they are our real array elements

vector<int> nextGreater2Optimal(const vector<int> &arr) {
    
    stack<int> st;
    vector<int> ans(arr.size());
    for(int i = 2 * arr.size() - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i % arr.size()]) {
            st.pop(); // here we maintain the monotonic order of stack
        }

        // this are the elements for which we have to find next greater element or our answer
        // not for elements for which i >= arr.size() (they are hypothetical, but we still have to maintain monotonic stack order for them)

        if(i < arr.size()) {
            if(st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
        } 

        st.push(arr[i % arr.size()]); 
        // at total we end up pushing 2N elements hence we also pop 2N elements
    } 
    return ans;
} // O(2N + 2N) = O(4N) time and O(2N) space 

int main() {
    
    return 0;
}