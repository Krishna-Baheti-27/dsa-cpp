#include<bits/stdc++.h>
using namespace std;

// we have to return the triplets having sum == 0, where we cant take the same element twice which is clear by [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k and we have to make sure that we do not return any duplicate triplets that is [-1, 0, 1] is same as [1, -1, 0]

//////////////////////////////////////////////////////////////////////////////////////

// in the brute force approach to deal with duplciates we are simply sorting them and storing in set and then convertin set back into 2d array 

vector<vector<int>> threeSumBrute(vector<int> &arr) {

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

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
} // O(N^3 x log(no of unique triplets)) time, O(no of unique) space

//////////////////////////////////////////////////////////////////////////////////////

// the better approach here uses the same complement approach as we used in two sum that is we are lookin for target and if we find target - arr[i] then we are sure that we have pair

vector<vector<int>> threeSumBetterMap(vector<int> &arr) {

    set<vector<int>> st;

    for(int i = 0; i < arr.size(); i++) {

        // when finding triplets for a particular element we maintain the map from the next position so that we dont see same indices as we strictly want i != j != k

        // so i stays constant and we move j from i + 1 to n - 1 and each time check if we have third element in map using (target - arr[i] - arr[j])

        unordered_map<int, int> mpp;

        for(int j = i + 1; j < arr.size(); j++) {
            
            int thridEl = 0 - arr[i] - arr[j];

            if(mpp.find(thridEl) != mpp.end()) { // element found
                
                vector<int> temp = {arr[i], arr[j], 0 - arr[i] - arr[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            mpp[arr[j]]++; // we make sure that we have arr[j] in map
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

} // O(n^2 * log(no. of unique triplets)) time and O(no. of unique) + O(n) space for map

/////////////////////////////////////////////////////////////////////////////////

// this is very standard pattern when we dont want to have duplicates and dont want to use set also then we sort the array so that we dont fget duplicates in future as we skip them

vector<vector<int>> threeSumOptimal(vector<int> &arr) {

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i = 0; i < arr.size(); i++) {

        // skip the duplicate that if curr element == prev element then simply continue
        if(i > 0 && arr[i] == arr[i - 1]) continue; 

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
                // always take base case at the last, here it is sum == 0
                ans.push_back({arr[i], arr[j], arr[k]}); // since i,j,k are already in sorted order
            
                // since we dont want them again since it would mean duplicates
                j++;
                k--; 

                // but what if arr[j - 1] == arr[j] so again same element then again do j++ till we get different and we have to do this for k also since i is already same and if k also remains same by chance then again j would be same and we would have duplicate triplet, by same here i mean same value and not same indices

                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
} // O(nlogn + n^2) time and O(1) space

int main() {
    
    return 0;
}