#include<bits/stdc++.h>
using namespace std;

// we have to find min element in rotated sorted array given all elements are unique

/////////////////////////////////////////////////////////////////////////////

// uses simple linear search

int findMinBrute(vector<int> &arr) {
   
    int min = INT_MAX;
    for(int num : arr) if(num < min) min = num;
    return min == INT_MAX ? -1 : min;

} // O(N) time

///////////////////////////////////////////////////////////////////////

// Using binary search algo

// we are given that array is rotated sorted, so we can take advantage of that since we know atleast one half ought to be sorted so we compare min with the first element in sorted half (that is the smallest element in sorted half) and then we apply our algo on the other half (skipping half elements of sorted half directly) 

int findMinOptimal(vector<int> &arr) {

    int low = 0, high = arr.size() - 1, minel = INT_MAX;

    while(low <= high) {

        // happens only when array is sorted or has been rotated by k = arr.size() 

        if(arr[low] <= arr[high]) { 
            return min(arr[low], minel); // return early
        } 

        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[mid]) {  // left part is sorted

            minel = min(arr[low], minel); // our possible minimum element
            low = mid + 1; // now look on right (we eliminated sorted half, (left half))

        } else if(arr[mid] <= arr[high]) { // right part is sorted
            
            minel = min(arr[mid], minel); // our possible minimum element 
            high = mid - 1; // now look on left (we eliminated sorted half, (right half))
        }
    }
    
    return minel;

} // O(logN) time 

int main() {
    vector<int> arr = {4,5,6,7,0,1,2,-1};
    cout << findMinBrute(arr) << endl;
    cout << findMinOptimal(arr) << endl;
    return 0;
}