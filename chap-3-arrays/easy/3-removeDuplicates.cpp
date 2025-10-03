#include<iostream>
#include<set>
#include<vector>
using namespace std;

// PROBLEM STATEMENT : Remove duplicate from a sorted array (in non decreasing order) from their places and if an array has N unique elements then the first N positions of the array should be occupied by unique elements only in sorted array and then return the new array 

// brute force using set

int removeDuplicatesBrute(vector<int> &arr) {
    set<int> st;
    for(int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto el : st) {
        arr[index++] = el; 
    }
    // now the arr stores first N unique elements at N places
    return index;
} // O(nlogn + no.ofunique) time for set or O(n) time for unordered_set (but not guaranteed) and O(n) space

int removeDuplicatesBetter(vector<int> &arr) {
    vector<int> ans;
    ans.push_back(arr[0]); // first element would always be inserted because it ought to be unique
    for(int i = 1; i < arr.size(); i++) {
        if(ans.back() != arr[i]) ans.push_back(arr[i]);
        // this only works becuase arr is sorted if ans.back() != arr[i], then it is guaranteed that arr[i] is unique (and greater) element
    }
    for(int i = 0; i < ans.size(); i++) arr[i] = ans[i]; // we dont care about rest of the elements
    return ans.size(); // this are the number of unique elements
} // O(n + no.ofunique) time and O(n) space

// from here we get the intuition that we dont need the ans array since we are only interested in finding k unique elements of arr, and placing them at the start so instead of storing them in the temporary array we copy them directly into our main array arr, and we are essetially performing this check that ans.back() != arr[i] which ensures that there are no duplicates, similary we achieve it here by only comparing it with the current element since array is sorted

int removeDuplicatesOptimised(vector<int> &arr) {
    int j = 0; // this acts as the back pointer similar to arr.back() which maintains last inserted element and helps us from preventing duplicats
    for(int i = 1; i < arr.size(); i++) {
        // we start from second element since we know that the first element is always unique and woudl remain there
        if(arr[j] != arr[i]) { // same as if arr.back() != arr[i] then only insert
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1; // since j points to the last unique element starting from 0 so total j + 1
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