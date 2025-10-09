#include<bits/stdc++.h>
using namespace std;

int majortiyElBrute(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        int count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j]) count++;
            if(count > arr.size() / 2) return arr[i]; 
            // early exit when we know the majority element already then no need to count all the occurences
        }
    }
    return -1; // no majority element
} // O(n^2) time 

int majorityElBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    for(int el : arr) mpp[el]++; // storing frequency of each element
    for(auto el : mpp) if(el.second > arr.size() / 2) return el.first;
    return -1;
} // O(2n) time and O(n) space

int majorityElMoreBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    for(int el : arr) {
        mpp[el]++;
        // as soon as the frequency of element increased here to be more than n/ 2 or simply n/2 + 1, we return early and are not interested in calculating its actual frequency
        if(mpp[el] == arr.size() / 2 + 1) return el;
    }
    return -1;
} // single pass O(n) time and O(n) space


// the entire moore voting algo is based on the simple logic that if there exists a majority element, that is more than n/2 times it occurs, then it cannot be cancelled or there is not enough fire power to cancel that element

// the intuition of the algo, is that we cosndier one elements as majority element and start counter = 1, when we find its occurence we increase the counter and we find any other we decrease the counter, if counter = 0 (means it was cancelled, means it didnt have more than n/2 occurences, otherwise it was impossible to cancel it, so at the end of iteration we have a el and IF THE MAJORITY ELEMENT EXISTS, IT WILL BE ELEMENT LEFT AT THE END OF ITERATION ELSE NO MAJORITY element)

int majorityElOptimal(const vector<int> &arr) {

    int ans, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(count == 0) {
            ans = arr[i]; // if count zero then pick a new element
            count = 1; // and make its count = 1
        } else if(arr[i] == ans) {
            count++;
        } else {
            count--;
        }
    } 

    // in the end count basically has no significance
    // now check if ans occurs more than n/2 times, if it does then its the majority
    // no need to do this check if it is given that there always exists a majority element

    count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == ans) count++;
    }

    if(count > arr.size() / 2) return ans;
    return -1;
} // O(2N) time 


int main() {
    
    return 0;
}