// its like union of sets, so we dont repeat, like we do when merging two arrays
// both arrays have to be sorted
#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfArraysBruteUsingSet(vector<int> &arr1, vector<int> &arr2) {
    // brute using set (huge if you find out time)
    set<int> st;
    vector<int> arr3;
    for(int i = 0; i < arr1.size(); i++) {
        st.insert(arr1[i]);
    }
    for(int j = 0; j < arr2.size(); j++) {
        st.insert(arr2[j]);
    }
    for(auto &el : st) arr3.push_back(el); // we use &/reference operator to avoid creating copies
    return arr3;
    // O(m + n(log(m + n))) + O(mlogm) + O(nlogn)
}

vector<int> unionOfArraysBruteUsingMap(vector<int> &arr1, vector<int> &arr2) {
    // since map can be used to store frequecies of elements, so it would store the frequecies as values but actual elements as keys and we would simply copy back from map the keys into main array, since map stores key in sorted and unique fashion
    // unordered_map does not store in ordered fashion
    vector<int> arr3;
    map<int,int> mp;
    for(int num : arr1) mp[num]++;
    for(int num : arr2) mp[num]++;
    for(const auto &el : mp) arr3.push_back(el.first); // we only need the keys not values since we only want to store unique occurences hence keys 
    return arr3;
}

// Using the two pointer approach
// Approach very similar to merging two arrays but you only have to take care of whether the lats inserted element is not equal (since we dont want duplicates) and since array is sorted if the last element is not equal then it must be less than and hence we can insert without disturbing the sorted order
// use arr3.empty() if that were to be the first element, arr3.back() wouldn't make a lot of sense 

vector<int> unionOfArraysOptimal(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> arr3;
    int i = 0, j = 0; // indexes for arr1, arr2
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            if(arr3.empty() || arr1[i] != arr3.back()) {
                arr3.push_back(arr1[i]);
            }
            i++; // regardless of whether you insert or not, because you didnt insert because 
            // arr1[i] == arr3.back() which means element already taken, so move i aheaf
        } else {
            if(arr3.empty() || arr2[j] != arr3.back()) {
                arr3.push_back(arr2[j]);
            }
            j++; // move ahead regardless
        }
    }
    while(i < arr1.size()) {
        if(arr3.empty() || arr3.back() != arr1[i]) {
            arr3.push_back(arr1[i]);
        }
        i++; // move ahead regardless
    }
    while(j < arr2.size()) {
        if(arr3.empty() || arr3.back() != arr2[j]) {
            arr3.push_back(arr2[j]);
        }
        j++; // move ahead regardless
    }
    return arr3;
}

int main() {
    vector<int> arr1 = {1,1,2,3,4,5,6,6,7,7};
    vector<int> arr2 = {2,3,4,4,5};
    // both arrays have to be sorted
    vector<int> arr3 = unionOfArraysOptimal(arr1,arr2);
    for(int num : arr3) cout << num << ' ';
    cout << '\n';
    return 0;
}