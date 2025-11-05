#include<bits/stdc++.h>
using namespace std;

// the peak element is defined as the element which is greater than both of its left and right negihbours
// given an array we have to return any one peak element
// consider -ve infinity on both ends of array

// there can be multiple peaks, we just have to return one, or we can also create an array of peak elements and return that if you feel like, here we are returning the index of any one peak

// this question is extremely similar to last question, because in both cases we were dealing with adjacent elements

// so the condition for peak element is pretty clear that
// arr[i - 1] < arr[i] && arr[i + 1] < arr[i]

///////////////////////////////////////////////////////////////////////////////////

// in the brute force solution we simply go through each element and check if its peak or not using the above condition and if yes then immediately return it

int peakElBrute(const vector<int> &arr) {

    // edge cases, if these are peaks then our work is easy we return early

    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    // now with edge cases out of the way

    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
    }

    return -1; // would be executed if no peak 

} // O(N) time

//////////////////////////////////////////////////////////////////////////////////

// to solve this question for array containing multiple peaks we first solve for array containing single peak

// we use the concept of slope that if arr[mid - 1] < arr[mid] then we are on increasing slope and hence peak lies on right, if arr[mid] > arr[mid + 1] then we are on decreasing slope and hence peak lies on left, so this is how we eliminate left or right halves

// and to identify the peak element we use the same condition as in brute force method

int peakElOptimalSingle(const vector<int> &arr) {

    // handling edge cases

    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    // now for indices [1 .. n - 2]

    int low = 1, high = arr.size() - 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {

            return mid; // for mid to be peak

        } else if(arr[mid] > arr[mid - 1]) { // mid lies on the increasing slope

            low = mid + 1; // so we will have peak on right of increasing

        } else if(arr[mid] > arr[mid + 1]) { // mid lies on the decreasing slope

            high = mid - 1; // so for decreasing we will have peak on the left
        }
    }

    return -1; // no peak

} // O(logN) time

/////////////////////////////////////////////////////////////////////////////////

// now this code perfectly works for single peak, but if we have multiple peaks we might create a valley 
// ex : [1,5,1,2,1], here 1 < 5 and 1 < 2 so none of above cases get executed and we run into a infinite loop, so to get out of it, if none of the cases execute, simply enter into a new search space which can be low  = mid + 1 or high = mid - 1, thats it, after that, algo will place it in a new search space which may have peak else again for valley we do this to escape the valley

// this works for multiple peaks, becaue we guaranteed to enter into one of the search spaces since we are constantly doing low = mid + 1 or high = mid- 1

int peakElOptimal(const vector<int> &arr) {

    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    int low = 1, high = arr.size() - 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;
       
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;

        // now for eliminating halves

        if(arr[mid] > arr[mid - 1]) {

            // mid lies on the increasing slop
            low = mid + 1; // so we will have peak on right of increasing

        } else if(arr[mid] < arr[mid - 1]) {

            // mid lies on the decreasing slope
            high = mid - 1; // so for decreasing we will have peak on the left

        } else {
            // get into any of the search spaces (currently in a valley)
            low = mid + 1; // or high = mid - 1, both work
        }
    }

    return -1; // no peak

} // O(logN) time

////////////////////////////////////////////////////////////////////////////////

// consider this more readable and less complex approach we does the same thing

int peakElOptimalReadable(vector<int> &arr) {

    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;
    
    int low = 1, high = arr.size() - 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if(arr[mid] > arr[mid - 1]) {
            low = mid + 1; // on increasing slop so peak on right
        } else {
            high = mid - 1; // get into any search space regardless
        }
    }

    return -1; // no peak

} // O(logN) time

int main() {
    
    return 0;
}