#include<iostream>
#include<vector>
using namespace std;

// They asking for the index of target if found and if not then find the index where it were to be inserted in order to maintain the array sorted

////////////////////////////////////////////////////////////////////////

// using linear search

int searchInsertPositionBrute(vector<int> &arr, int key) {
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= key) return i;
    }

    return arr.size(); // no position to insert
    
} // O(N) time

/////////////////////////////////////////////////////////////////////

int searchInsertPositionOptimised(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1, ans = arr.size();

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // we basically have to find the lower_bound , arr[index] >= key return index;
        // But this question was asked only for array of unique elements so as soon as arr[ind] == key then we have our answer else find the position to insert

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