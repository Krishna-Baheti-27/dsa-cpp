#include<iostream>
#include<vector>
using namespace std;

void leftRotateBy1(vector<int> &arr) { // elements from left are moved to right is left rotation
    // {1,2,3,4,5} becomes {2,3,4,5,1} // from starting to backwards
    int first = arr[0];  // start loop from first element, and shift them by one place
    for(int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = first;
} // in left rotate starting k elements move to end one by one

void rightRotateBy1(vector<int> &arr) { // elements from right are moved to left is right rotation
    // {1,2,3,4,5} becomes {5,1,2,3,4} // from back to starting
    int last = arr[arr.size() - 1]; // start from last element and shift it by one place
    for(int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
} // in right rotate ending k elements move at beginning one by one

void reverseArray(vector<int> &arr, int low, int high) {
    // low and high are indexes both inclusive
    for(int i = low, j = high; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
// for this cpp has stl => reverse(arr,arr+d) reverses from 0th to d-1th index
// reverse(arr+d,arr+n) reverses from dth to n-1th index
// and for vectors use iterators

void leftRotateByk(vector<int> &arr, int k) {
    k = k % arr.size();
    vector<int> temp;
    for(int i = 0; i < k; i++) {
        temp.push_back(arr[i]);
    } // storing the values which we have to send backwards (left to right)
    for(int i = k; i < arr.size(); i++) {
        arr[i - k] = arr[i]; // we start from storing arr[i-k] or arr[0] then arr[1] and so on
        // basically shifting the values
    }
    for(int i = arr.size() - k; i < arr.size(); i++) {
        arr[i] = temp[i - (arr.size() - k)];  // storing the values in arr stored in temp
        /// you can also simply use j = 0, and use temp[j++] instead of all the maths
    }
    // O(n+k) time but O(k) extra space, k is the number of rotations
}

void rightRotateByk(vector<int> &arr, int k) {
    k = k % arr.size();
    vector<int> temp;
    for(int i = k + 1; i < arr.size(); i++) temp.push_back(arr[i]); // storing values which we have to bring forward from back
    for(int i = arr.size() - 1; i >= k; i--) {
        arr[i] = arr[i-k]; // elements to be shifted
    }
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i]; // storing forward values
    }
    // O(n+k) time but O(k) extra space
}

void leftRotateBykOptimised(vector<int> &arr, int k) {
    k = k % arr.size();
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,arr.size() - 1);
    reverseArray(arr,0,arr.size() - 1);
    // O(k) + O(n-k) + O(n) = O(2n), but no extra space
}

void rightRotateBykOptimised(vector<int> &arr, int k) {
    k = k % arr.size();
    reverseArray(arr,0,arr.size() - 1);
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,arr.size() - 1);
    // O(n) + O(k) + O(n-k) = O(2n)
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << endl;
    rightRotateBykOptimised(arr,7);
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}