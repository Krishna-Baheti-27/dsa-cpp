#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Defined only for sorted arrays
// Lower Bound -> smallest index such that arr[index] >= given number (if doesnt exist then it is equal to size of array)
// Upper Bound -> smallest index such that arr[index] > given number (if doesnt exist then it is equal to size of array)

//////////////////////////////////////////////////////////////////////////////////////////

int lowerBoundBrute(vector<int> &arr, int target) {

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= target) return i;
    }

    return arr.size();

} // O(N) time, brute force using linear search

////////////////////////////////////////////////////////////////////////////////////

// Using binary search since its sorted array

int lowerBoundOptimal(vector<int> &arr, int target) { 

    int low = 0, high = arr.size() - 1, ans = arr.size();

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) { 
            ans = mid; //  take it as a possible answer 
            high = mid - 1; // but look for something better
        } else {
            low = mid + 1; // try to reach the target
        } 

    }

    return ans;
} // O(logn) time

///////////////////////////////////////////////////////////////////////////////////

// In C++ STL we have direct functions
int lowerBoundVector(const vector<int>& vec, int target) {

    // returns an iterator pointing to the element

    auto it = lower_bound(vec.begin(), vec.end(), target); 

    return it - vec.begin();  // index of first element >= target
}

// For arrays
int lowerBoundArray(const int arr[], int n, int target) {

    auto ptr = lower_bound(arr, arr + n, target);

    return ptr - arr;  // index of first element >= target
}

/////////////////////////////////////////////////////////////////////////////////////////

int upperBoundBrute(vector<int> &arr, int target) {

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > target) return i;
    }

    return arr.size();

} // O(N) time, brute using linear search

///////////////////////////////////////////////////////////////////////////////////////

// Using binary search since we sort of have to search in sorted array

int upperBoundOptimal(vector<int> &arr, int target) {

    int low = 0, high = arr.size() - 1, ans = arr.size();

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] > target) {
            ans = mid; // we take it as a possible answer
            high = mid - 1; // but look for an even better answer (smaller index)
        } else {
            low = mid + 1; // try to reach the answer (arr[mid] <= target) does not work
        }
    }

    return ans;

} // O(logn) time

int upperBoundVector(const vector<int>& arr, int target) {
    return upper_bound(arr.begin(), arr.end(), target) - arr.begin();
}

int upperBoundArray(const int arr[], int n, int target) {
    return upper_bound(arr, arr + n, target) - arr;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << lowerBoundOptimal(arr,4) << endl;
    cout << lowerBoundVector(arr,4) << endl;
    cout << upperBoundOptimal(arr,7) << endl;
    return 0;
}