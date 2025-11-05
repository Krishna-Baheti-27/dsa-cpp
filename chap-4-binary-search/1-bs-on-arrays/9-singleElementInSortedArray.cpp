#include<bits/stdc++.h>
using namespace std;

// return the only single elementpresent in an unsorted array where everyone else appears twice 

// we have already done single element in an unsorted array and best solution was using xor in linear time, but here we can take advantage of the fact that array is sorted and do it in logN time

// when we are standing at a index, then either index - 1 or index + 1 ought to have the same element, if both of them dont then that element is guranteed to be single, using this logic we deal with edge cases of first and last element early on

////////////////////////////////////////////////////////////////////////////////////////

// the brute force involved going through each element and checking if the same element is present on atleast left or right if not then that is the single element which we can return

int singleElBrute(vector<int> &arr) {

    // handling edge cases

    if(arr.size() == 1) return arr[0]; // length of array == 1
    if(arr[0] != arr[1]) return arr[0];  // first element
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1];  // last element

    // for rest of the elements, checking from index 1 to n - 2

    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i - 1] != arr[i] && arr[i + 1] != arr[i]) return arr[i];
    }

    return -1; // no single element

} // O(N) time in worst case

/////////////////////////////////////////////////////////////////////////////////////

// The logic for optimal solution

// here we are pretty clear that we want to apply binary seach since array is sorted and we have to achieve a complexity of less than O(N), so now the main thing to find is the logic to eliminate halves

// we can eliminate the halves by using the property which is shown by the only single element in the array, that is,
// on the left of single element we have pairs like (even,odd) indices for all equals
// on the right of single element we have pairs lie (odd, even) indices for all equals

// we can surely use this to determine where are we standing and which half to eliminate in order to reach the single element

// this is how we reach our single element, but how do we know that it is single element, that logic is simple and we have already used in brute force that is if neither element on left and right are equal to it

int singleElOptimal(const vector<int> &arr) {

    // handling edge cases

    if(arr.size() == 1 || arr[0] != arr[1]) return arr[0]; // first element or 1 lenght array
    if(arr[arr.size() - 1] != arr[arr.size() - 2]) return arr[arr.size() - 1]; // last element

    int low = 1, high = arr.size() - 2; // eliminating edge cases and starting from 1 to n - 2

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // condition to check whether a given element is single or not

        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        } else if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
         (mid % 2 != 0 && arr[mid] == arr[mid - 1])) {

            // (even, odd), means we are on left half
            // we are standing on left half and element in on right hence eliminate left
            low = mid + 1; 

        } else if((mid % 2 != 0 && arr[mid] == arr[mid + 1]) || 
        (mid % 2 == 0 && arr[mid] == arr[mid - 1])) {

            // (odd, even), means we are on right half
            // we are standing on right half and element in on left hence eliminate right
            high = mid - 1; 
        }
    }

    return -1; // no single element

} // O(logn) time

int main() {
    
    return 0;
}