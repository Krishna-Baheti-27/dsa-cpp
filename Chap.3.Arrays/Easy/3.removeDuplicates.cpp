#include<iostream>
#include<set>
#include<vector>
using namespace std;

// PROBLEM STATEMENT : Remove duplicate from a sorted array (in non decreasing order) from their places and if an array has N unique elements then the first N positions of the array should be occupied by unique elements only in sorted array and then return the new array 

// brute force using set

void removeDuplicatesBrute(vector<int> &arr) {
    set<int> st;
    for(int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto el : st) {
        arr[index++] = el; 
    }
    // now the arr stores first N unique elements at N places
}

int removeDuplicatesOptimised(vector<int> &arr) {
    if (arr.empty()) return 0;

    int j = 0; // points to the position where the next unique element should go
    // the first element would always be unique so we start from second element, since we have to maintain the relative order of elements

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[j]) {
            j++; // if we find unique element then increment j and store arr[i], in our array free from duplicates whose last element is currently arr[j] with which we check to verify whether its a duplicate or not
            arr[j] = arr[i];
        }
    }
    // now just return j + 1, since j is index and we have to return the size
    //  Core Insight:

    // You're scanning the array from left to right.

    // You keep a j pointer to track where to store the next unique element.

    // The first element is always unique, so we start j = 0 and loop from i = 1.

//     If same:

//     arr[i] == arr[j]:
//     → This means it's a duplicate.
//     → Just skip it and move on (i++).

// 💾 If different:

//     arr[i] != arr[j]:
//     → This means a new unique element is found.
//     → Increment j to create space, then store arr[i] at arr[j].
    // The vector now has unique elements in the first (j+1) positions
    return j + 1; // New size of unique part
    // only works for a sorted array
}



int main() {
    vector<int> arr = {1,1,2,2,3,3,4,5};
    for(int num : arr) cout << num << ' ';
    cout << endl;
    removeDuplicatesOptimised(arr);
    for(int num : arr) cout << num << ' ';
    cout << endl;
    return 0;
}