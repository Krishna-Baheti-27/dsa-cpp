#include<bits/stdc++.h>
using namespace std;

// we have to find the minimum value of integer divisor, which when divides whole array and we sum the division's, the result should be <= threshold

int smallestDivisorBrute(vector<int> &nums, int threshold) {
    // minimum value of divisor can be 1, and maximum value can be max_element of nums because that will divide everything and ceil will be 1 and the result of sum will be == threshold
    int div, maxDiv = *max_element(nums.begin(), nums.end());
    for(div = 1; div <= maxDiv; div++) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result += ceil((double)nums[i] / div);
        }
        if(result <= threshold) return div;
    }
    return maxDiv; // technically wont hit since there will be answer
} // O(maxel * n)

int smallestDivisorOptimal(vector<int> &nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // we check for the mid day
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result += ceil((double)nums[i] / mid);
        }
        if(result <= threshold) high = mid - 1; // take it as an answer but look for better
        else low = mid + 1; // we try to reach the answer
    }
    return low; // low became possible from not possible hence our answer
}

int main() {
    
    return 0;
}