#include<bits/stdc++.h>
using namespace std;

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n

////////////////////////////////////////////////////////////////////////////////////

// even though we have to do it in place but the brute force involves creating a new temporary array which will have all the merged values and then simply copy back this into arr1 

void mergeSortedArraysBrute(vector<int> &arr1, int m, vector<int> &arr2, int n) {

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

    // now since arr3 is our new array, copy all the elements from arr3 into arr1
    for(int i = 0; i < arr3.size(); i++) {
        arr1[i] = arr3[i];
    }
    
} // O(m + n) extra space and O(2 * (m + n)) time

///////////////////////////////////////////////////////////////////////////////////

// in this better approach we simply move the elements of arr2 into end of arr1 then sort arr1 , it is efficient in terms of space but not time

void mergeSortedArraysBetter(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    for(int i = m; i < m + n; i++) {
        arr1[i] = arr2[i - m];
    }
    sort(arr1.begin(), arr1.end());
} // O(n + (m + n) * log(m + n)) time and O(1) space

////////////////////////////////////////////////////////////////////////////////////

// this is a good method but is incorrect when j exceeds n and we still havent processed i till m as here we simply moving bigger elements to end

// vector<int> mergeSortedArraysOptimal3(vector<int> &arr1, int m, vector<int> &arr2, int n) {
//     int postToInsert = m;
//     int i = 0, j = 0;
//     while(i < m && j < n) {
//         if(arr1[i] > arr2[j]) {
//             arr1[postToInsert] = arr1[i];
//             arr1[i] = arr2[j];
//             j++;
//             postToInsert++;
//         }
//         i++;
//     }
//     while(j < n) {
//         if(arr1[i] == 0) {
//             while(j < n) {
//                 arr1[i++] = arr2[j++];
//             }
//             break;
//         } else {
//             if(arr1[i] > arr2[j]) {
//                 arr1[postToInsert] = arr1[i];
//                 arr1[i] = arr2[j];
//                 j++;
//                 postToInsert++;
//             }
//             i++;
//         }
//     }
// }

//////////////////////////////////////////////////////////////////////////////////////

void mergeSortedArraysOptimal1(vector<int>& arr1, int m, vector<int>& arr2, int n) {

    int i = m - 1; // Last element of arr1's sorted part
    int j = n - 1; // Last element of arr2
    int k = m + n - 1; // Last position in arr1's total space

    // Go backwards as long as arr2 still has elements so we start filling largest elements first contrary to filling smaller first as we did before

    while (j >= 0) {
        
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--; 
        } else {
            arr1[k] = arr2[j];
            j--; 
        }
        k--; 
    }
} // O(m + n) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////

// analyse other solutions by striver later

int main() {
    
    return 0;
}