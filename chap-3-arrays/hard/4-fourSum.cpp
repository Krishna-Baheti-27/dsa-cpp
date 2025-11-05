#include<bits/stdc++.h>
using namespace std;

// we have to return the quadruplets having four different indices
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct. // very imp
// nums[a] + nums[b] + nums[c] + nums[d] == target

// hence return any one combination of nums[a], nums[b], nums[c], nums[d] since the combination is not required but four different indices are required and we only need to return unique combinations not all the combinations and they can be returned in any order

//////////////////////////////////////////////////////////////////////////////////////

// to enforce this unique constraint we are again using set to and we store by sorting qudruplets so that we dont have any duplicate combinations

vector<vector<int>> fourSumBrute(vector<int> &arr, int target) {

    set<vector<int>> st;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            for(int k = j + 1; k < arr.size(); k++) {
                for(int l = k + 1; l < arr.size(); l++) {

                    // to prevent overflow for even long long

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

} // O(n^4) time and O(no of unique quads) space

//////////////////////////////////////////////////////////////////////////////////////

// now same the better approach here is to trim O(n^4) to O(n^3) using hashing or complement approach to find

vector<vector<int>> fourSumBetter(vector<int> &arr, int target) {
    
    set<vector<int>> st;

    for(int i = 0; i < arr.size(); i++) {

        for(int j = i + 1; j < arr.size(); j++) {

            // similar to threeSum, we will maintain a hashh set between j and k

            unordered_set<long long> hashh;

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

} // O(n^3) time and O(no of unique) + O(n) space

////////////////////////////////////////////////////////////////////////////////////////

// here we have to get rid of st which we used to store only unique occurences and also get rid of hashh set for looking up in array
// so first sort the array, again standart variety

vector<vector<int>> fourSumOptimal(vector<int> &arr, int target) {
    
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    // now same as in three sum, we will fix 2 pointers i and j and move other k and l

    for(int i = 0; i < arr.size(); i++) {

        if(i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates

        for(int j = i + 1; j < arr.size(); j++) {

            if(j > i + 1 && arr[j] == arr[j - 1]) continue; // skip duplicates

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

}  // O(n^3 + nlogn) time and O(1) space 

// hence we can generalise any k - sum algo as O(n^(k - 1) + nlogn) time and O(1) space
// but for two sum, the hashing solution is better time wise and two pointer is better space wise

int main() {
    
    return 0;
}