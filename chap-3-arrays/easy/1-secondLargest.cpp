#include<bits/stdc++.h>
using namespace std;

// int secondLargestBrute(), simply sorting the array and second largest would be at n - 2 index and second smallest would be at index = 1, but this works only if array doesnt have duplicates

int secondLargestInArrayBetter(int arr[], int n) {
    // in this code you can handle other cases like array with less than 2 elements cannot have a secondMax
    if(n < 2) return -1; 
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    int secondMax = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] != max && arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }
    if(secondMax == INT_MIN) return -1; // if all the elements are equal then there is no secondMax
    return secondMax;
} // here we use two passes, first to find max/min and then to find secondMax/Min

// the above function was for begginners but we can improve it to find both the max and second max in one go

int secondMaxOptimal(int arr[], int n) {
    int max = INT_MIN, secondMax = INT_MIN;
    // finding max and if a new max is found then we set secondMax = previousMax
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            secondMax = max; // setting existing max equal to secondMax before setting it to new max
            max = arr[i]; // setting new value of max
        } else if(arr[i] > secondMax && arr[i] != max) {
            // case where a new max is not found but a new secondMax is found
            secondMax = arr[i];
            // This ensures that only values that are strictly less than the current maximum are considered for secondMax
        }
        // if niether secondMax nor max is found do nothing
    }
    if(secondMax == INT_MIN) return -1;
    return secondMax;
}

// Brute for second smallest is using sorting (not for duplicates)
int secondSmallestBetter(vector<int> &arr) {
    // using two passes
    if(arr.size() < 2) return -1;
    int min = INT_MAX, secondMin = INT_MAX;
    for(int num : arr) {
        if(num < min) min = num;
    }
    // second pass
    for(int num : arr) {
        if(num != min && num < secondMin) secondMin = num;
    }
    if(secondMin == INT_MAX) return -1;
    return secondMin;
}

int secondSmallestOptimal(vector<int> &arr) {
    if(arr.size() < 2) return -1;
    int min = INT_MAX, secondMin = INT_MAX;
    for(int num : arr) {
        if(num < min) {
            secondMin = min;
            min = num;
        } else if(num != min && num < secondMin) {
            // case where new secondMin if found but a new min is not found
            secondMin = num;
        }
    }
    if(secondMin == INT_MAX) return -1; // when all elements are same
    return secondMin;
}

int main() {
    int arr[] = {9,6,1,2,10,-9,9,10};
    int n = 8;
    cout << secondLargestInArrayBetter(arr,n) << '\n';
    cout << secondMaxOptimal(arr,n) << '\n';
    return 0;
}