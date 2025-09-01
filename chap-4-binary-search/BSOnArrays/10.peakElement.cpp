#include<bits/stdc++.h>
using namespace std;

// there can be multiple peaks, we just have to return one, or we can also create an array of peak elements and return that if you feel like, here we are returning the index
int peakElBrute(const vector<int> &arr) {
    // O(N) linear search solution
    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    // now with edge cases out of the way
    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
    }
    return -1; // never executed
}

int peakElBruteReadable(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        if((i == 0 || arr[i - 1] < arr[i]) && (i == arr.size() - 1 || arr[i + 1] < arr[i])) return i;
    }
    return -1;
}

int peakElOptimalSingle(const vector<int> &arr) {
    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    int low = 1, high = arr.size() - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // for mid to be peak
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        // now for eliminating halves
        if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
            // mid lies on the increasing slop
            low = mid + 1; // so we will have peak on right of increasing
        } else if(arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            // mid lies on the decreasing slope
            high = mid - 1; // so for decreasing we will have peak on the left
        }
    }
    return -1; // never executed
}

// now this code perfectly works for single peak, but if we have multiple peaks we might create a valley 
// ex : [1,5,1,2,1], here 1 < 5 and 1 < 2 so none of above cases get executed and we run into a infinite loop, so to get out of it, if none of the cases execute, simply enter into a new search space which can be low  = mid + 1 or high = mid - 1, thats it, after that, algo will place it in a new search space which may have  peak else again for valley we do this

// this works for multiple peaks, becaue we guaranteed to enter into one og the search spaces since we are constantly doing low = mid + 1 or high = mid- 1

int peakElOptimal(const vector<int> &arr) {
    if(arr.size() == 1 || arr[0] > arr[1]) return 0; 
    if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

    int low = 1, high = arr.size() - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // for mid to be peak
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        // now for eliminating halves
        if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
            // mid lies on the increasing slop
            low = mid + 1; // so we will have peak on right of increasing
        } else if(arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            // mid lies on the decreasing slope
            high = mid - 1; // so for decreasing we will have peak on the left
        } else {
            low = mid + 1; // or high = mid - 1, both work
        }
    }
    return -1; // never executed
}

int main() {
    
    return 0;
}