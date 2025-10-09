#include<bits/stdc++.h>
using namespace std;

int findMinBrute(vector<int> &arr) {
    // uses linear search, all elements are unique
    int min = INT_MAX;
    for(int num : arr) if(num < min) min = num;
    return min == INT_MAX ? -1 : min;
}

// Using binary search algo

// our approach is pretty simple
// we go and identify the sorted part of array, then we compare our minel with smallest part of sorted array and then we go to other side for finding potentially smaller element

int findMinOptimal(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, minel = INT_MAX;
    while(low <= high) {

        // happens only when array is sorted or has been rotated by k = arr.size() 
        if(arr[low] <= arr[high]) { 
            return min(arr[low], minel); 
        } // to return early

        int mid = low + (high - low) / 2;

        // left part is sorted
        if(arr[low] <= arr[mid]) {
            minel = min(arr[low], minel); // our possible minimum element
            low = mid + 1; // but we look for even samller on right side, why do we look on right side ??, because we have already found the minel from the left side since left part was sorted, the minel was arr[low], now we have to also look on right side for finding a potentially smaller element
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