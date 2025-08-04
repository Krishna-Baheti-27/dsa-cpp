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
        if(arr[i] > arr[(i + 1) % n]) count++; // found a decrease (the smaller element is after)
        // we basically wanted to check if arr[i] > arr[i + 1] so we would increase count but here array is rotated but sorted in circular wau hence we use (i + 1) % n which restricts and bounds in circular way
    }
    return count <= 1;
    // arr[i] > arr[(i+1) % arr.size()] checks if the current element is greater than the next, treating the array as circular. This is used to detect how many times the order decreases, which helps determine if an array is sorted and rotated.

    // to check if array is sorted we traversed it in linear fashion from start to end but for rotated array we will have to wrap around it like circular array to check how many time we see decrease

    // if count = 1, single time decrease, => rotated and sorted
    // if count = 0, zero time decrease => sorted
    // if count > 1, array is not sorted and rotated
}


int main() {
    int arr[] = {1,2,2,3,100};
    int n = 5;
    cout << isArraySortedOptimal(arr,n) << '\n'; // 1 -> true, 0 -> false 
    return 0;
}