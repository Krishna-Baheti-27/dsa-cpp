#include<iostream>
using namespace std;

bool isArraySortedBrute(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) return false;
        }
    }
    return true;
} // O(N^2)

bool isArraySortedOptimal(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i+1] < arr[i]) {
            return false; // since the adajacent consecutive elements are not in non-decreasing  order
        }
        // else move to next iteration
    }
    return true; // if no problem in whole loop then array is sorted in non-decreasing order
} // O(N)

bool isArraySortedRecursive(int arr[], int n, int index = 0) {
    if(index == n - 1) return true;  // reached the end
    if(arr[index + 1] < arr[index]) return false;
    return isArraySortedRecursive(arr, n, index + 1);
}
// recursive method

///////////   IS ROTATED ARRAY SORTED /////////////////

// A rotation involves shifting a contiguous block of elements to the back of the array, preserving the relative order of all elements.
// VVIP THE ORDER OF ELEMENTS SHOULD NOT CHANGE OR BE PRESERVED

bool isSortedRotated(int arr[], int n) { // check for sorted in non decreasing order
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[(i + 1) % n]) count++; 
        // found a decrease (the smaller element is after)
        // we basically wanted to check if arr[i] > arr[i + 1] so we would increase count but here array is rotated but sorted in circular wau hence we use (i + 1) % n which restricts and bounds in circular way
    }
    return count <= 1;
    // little edge case, if array consists of a single element like [1,1,1] then count remains zero and hence count == 0 also means sorted
    // if count == 1 exactly one drop this means either array is fully sorted or sorted-rotated
    // if count > 1 array is not sorted rotated
}


int main() {
    int arr[] = {1,2,2,3,100};
    int n = 5;
    cout << isArraySortedOptimal(arr,n) << '\n'; // 1 -> true, 0 -> false 
    return 0;
}