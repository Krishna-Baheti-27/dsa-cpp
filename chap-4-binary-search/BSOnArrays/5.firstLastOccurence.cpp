#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> firstLastOccurenceBrute(const vector<int> &arr, int key) {
    int firstOcc = -1, lastOcc = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) {
            if(firstOcc == -1) firstOcc = i;
            lastOcc = i; // always update so that it handles all the cases of whether single occurence or multiple
        } 
    }
    return {firstOcc, lastOcc};
}

// vector<int> firstLastOccurenceOptimal(const vector<int> &arr, int key) {
//     int low = 0, high = arr.size() - 1, firstOcc = -1, lastOcc = -1;
//     while(low <= high) {
//         int mid = low + (high - low) / 2;
//         if(arr[mid] <= key) {
//             if(arr[mid] == key) {
//                 if(firstOcc == -1) firstOcc = mid;
//                 lastOcc = mid;
//             }
//             low = mid + 1; // look on the right side for finding higher occurences
//         } else high = mid - 1; // look on left
//     }
//     return {firstOcc, lastOcc};
// } 
// This code is incorrect and misses the real first occurence since mid just jumps and might miss something, rather we will have to use two passes of binary search since we are essentially searching for two elements, hence two passes would be required


vector<int> firstLastOccurenceOptimal(vector<int> &arr, int key) {
    // Using pure binary search and no upper/lower bound
    int low = 0, high = arr.size() - 1, firstOcc = -1, lastOcc = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= key) { // we are doing this because array does contain duplicates, so we have to apply binary search on array containing duplicates with given constraint, that is find the smallest index of that element
            if(arr[mid] == key) firstOcc = mid;
            high = mid - 1; // but i will also look for smaller index, regardless of whether i get the value of key or not since we are lookinh for very first occurence
        } else {
            low = mid + 1; // try to reach the answer
        }
    }
    low = 0, high = arr.size() - 1;
    while(low <= high) {
        // we are lloking to find last occurecne of key
        int mid = low + (high - low) / 2;
        if(arr[mid] <= key) {
            if(arr[mid] == key) lastOcc = mid;
            low = mid + 1; // i will also look for any index greater than this
        } else {
            high = mid - 1;
        }
    }
    return {firstOcc, lastOcc};
}

vector<int> usingLowerUpperBound(const vector<int> &arr, int key) {
    // Lower Bound -> smallest index such that arr[index] >= given number (if doesnt exist then put = size of array)
    // Upper Bound -> smallest index such that arr[index] > given number 
    // so upper - 1 would be the last occurence
    auto it1 = lower_bound(arr.begin(), arr.end(), key);
    auto it2 = upper_bound(arr.begin(), arr.end(), key);

     // Check if key is present because this functions return upper and lower bound and dont guarantee if key is present or not
    if (it1 == arr.end() || *it1 != key) // this conditions check if key is present
        return {-1, -1}; // key not found

    // if key is present then it2 would point to either arr.end() or it1 + 1 or anything after that, and in all cases it is a valid iterator and hence no need to check for it2
    
    int firstOcc = it1 - arr.begin();
    int lastOcc = it2 - arr.begin() - 1;
    return {firstOcc, lastOcc};
}

int countNumberOfOccurences(vector<int> &arr, int key) {
    vector<int> occ = firstLastOccurenceOptimal(arr,key);
    return occ[1] - occ[0] + 1; // gives number of occurences since array is sorted in non decreasing order
    // we cna also implement plain linear search but that will take O(N)
}

int countNumberOfOccurencesUsingLowerUpperBound(vector<int> &arr, int key) {
    auto lowerb = lower_bound(arr.begin(), arr.end(), key);
    auto upperb = upper_bound(arr.begin(), arr.end(), key);
    return upperb - lowerb; // no +1 since these are iterators and not indexes
//     Iterators in C++ STL point to elements in a container, and their difference (upper - lower) gives the number of elements between them, not their index difference.

// If you have two iterators, it1 and it2, then it2 - it1 gives the count of elements in the range [it1, it2) (including it1, excluding it2).
}


int main() {
    vector<int> arr = {2,4,6,8,8,8,11,13};
    vector<int> occArr = firstLastOccurenceOptimal(arr,8);
    cout << occArr[0] << ' ' << occArr[1] << endl;
    
    return 0;
}