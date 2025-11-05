#include<bits/stdc++.h>
using namespace std;

// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
// in simple words, the left element should be greater than the right element
// so we have to find total number of all such pairs

//////////////////////////////////////////////////////////////////////////////

// in the brute force we simply check for each element on its right and by comparing and counting pairs

int countInversionsBrute(vector<int> &arr) {

    int count = 0;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) { // if left element is greater than the right element
                count++;
            }
        }
    }

    return count;

} // O(N^2) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////

// uses the merge sort approach
// here we know for counting pairs we basically have to divide the array into two parts but we also count the pairs in least time so if array is sorted then we can do that in linear time and hence we use this approach

// while merging back the sorted arrays from mergeSort we count the number of inversion pairs which re simply instances where left element > right element or element from left half(low to mid) is greater than element from right half (mid + 1 to high)

void merge(vector<int> &arr, int low, int mid, int high, int &count) {

    int i = low, j = mid + 1;
    vector<int> temp;

    while(i <= mid && j <= high) {
        if(arr[i] > arr[j]) {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        } else {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= high) {
        temp.push_back(arr[j++]);
    }

    for(int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high, int &count) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
}

int countInversionsOptimal(vector<int> &arr) {
    int count = 0;
    mergeSort(arr, 0, arr.size() - 1, count); 
    return count;
} // O(NlogN) time and O(N) space for temp array (ignoring recursion stack space) 

//////////////////////////////////////////////////////////////////////////////////

// better way to write this without passing variables by reference is using the recursive way to return the number of pairs formed at each level of function call

int mergeBetter(vector<int> &arr, int low, int mid, int high) {

    int i = low, j = mid + 1;
    int count = 0;
    vector<int> temp;


    while(i <= mid && j <= high) {
        if(arr[i] > arr[j]) {
            count += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        } else {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= high) {
        temp.push_back(arr[j++]);
    }

    for(int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return count;

}

int mergeSortBetter(vector<int> &arr, int low, int high) {
    if(low >= high) return 0;
    int count = 0;
    int mid = low + (high - low) / 2;
    count += mergeSortBetter(arr, low, mid);
    count += mergeSortBetter(arr, mid + 1, high);
    count += mergeBetter(arr, low, mid, high);
    
    return count;
}

int countInversionsOptimal(vector<int> &arr) {
    return mergeSortBetter(arr, 0, arr.size() - 1); 
}

int main() {
    
    return 0;
}