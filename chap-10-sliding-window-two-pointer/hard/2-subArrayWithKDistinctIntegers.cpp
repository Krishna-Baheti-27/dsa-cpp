#include<bits/stdc++.h>
using namespace std;

// same as previous question but here we want the subarray having exactly k distinct integers and not atmost k, and we want to count their occurences not max lenth

// brute force involves generating all subarrays and then we count all the subarrays having exactly k different integers

int countSubarraysHavingKDistinctIntegersBrute(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        unordered_set<int> st;
        for(int j = i; j < arr.size(); j++) {
            st.insert(arr[j]);
            if(st.size() == k) count++;
            else if(st.size() > k) break;
        }
    }
    return count;
} // O(N^2) time and O(N) space for set

// this works the same way as we did before, here we first find the number of subarrays having at most k distinct integers or integers <= k (which is easy to find) and from it we subtract the number of subarrays having atmost k - 1 distinct integers <= k - 1, to get the number of  subarrays having exactly k distinct integers

int countSubarraysHavingAtmostKDistinctIntegersBetter(vector<int> &arr, int k) {
    if(k < 0) return 0;
    int l = 0, r = 0, count = 0;
    unordered_map<int,int> mpp;
    while(r < arr.size()) {
        mpp[arr[r]]++;
        while(mpp.size() > k) { // here we cant optimise this by if, since we are actually counting the valid subarrays, if we had min/max thingy we could do that since it wont affect our answer
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        count += (r - l + 1); // add the new valid subarrays, same as window length
        r++;
    }
    return count;
} // O(2N) time, O(N) space

int countSubarraysHavingKDistinctIntegersOptimal(vector<int> &arr, int k) {
    return countSubarraysHavingAtmostKDistinctIntegersBetter(arr, k) - countSubarraysHavingAtmostKDistinctIntegersBetter(arr, k - 1);
} // O(4N) time and O(2N) space

int main() {
    
    return 0;
}