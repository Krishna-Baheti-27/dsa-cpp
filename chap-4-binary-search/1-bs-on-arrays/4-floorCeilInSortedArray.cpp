#include<iostream>
#include<vector>
using namespace std;

// largest number <= key in array is the floor value of key in that array

/////////////////////////////////////////////////////////////////////////

// brute force linear search solution

int floorInSortedArrayBrute(vector<int> &arr, int key) {
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i] <= key) return arr[i];
    }
    return -1;
} // O(N) time

///////////////////////////////////////////////////////////////////////

// optimised solution using binary search since array is sorted

int floorInSortedArrayOptimised(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1, ans = -1; // since array has positives only

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] <= key) {
            ans = arr[mid]; // posible answer 
            low = mid + 1; // looking for even larger on right
        } else {
            high = mid - 1; // try to reach the answer
        }
    }

    return ans;

} // O(logN) time

/////////////////////////////////////////////////////////////////////////////

// smallest number >= key in array is the ceil value of key in that array

////////////////////////////////////////////////////////////////////////////

// brute force solution using linear search

int ceilInSortedArrayBrute(vector<int> &arr, int key) {

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= key) return arr[i];
    }

    return -1;

} // O(N) time

////////////////////////////////////////////////////////////////////////

// using binary search since array is sorted

int ceilInSortedArrayOptimised(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1, ans = -1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] >= key) {
            ans = arr[mid]; // possible answer
            high = mid - 1; // looking on left for even smaller
        } else {
            low = mid + 1; // try to reach answer
        }
    }

    return ans;

} // O(logN) time

int main() {
    
    return 0;
}