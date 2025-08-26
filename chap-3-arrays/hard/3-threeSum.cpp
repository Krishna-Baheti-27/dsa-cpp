#include<bits/stdc++.h>
using namespace std;

// return all triplets such that their sum is zero and not any duplicates, and to ensure we dont have any duplicates we will be sorting

vector<vector<int>> threeSumBrute(vector<int> &arr) {
    vector<vector<int>> ans;
    set<vector<int>> st; // to ensure no duplicates are being filled
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            for(int k = j + 1; k < arr.size(); k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    // this is our triplet so we just store and sort this and insert in the set
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    } 
    for(auto &el : st) {
        ans.push_back(el);
    }
    return ans;
} // O(N^N^N x log(no of unique)) time, O(2 * no of unique) // space

vector<vector<int>> threeSumBetterMap(vector<int> &arr) {
    set<vector<int>> st;
    for(int i = 0; i < arr.size(); i++) {
        unordered_map<int, int> mpp;
        for(int j = i + 1; j < arr.size(); j++) {
            // we maintain the hashh map only in the range i + 1 to j - 1 so when we find the thirdEl = -(arr[i] + arr[j]) ,the map doesnt return us something like arr[i] or arr[j] again
            int thridEl = 0 - arr[i] - arr[j];
            if(mpp.find(thridEl) != mpp.end()) {
                // element found
                vector<int> temp = {arr[i], arr[j], 0 - arr[i] - arr[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            mpp[arr[j]]++;
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
} // gives TLE, O(N^N * logM), M is the number of elements map ,which is variable

vector<vector<int>> threeSumBetterSet(vector<int> &arr) {
    set<vector<int>> st;
    for(int i = 0; i < arr.size(); i++) {
        set<int> hashh;
        for(int j = i + 1; j < arr.size(); j++) {
            // we maintain the hashh map only in the range i + 1 to j - 1 so when we find the thirdEl = -(arr[i] + arr[j]) ,the map doesnt return us something like arr[i] or arr[j] again
            int thridEl = 0 - arr[i] - arr[j];
            if(hashh.find(thridEl) != hashh.end()) {
                // element found
                vector<int> temp = {arr[i], arr[j], 0 - arr[i] - arr[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashh.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
} // gives TLE, O(N^N * logM), M is the number of elements in set ,which is variable

vector<vector<int>> threeSumOptimal(vector<int> &arr) {
    // here we wont use the set data structure to identify the unique elements, instead we sort the array and devise our algo in such a way that there are no unique
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < arr.size(); i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue; // we have had this value before we want something new
        int j = i + 1;
        int k = arr.size() - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {
                // we need to increase the sum and the array is sorted and hence move j
                j++;
            } else if(sum > 0) {
                // we need to decrease the sum and the array is sorted and hence move k
                k--;
            } else {
                // always take base case at the last
                ans.push_back({arr[i], arr[j], arr[k]}); // since i,j,k are already in sorted order
                j++;
                k--; 
                // since we dont want them again but what if we get them again
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
} // O(nlogn + n^n) time and O(1) space

int main() {
    
    return 0;
}