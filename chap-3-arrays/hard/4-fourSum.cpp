#include<bits/stdc++.h>
using namespace std;

// we have to return the quadruplets having four different indices
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct. // very imp
// nums[a] + nums[b] + nums[c] + nums[d] == target
// hence return any one combination of nums[a], nums[b], nums[c], nums[d] since the combination is not required but four different indices are required

vector<vector<int>> fourSumBrute(vector<int> &arr, int target) {
    set<vector<int>> st;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            for(int k = j + 1; k < arr.size(); k++) {
                for(int l = k + 1; l < arr.size(); l++) {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
} // O(n^n^n^n) time and O(no of quads) * 2

vector<vector<int>> fourSumBetter(vector<int> &arr, int target) {
    // to optimise O(n^n^n^n) we can trim it to O(n^n^n)
    set<vector<int>> st;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            // similar to threeSum, we will maintain a hashh set between j and k
            set<long long> hashh;
            for(int k = j + 1; k < arr.size(); k++) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if(hashh.find(fourth) != hashh.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashh.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
} // O(n^n^n X logm), where m is the number of elements in hashh set at that instance

vector<vector<int>> fourSumOptimal(vector<int> &arr, int target) {
    // here we have to get rid of st which we used to store only unique occurences and also get rid of hashh set for looking up in array
    // so first sort the array
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    // now same as in three sum, we will fix 2 pointers i and j and move other k and l
    for(int i = 0; i < arr.size(); i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        for(int j = i + 1; j < arr.size(); j++) {
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;
            // else now we finally initialise our two pointers k and l
            int k = j + 1;
            int l = arr.size() - 1;
            while(k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum > target) l--; // decrease the sum
                else if(sum < target) k++; // increase the sum
                else {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    // since we dont want the same thing again but what if arr[k] == arr[k - 1] or 
                    // arr[l] ==  arr[l + 1]
                    while(k < l && arr[k] == arr[k - 1]) k++;
                    while(k < l && arr[l] == arr[l + 1]) l--;
                }
            }
        }
    }
    return ans;
}  // O(n^n^n + nlogn) time and O(1) space 

int main() {
    
    return 0;
}