#include<bits/stdc++.h>
using namespace std;

int findMinBrute(vector<int> &arr) {
    // uses linear search, all elements are unique
    int min = INT_MAX;
    for(int num : arr) if(num < min) min = num;
    return min == INT_MAX ? -1 : min;
}

int findMinOptimal(vector<int> &arr) {
    // Using binary search algo
    int low = 0, high = arr.size() - 1, minel = INT_MAX;
    while(low <= high) {
        if(arr[low] <= arr[high]) { // happens only when array is sorted or has been rotated by k = arr.size()
            return min(arr[low], minel); 
        } // to return early
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]) {
            // left part is sorted
            minel = min(arr[low], minel); // our possible minimum element
            low = mid + 1; // but we look for even samller on right side, why do we look on right side ??, because we have already found the minel from the left side since left part was sorted, the minel was arr[low]
        } else if(arr[mid] <= arr[high]) {
            // right part is sorted
            minel = min(arr[mid], minel); // our possible minimum element 
            high = mid - 1; // but we look for even smaller on left side, why do we look on left side ??, because we have already found the minel from the right side since right part was sorted, the minel was arr[mid]
        }
    }
    // this is O(logN) solution since any part ought to be sorted in  rotated sorted array
    return minel;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2,-1};
    cout << findMinBrute(arr) << endl;
    cout << findMinOptimal(arr) << endl;
    return 0;
}