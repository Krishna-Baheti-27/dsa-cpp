#include<bits/stdc++.h>
using namespace std;

// you have to return an array containing max from each window of given length k, and on each iteration we slide the window by 1

vector<int> maxSlidingWindowBrute(vector<int> &arr, int k) {
    // brute involves generating all possible windows and finding max of each window and going from there
    int left = 0, right = k - 1;
    // so [left, right] is our current window
    vector<int> arr;
    while(right < arr.size()) {
        int maxel = *max_element(arr.begin() + left, arr.begin() + right + 1);
        arr.push_back(maxel);
        // now shift the window by one place
        left++;
        right++;
    }
    return arr;
} // O(no. of windows * k) which is same as O(n - k) * O(k) time
// O(no. of windows) which is same as O(n - k) space

// vector<int> maxSlidingWindowOptimal(vector<int> &arr, int k) {
//     // now we have to reduce the time spend in findinf max element of each windw that is O(k) because of that we are getting N^2 time
//     int left = 0, right = k - 1;
//     vector<int> arr;
//     int maxel = *max_element(arr.begin() + left, arr.end() + right + 1);
//     arr.push_back(maxel);
//     left++;
//     right++;
//     while(right < arr.size()) {
//         if(arr[right] > maxel) maxel = arr[right];
//         arr.push_back(maxel);
//         left++;
//         right++; 
//         // move the window ahead
//     }
//     return arr;
// } // Whats wrong here is that, once the we expand the window we only check for arr[right] if it can be maximum, but when we change the window it might be that arr[left] was maximum which we discarded, and to ensure that we again have to do linear scan to find max element and hence, this is not the correct or optimal approach


// THE OPTIMAL APPROACH USES A DEQUE TO GIVE US PUSH_BACK AND POP_FRONT FUNCTIONALITY WHICH IS CRUCIAL SINCE  WE WANT TO KEEP ONLY THE WINDOW ELEMENTS IN OUR DEQUE

// now once we have a window, to find the max element, in that window we were initially scanning the entire the window which was taking us O(k), instead we maintain a monotonic stack in decreasing order so that we can get the min element in constant time

vector<int> maxSlidingWindowOptimal(vector<int> &arr, int k) {
    vector<int> ans;
    deque<int> dq;
    for(int i = 0; i < arr.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // to maintain montonicallt greater elements
        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) ans.push_back(arr[dq.front()]);  
    }
    return ans;
} // O(2N) time in worst case
// O(k) for deque + O(n - k) space for ans,


int main() {
    
    return 0;
}