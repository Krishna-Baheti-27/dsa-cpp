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

int singleElOptimal(const vector<int> &arr) {
    // O(logN) solution since array is sorted
    if(arr.size() == 1) return arr[0]; // only element
    if(arr[0] != arr[1]) return arr[0]; // it ought to be since there is no one on the left of arr[0]
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // it ought to be since there is no one on the right of arr[arr.size() - 1]

    // now we start our search space excluding the first and last element
    int low = 1, high = arr.size() - 2;
    // (even, odd) we are on the left half, hence look on right
    // (odd, even) we are on the right half, hecne look on left
    // for our target we would have both the elements on left and right to be not equal to it
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid]; // or single
        // now we have to eliminate either half
        if(mid % 2 != 0 && arr[mid] == arr[mid - 1]) {
            // we are standing on an odd index and the it is equal to element on even index pn left, which means , we are on left half, element in on right, hence eliminate left half
            low = mid + 1;
        }
        if(mid % 2 != 0 && arr[mid] == arr[mid + 1]) {
            // we are standing on odd index and and it is equal to element on even index on right,we are on right half, element is on left, hecne eliminate right half
            high = mid - 1;
        }
        if(mid % 2 == 0 && arr[mid] == arr[mid + 1]) {
            // we are at even index and it is equal to element on odd index on right, we are on left, element in on right, hence eliminate left
            low = mid + 1;
        }
        if(mid % 2 == 0 && arr[mid] == arr[mid - 1]) {
            // we are at even idnex and it is equal to element on odd index on left, we are on right, element is on left, hecne eliminate right
            high = mid - 1;
        }
    }
    return -1;
}

// finally understand this to get anwer
// I'm on (even, odd), the element occurs after me, so eliminate everything before me (the left half)
// If I'm on (odd, even), the element occurred before me, so eliminate everything after me (the right half)

int singleElOptimalProper(const vector<int> &arr) {
    if(arr.size() == 1 || arr[0] != arr[1]) return arr[0];
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1];
    int low = 1, high = arr.size() - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 != 0 && arr[mid] == arr[mid - 1])) {
            low = mid + 1;
        }
        if((mid % 2 != 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 0 && arr[mid] == arr[mid - 1])) {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    
    return 0;
}