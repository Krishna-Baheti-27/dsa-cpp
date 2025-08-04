#include<bits/stdc++.h>
using namespace std;

// Arrays are sorted

vector<int> intersectionOfArraysBrute(vector<int> &arr1, vector<int> &arr2) {
    // brute using O(n^2) nested loops
    vector<int> arr3;
    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr2.size(); j++) {
            if(arr1[i] == arr2[j] && (arr3.empty() || arr3.back() != arr2[j])) {
                arr3.push_back(arr2[j]);
                break;
            }
        }
    }
    return arr3;
}

vector<int> intersectionOfArraysBetter(vector<int> &arr1, vector<int> &arr2) {
    // using unordered_set if you dont stress about order of o/p and want speed, takes only O(m + n) time O(min(m,n)) extra space for unordered_set
    vector<int> arr3;
    unordered_set<int> st(arr1.begin(), arr1.end());
    for(int num : arr2) {
        if(st.count(num)) { // to check if num exists in st
            arr3.push_back(num); // if it exists then its a common element and hence intersection
            st.erase(num); // deleted the num so that next time we dont have to check it
            // improved time as it decrease N, indirectly O(logN)
        }
    }
//     The unordered_set approach’s output order depends on the traversal order of arr2 (the second array).
// If arr2 is sorted, the intersection elements will appear in sorted order in the result, even if arr1 is unsorted.
// If arr2 is unsorted, the output will reflect arr2’s element order.
    return arr3;
}

vector<int> intersectionOfArraysOptimised(vector<int> &arr1, vector<int> &arr2) {
    // both arrays are sorted
    vector<int> arr3;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] == arr2[j] && (arr3.empty() || arr3.back() != arr2[j])) {
            arr3.push_back(arr2[j]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]) i++;
        else if(arr1[i] > arr2[j]) j++;
    }
    return arr3;
}

vector<int> intersectionOfArraysOptimised2(const vector<int> &arr1, const vector<int> &arr2) {
    int i = 0, j = 0; // indexes for arr1, arr2
    vector<int> arr3; // intersection array
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] == arr2[j]) {
            if(arr3.empty() || arr1[i] != arr3.back()) {
                arr3.push_back(arr1[i]);
            }
            i++;
            j++;
        } else if(arr1[i] < arr2[j]) {
            // no point in looking ahead as arr1[i] is already less than arr2[j] so moving j ahead will not result in anythinh substantial
            i++;
        } else {
            // no point in looking ahead as arr1[i] is already greater than arr2[j] so moving i ahead will not result in anything substantial 
            j++;
        }
    }
}

int main() {
    vector<int> arr1 = {1,1,2,3,4,5,6,6,7,7};
    vector<int> arr2 = {2,3,4,4,5};
    // both arrays have to be sorted
    vector<int> arr3 = intersectionOfArraysOptimised(arr1,arr2);
    for(int num : arr3) cout << num << ' ';
    cout << '\n';
    return 0;
}