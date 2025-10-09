#include<bits/stdc++.h>
using namespace std;

// return the only single element where everyone else appears twice

// we have already done single element in an unsorted array and best solution was using xor in linear time, but here we can take advantage of the fact that array is sorted and do it in logN time

// when we are standing at a index, then either index - 1 or index + 1 ought to have the same element, if both of them dont then that element is single

int singleElBrute(vector<int> &arr) {

    // handling edge cases
    if(arr.size() == 1) return arr[0]; // only single
    if(arr[0] != arr[1]) return arr[0]; // it ought to be since there is no one on the left of arr[0]
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // it ought to be since there is no one on the right of arr[arr.size() - 1]
    // for rest of the elements

    // checking for indices [1, n - 2]
    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i - 1] != arr[i] && arr[i + 1] != arr[i]) return arr[i];
    }
    return -1; // would not be reuqired just to avoid warnings
} // O(N) time in worst case

// The logic for optimal solution

// for the single element, if you look on its left, you will find pairs of same integers but their indices obeying (even, odd) but on the right side of single element we will find pairs of same integers but their indices obeying (odd, even)

// this is how we reach our single element, but how do we know that it is single element, that logic is simple and we have already used in brute force that is if neither element on left and right are equal to it

int singleElOptimal(const vector<int> &arr) {

    // handling edge cases
    if(arr.size() == 1 || arr[0] != arr[1]) return arr[0]; // because array is sorted
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // array is sorted

    int low = 1, high = arr.size() - 2; // eliminating edge cases and starting from 1 to n - 2
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        // i am standing on an even index and element on right is equal or i am standing on an odd index and element on left is equal both point left half, but single element on right half and hence low = mid + 1
        if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 != 0 && arr[mid] == arr[mid - 1])) {
            low = mid + 1; // (even, odd)
        }
        // i am standing 
        if((mid % 2 != 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 0 && arr[mid] == arr[mid - 1])) {
            high = mid - 1; // (odd, even)
        }
    }
    return -1;
} // O(logn) time

int main() {
    
    return 0;
}