#include<bits/stdc++.h>
using namespace std;

// print all the subarrays having sum = k, basically return the indices of start and end of subarray in any possible order

// brute involves generating all possible subarrays
vector<vector<int>> subarraysHavingSumKBrute(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if(sum == k) {
                ans.push_back({i ,j});
            }
        }
    }
    return ans;
} // O(n^2) time

// the better solution uses hashing, and its also optimal for array containing negatives
vector<vector<int>> subarraysHavingSumKBetter(vector<int> &arr, int k) {
    int sum = 0;
    vector<vector<int>> ans;
    // Map stores: {prefix_sum -> list_of_indices_where_it_occurred}
    unordered_map<int,vector<int>> mpp; // for each sum we are storing all the indices at which it occured
    mpp[0].push_back(-1); // {-1} for handling subarrays starting from index 0
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(mpp.find(sum - k) != mpp.end()) {
            for(int startIdx : mpp[sum - k]) {
                ans.push_back({startIdx + 1, i});
                // storing all possible subarrays or indices having sum as sum - k 
            }
        }
        mpp[sum].push_back(i); // push in the vector all the indices i having sum as sum
    }
    return ans;
} // O(N^2) time in worst case when all subarrays have sum k, else O(2N) time and O(N) space

// the most optimal solution using sliding window and two pointer but only for array containing positives and zero

vector<vector<int>> subarraysHavingSumKOptimal(vector<int> &arr, int k) {
    int sum = 0, l = 0, r = 0;
    vector<vector<int>> ans;
    while(r < arr.size()) {
        sum += arr[r];
        while(sum > k) {
            sum -= arr[l];
            l++;
        }
        if(sum == k) ans.push_back({l , r});
        r++;
    }
    return ans;
}
// Note: This simple sliding window finds only the longest subarray ending at r that sums to k. For example, in [1, 2, 3, 0] with k=3, it would find [1,2] and [3,0] but miss [3]. Finding all subarrays with sliding window is significantly more complex. The hash map approach is generally preferred for this specific problem ("find all").

// Hardly ever used
std::vector<std::vector<int>> findAllSubarrays(const std::vector<int>& arr, int k) {
    std::vector<std::vector<int>> ans;
    int l = 0, r = 0;
    long long sum = 0;

    while (r < arr.size()) {
        // 1. Expand the window to the right
        sum += arr[r];

        // 2. Shrink the window from the left if the sum exceeds k
        while (l <= r && sum > k) {
            sum -= arr[l];
            l++;
        }

        // 3. If sum is k, process all valid subarrays ending at r
        if (sum == k) {
            // The window [l...r] is a valid subarray
            ans.push_back({l, r});
            
            // Check for additional subarrays by trimming leading zeros
            // If [l...r] sums to k and arr[l] is 0, then [l+1...r] also sums to k.
            int temp_l = l;
            while (temp_l < r && arr[temp_l] == 0) {
                temp_l++;
                ans.push_back({temp_l, r});
            }
        }
        
        // 4. Continue expanding the window
        r++;
    }

    return ans;
}

int main() {
    
    return 0;
}