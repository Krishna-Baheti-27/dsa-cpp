#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArraysBrute(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    vector<int> arr3; // your answer (using extra space)
    int i = 0, j = 0;
    while(i < m && j < n) {
        if(arr1[i] <= arr2[j]) {
            arr3.push_back(arr1[i++]);
        } else {
            arr3.push_back(arr2[j++]);
        }
    }
    while(i < m) {
        arr3.push_back(arr1[i++]);
    }
    while(j < n) {
        arr3.push_back(arr2[j++]);
    }
    // now since arr3 is our new array, copy all the elements from arr3 into arr1 and return arr1
    for(int i = 0; i < arr3.size(); i++) {
        arr1[i] = arr3[i];
    }
    return arr1;
} // O(m + n) extra space and O(m + n) time

vector<int> mergeSortedArraysOptimal1(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    int i = m - 1, j = 0;
    while(i >= 0 && j < n) {
        if(arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        } else {
            break; // since equal or lesser means they are in correct position and anything after them would also be since array is sorted
        }
    }
    // now sort both arr1 and arr2
    sort(arr1.begin(), arr1.begin() + m);
    sort(arr2.begin(), arr2.end());
    // now just copy the elements of arr2 into arr1's vacant places
    for(int i = m; i < m + n; i++) {
        arr1[i] = arr2[i - m];
    }
} // O(min(n,m)) + O(nlogn + mlogm) + O(n) total time and O(1) space 

vector<int> mergeSortedArraysOptimal2(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    // using gap method
} 

vector<int> mergeSortedArraysOptimal3(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    // using abdul bari approach
}

int main() {
    
    return 0;
}