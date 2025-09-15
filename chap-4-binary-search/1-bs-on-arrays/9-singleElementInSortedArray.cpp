#include<bits/stdc++.h>
using namespace std;

// we have already done single element in an unsorted array and best solution was using xor in linear time, but here we can take advantage of the fact that array is sorted and do it in logN time

int singleElBrute(vector<int> &arr) {
    // when we are standing at a index, then either index - 1 or index + 1 ought to have the same element, if both dont then that element is single
    if(arr.size() == 1) return arr[0]; // only single
    if(arr[0] != arr[1]) return arr[0]; // it ought to be since there is no one on the left of arr[0]
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // it ought to be since there is no one on the right of arr[arr.size() - 1]
    // for rest of the elements
    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i - 1] != arr[i] && arr[i + 1] != arr[i]) return arr[i];
    }
    return -1; // would not be reuqired just to avoid warnings
    // O(N) time in worst case
}


// very simple logic, do not complicate it
// (even, odd) => we are on left but element on right and hence eliminate left // low = mid + 1
// (odd, even) => we are on right but element on left and hence eliminate right // high = mid - 1

int singleElOptimal(const vector<int> &arr) {
    if(arr.size() == 1 || arr[0] != arr[1]) return arr[0]; // because array is sorted
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // array is sorted
    int low = 1, high = arr.size() - 2; // eliminating edge cases and starting from 1 to n - 2
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 != 0 && arr[mid] == arr[mid - 1])) {
            low = mid + 1; // (even, odd)
        }
        if((mid % 2 != 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 0 && arr[mid] == arr[mid - 1])) {
            high = mid - 1; // (odd, even)
        }
    }
    return -1;
}

int main() {
    
    return 0;
}