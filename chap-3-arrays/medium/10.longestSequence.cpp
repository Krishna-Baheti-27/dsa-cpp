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
    // O(N^N^N) time
}

int longestSeqBetter(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int maxLen = 1, len = 0, lastSmallest = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] - 1 == lastSmallest) {
            // if arr[i] has to be a part of sequence then the lastSmaller or basically the previous element has to be 1 lesser than arr[i] and in that case we increase the length of current sequence and make arr[i] the new lastSmaller
            lastSmallest = arr[i];
            len++;
        } else if(arr[i] != lastSmallest) {
            // if arr[i] == lastSmallest we dont do anything as we have already considered that so no need for repetition
            // but in this case when arr[i] != lastSmallest then we start the fresh sequence right since now there is no chance for continuation of existing sequence since, arr[i] - 1 is not equal to lastSmallest which would increase sequence or arr[i] == lastSmallest which would continue the sequecne (moving ahead and checking for others)
            lastSmallest = arr[i];
            len = 1; // new sequecne
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

int longestSeqOptimal(const vector<int> &arr) {
    unordered_set<int> st(arr.begin(), arr.end());
    int maxLen = 1, len = 0;
    for(auto el : st) {
        if(st.find(el - 1) == st.end()) {
            // here we skip all the elements from the operation which are not at the start of the sequence since they would be found at later down the iteration in the set, and if they are the start of the sequecne then similar to brute force we start checking for next element in the sequecne, if we find we icnrease the length fo sequecne or else just move ahead
            len++;
            int elementToCheck = el;
            while(st.find(elementToCheck + 1) != st.end()) {
                len++;
                elementToCheck++;
            }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int main() {
    
    return 0;
}