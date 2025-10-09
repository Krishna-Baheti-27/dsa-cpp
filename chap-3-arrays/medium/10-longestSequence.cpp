#include<bits/stdc++.h>
using namespace std;

bool linearSearch(const vector<int> &arr, int target) {
    for(int num : arr) if(num == target) return true;
    return false;
}

int longestSeqBrute(const vector<int> &arr) {
    int maxLen = 1; // even if you pick a single element, the length would be atleast 1
    for(int i = 0; i < arr.size(); i++) {
        // for each arr[i] we check if there is arr[i] + 1, and if there is we update its length and if not we move ahead
        int len = 1; // len for each element
        int elementToCheck = arr[i] + 1; // for arr[i] we have to find arr[i] + 1

        // here when we do linear search we are essentially looking from the start of array so no need to worry that we would leave anything
        while(linearSearch(arr, elementToCheck)) {
            // if we find arr[i] + 1, then we look for arr[i] + 2 and increase the length but if we do not find the element we exit the loop check for next element, if it can be a part of sequence
            elementToCheck++;
            len++;
        }
        maxLen = max(len, maxLen);
    } 
    return maxLen;
    // O(N^3) time
}

int longestSeqBetter(vector<int> &arr) {
    if(arr.size() == 0) return 0;
    int len = 1, maxlen = 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] + 1 == arr[i + 1]) { // if we have a valid consecutive sequence
            len++; 
            maxlen = max(maxlen, len);
        } else if(arr[i + 1] != arr[i]) {
            len = 1; // reset if not duplicate, starting new sequence
        }  // and if duplicate do nothing, we simply move ahead in iteration
    }
    return maxlen;
} // O(nlogn + n) time

// a more better way to write and understand above code 

int longestSeqBetteeReadable(vector<int> &arr) {
    int len = 0, lastSmaller = INT_MAX, maxlen = 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] - 1 == lastSmaller) {
            len++; // part of consecutive sequence
            lastSmaller = arr[i]; // new lastSmaller which will continue our sequence
        } else if(arr[i] != lastSmaller) {
            // we know its not equal and its not 1 greater than lastSmaller so here are bound to start a new sequence
            len = 1; // new sequence
            lastSmaller = arr[i];
        }
        maxlen = max(maxlen, len);
    }
    return maxlen;
} // but here we are distorting the array 

// here we skip all the elements from the operation which are not at the start of the sequence since they would be found at later down the iteration in the set, and if they are the start of the sequecne then similar to brute force we start checking for next element in the sequecne, if we find we icnrease the length fo sequecne or else just move ahead

int longestSeqOptimal(const vector<int> &arr) {
    unordered_set<int> st(arr.begin(), arr.end()); // O(N)
    int maxLen = 0;
    for(auto el : st) { // O(N)
         // if it is the starting element then we set len to 1 and start looking for consecutive elements in unordered_set in O(1) time
        if(st.find(el - 1) == st.end()) {
            int currlen = 1;
            int elementToCheck = el + 1;
            while(st.find(elementToCheck)!= st.end()) { // this loop will run total of N times
                currlen++;
                elementToCheck++;
            }
            maxLen = max(maxLen, currlen);
        }
        // if it is not the starting element of the sequence we simply skip it, since it would be covered by the starting element of its sequence
    } 
    return maxLen;
} // O(3N) time, O(N) space

// because this inner while loop only runs for starting element of sequence, that is if st cannot find el - 1, and that too it ca atmax run for N times since total it can reach N elements even though there are lets say 3-4 starting sequences the total elements reached through them cant be greater than N, hence N times total it runs during entire iteration
 

int main() {
    
    return 0;
}