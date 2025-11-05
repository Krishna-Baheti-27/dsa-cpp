#include<bits/stdc++.h>
using namespace std;

// we have to find the number of times the array has been right rotated

/////////////////////////////////////////////////////////////////////////

// We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element. (this is beacause first element in the min element for a sorted array and to find the number of rotations we simply have to check by how much position has the first element bee displaced)

// So, in order to solve this problem, we have to find the index of the minimum element.

////////////////////////////////////////////////////////////////////////

// brute force uses linear search to find the index of min element and return it

int noOfRotationsBrute(const vector<int> &arr) {

    int minIdx = 0; 

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < arr[minIdx]) minIdx = i;
    }

    return minIdx; 

} // O(N) time

///////////////////////////////////////////////////////////////////////////

// in the optimal solution we use the binary search algo to find the minel in the rotated sorted array thus telling us the number of times array has been right rotated

int noOfRotationsOptimal(const vector<int> &arr) {

    int minIdx = 0, minel = INT_MAX; 
    
    int low = 0, high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // you have to introduce the case of 
        // arr[low] == arr[mid] && arr[mid] == arr[high]
        // in case of duplicates but here we only have unique elements

        if(arr[low] <= arr[mid]) {
            
            if(arr[low] < minel) { // check with the least element of sorted half
                minel = arr[low];
                minIdx = low;
            } 
            low = mid + 1; // and then eliminate the sorted half

        } else if(arr[mid] <= arr[high]) {
        
            if(arr[mid] < minel) {
                minel = arr[mid];
                minIdx = mid;
            }
            high = mid - 1;
        }
    }

    return minIdx; 

} // O(logN) time 

int main() {
    
    return 0;
}