#include<bits/stdc++.h>
using namespace std;

// you are splitting the given array into k subarrays and each subarray has atleast one element (cannot be empty subarray) and now we have to find the largest possible sum of individual k subarrays, for a particular configuration and we have to find min of all such configurations and return it

// in simple words, split the array into k non empty subarrays such that largest sum of a particular subarray from all configurations is minimum

// since the subarrays are continuous so the divide must also be contiguous 

//////////////////////////////////////////////////////////////////////////////////////

// so the problem is exactly same as book allocation if you pay close attention, there we had to split n books to m students such that (no student is empty) and max pages assigned to any student is min

// here we have to split an array of n size into k non empty subarrays such that max sum of any subarray thus assigned is min

// so now to find the range of answer
// so the min value of answer is max_element when we only consider a single element as a subarray so it must be max since that is our condition, and the max value of answer is sum of entire array since there can be case of k = 1 then the entire array acts as subarray and the sum of subarray will be the sum of array

// now writing the brute force linear search solution since we are aware of the approach

int splitArrayBrute(vector<int> &nums, int k) {

    int minSum = *max_element(nums.begin(), nums.end());
    int maxSum = reduce(nums.begin(), nums.end(), 0);

    for(int sum = minSum; sum <= maxSum; sum++) {

        // now here we check wherther its possible for us to maintain a max sum of 'sum' and still divide the array into k non empty halves

        int arrSplits = 1, currSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(currSum + nums[i] <= sum) {
                currSum += nums[i];
            } else {
                arrSplits++;
                currSum = nums[i];
            }
        }

        if(arrSplits == k) return sum; // min possible value of largest sum

    }

    return maxSum; // would not hit 

} // O(sum - max element) * O(n) time

/////////////////////////////////////////////////////////////////////////////////////

// now since we already know the range of answer its pretty easy to apply binary search on answers the only tricky bit is how to find whether a following config is possible or not and for that we write the function

int splitCount(vector<int> &nums, int mid) {

    int arrSplits = 1, currSum = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(currSum + nums[i] <= mid) {
            currSum += nums[i];
        } else {
            arrSplits++;
            currSum = nums[i];
        }
    }

    return arrSplits;
}

int splitArrayOptimal(vector<int> &nums, int k) {

    int low = *max_element(nums.begin(), nums.end());
    int high = reduce(nums.begin(), nums.end(), 0);
    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // check if the value of mid is a valid sum such that we can divide the array into k non empty subarrays and overall max sum of config == mid (which is min)

        int arrSplits = splitCount(nums, mid);

        if(arrSplits <= k) {
            ans = mid; // take it as a possible answer
            high = mid - 1; // but look for min
        } else {
            low = mid + 1; // try to reach the answer
        }

        // you can also break it down and write 3 statements those are arrSplits == k and then arrSplits < k but these two are essentially same

    }

    return ans;

} // O(log(sum - max) * n) time

int main() {
    
    return 0;
}