#include<bits/stdc++.h>
using namespace std;

// We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
// So, in order to solve this problem, we have to find the index of the minimum element.

int noOfRotationsBrute(const vector<int> &arr) {
    int minIdx = 0; // uses linear search , O(N) solution
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < arr[minIdx]) minIdx = i;
    }
    return minIdx; // index of minimum element or minIndex is the number of times the array has been rotated
}

int noOfRotationsOptimal(const vector<int> &arr) {
    int minIdx = 0, minel = INT_MAX; // uses binary search, O(logn)
    // already done this in the question, find min in rotated sorted array
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // you have to introduce the case of 
        // arr[low] == arr[mid] && arr[mid] == arr[high]
        if(arr[low] <= arr[mid]) {
            // left part is sorted
            if(arr[low] < minel) {
                minel = arr[low];
                minIdx = low;
            } // we cant use min function since we would not be able to determine the index
            low = mid + 1;
        } else if(arr[mid] <= arr[high]) {
            // right part is sorted
            if(arr[mid] < minel) {
                minel = arr[mid];
                minIdx = mid;
            }
            high = mid - 1;
        }
    }
    return minIdx; // this is the number of rotations in rotated sorted array
}

int main() {
    
    return 0;
}