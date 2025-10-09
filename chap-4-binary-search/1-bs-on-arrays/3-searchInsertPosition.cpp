#include<iostream>
#include<vector>
using namespace std;

// They are simply asking the lower bound of that element, since insert position is simply the first index where arr[ind] >= key, key is the value you want to insert

int searchInsertPositionBrute(vector<int> &arr, int key) {
    // using linear search
    int i = 0;
    while(i < arr.size()) {
        if(arr[i] >= key) return i;
        else i++;
    }
    return i;
} // O(N) time

int searchInsertPositionOptimised(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // we basically have to find the lower_bound , arr[index] >= key return index;
        // But this question was asked only for array of unique elements
        if(arr[mid] >= key) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
} // O(logN) time using lower bound

int usingSTLSearchInsertPos(vector<int> &arr, int key) {
    auto it = lower_bound(arr.begin(), arr.end(), key);
    return it - arr.begin();
} // gives the answer right away


int main() {
    
    return 0;
}