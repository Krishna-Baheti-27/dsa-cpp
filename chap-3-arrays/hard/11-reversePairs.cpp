#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j]

// this problem is extremely similar to the count inversions problem discussed

////////////////////////////////////////////////////////////////////////////////////

// in the brute force we simply go to right of each element and try to find the pairs which satisfy the given condition

int reversePairsBrute(vector<int> &arr) {

    int count = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] > 2 * arr[j]) count++;
        }
    }

    return count;

} // O(N^2) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////

// the optimal solution again uses the merge sort approach

// here we do it differently though, since that logic wont work, it may happen that arr[i] is not greater than 2 * arr[j] but the arr[i + 1] or arr[i + 2] or any one after that may be and if we skip this like before using j++ then we would miss pairs

// so best way to do this is by separating the merge step from our computation step
// so first we do computation and them merge

// the main thing is how we compute number of reverse pairs if we have two sorted arrays
// we start from pointers on left and right arrays and we move right till satifies the condition arr[left] > 2 * arr[right], as soon as it doesnt we stop and find the number of pairs as everything on the left and then we do left pointer++

int countPairs(vector<int> &arr, int low, int mid, int high) {

    int count = 0;
    int right = mid + 1;

    for(int i = low; i <= mid; i++) {
        // compare with long long to get true value else integer overflow would give -ve result
        while(right <= high && arr[i] > 2ll * arr[right]) { 
            right++;
        }
        count += (right - (mid + 1));
    }

    return count;
}

int merge(vector<int> &arr, int low, int mid, int high) {

    int i = low, j = mid + 1;
    vector<int> temp;

    int count = countPairs(arr, low, mid, high); // number of reverse pairs

    // now do our regular merge step

    i = low, j = mid + 1;

    while(i <= mid && j <= high) {
        if(arr[i] > arr[j]) {
            temp.push_back(arr[j]);
            j++;
        } else {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high) {
        temp.push_back(arr[j++]);
    }

    for(int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {

    if(low >= high) return 0;
    int count = 0;

    int mid = low + (high - low) / 2;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int reversePairsOptimal(vector<int> &arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    
    return 0;
}