#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// here we have to first and last of occurence of an element in an array containing duplicates
// it can also be framed as finding frequency of an element in an array

// it is given that array is sorted

////////////////////////////////////////////////////////////////

// the brute force solution involves linear search in which we go through each element and we store the first and last occurence of the key in two variables and return them

vector<int> firstLastOccurenceBrute(const vector<int> &arr, int key) {

    int firstOcc = -1, lastOcc = -1;

    for(int i = 0; i < arr.size(); i++) {
        
        if(arr[i] == key) {
            if(firstOcc == -1) firstOcc = i;
            lastOcc = i; // always update last occurence, since we got a new latest occurence
        } 
    }

    return {firstOcc, lastOcc};

} // O(N) linear time solution

///////////////////////////////////////////////////////////////////////////////////

// This code is incorrect and misses the real first occurence since mid just jumps to a certain value and might miss something on the left, rather we will have to use two passes of binary search since we are essentially searching for two elements, hence two passes would be required

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

/////////////////////////////////////////////////////////////////////////////////////

// using the binary search to first find the first occurence of the element by going as left as possible and then finding the second occurence of the element in new pass by going as right as possible

// the real magic of this approach lies in the answer variable, in which we store our possible answer and then look for better so we dont loose our answer when nothing better is possible

// Using pure binary search and no upper/lower bound

vector<int> firstLastOccurenceOptimal(vector<int> &arr, int key) {
    
    int low = 0, high = arr.size() - 1, firstOcc = -1, lastOcc = -1;

    // finding first occurence

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] >= key) { 
            if(arr[mid] == key) {
                firstOcc = mid; // take it as a possible answer
            }
            high = mid - 1; // but look on left for even smaller index
        } else {
            low = mid + 1; // try to reach the answer
        }
    }

    // finding last occurence (hence resetting low and high)

    low = 0, high = arr.size() - 1;

    while(low <= high) {
        
        int mid = low + (high - low) / 2;

        if(arr[mid] <= key) {
            if(arr[mid] == key) {
                lastOcc = mid; // take it as a possible answer
            }
            low = mid + 1; // but also look on right for even higher index
        } else {
            high = mid - 1;
        }
    }

    return {firstOcc, lastOcc};

} // O(2logN) time 

////////////////////////////////////////////////////////////////////////////////

// the same implementation using upper and lower bound so that you reflect your knowledge of STL to the interviewer

vector<int> usingLowerUpperBound(const vector<int> &arr, int key) {

    auto it1 = lower_bound(arr.begin(), arr.end(), key);
    auto it2 = upper_bound(arr.begin(), arr.end(), key);

    // lower and upper bound exist even if the key is not present so check that key is present or not, key is not present if lower bound == arr.end() or the iterator does not point to key

    if (it1 == arr.end() || *it1 != key) {
        return {-1, -1}; // key not found
    }
   
    // if key is present then it2 would point to either arr.end() or it1 + 1 or anything after that, and in all cases it is a valid iterator and hence no need to check for it2

    // extract the indices from iterators
    
    int firstOcc = it1 - arr.begin();
    int lastOcc = it2 - arr.begin() - 1; 
    
    // since it2 points to arr[ind] > key, so ind - 1 would be arr[ind] == key (the last occurence) which is exactly what we want hence lastOcc = upper bound - 1

    return {firstOcc, lastOcc};

} // O(2logn) time

/////////////////////////////////////////////////////////////////////////////////

// now we can reframe the same question

// if they ask the frequency of an element in sorted array then we can use this approach to find lastOcc and firstOcc and then frequency = lastOcc - firstOcc + 1, thus finding it in just O(logN) time using binary search (better than O(N) of linear search for finding frequency)

////////////////////////////////////////////////////////////////////////////////

int countNumberOfOccurences(vector<int> &arr, int key) {
    
    vector<int> occ = firstLastOccurenceOptimal(arr,key);
    return occ[1] - occ[0] + 1; 
}

//////////////////////////////////////////////////////////////////////////////

int countNumberOfOccurencesUsingLowerUpperBound(vector<int> &arr, int key) {

    auto lowerb = lower_bound(arr.begin(), arr.end(), key);
    auto upperb = upper_bound(arr.begin(), arr.end(), key);
    return upperb - lowerb; // no +1 since these are iterators and not indexes
}

// simply do lastOcc - firstOcc + 1 from above binary search code and you would get it2 - it1 as our answer and thus it states that it2 - it1 give the number of elements in the range [it1, it2)

int main() {
    vector<int> arr = {2,4,6,8,8,8,11,13};
    vector<int> occArr = firstLastOccurenceOptimal(arr,8);
    cout << occArr[0] << ' ' << occArr[1] << endl;
    
    return 0;
}