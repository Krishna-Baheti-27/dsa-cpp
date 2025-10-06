#include<bits/stdc++.h>
using namespace std;

// you are splitting the given array into k subarrays, (same as splitting the wall between k painters), now each painter woudld take sum of the subarray allocated to that painter
// so time taken to paint the wall is maximum time taken by the painter or is the max sum of the k subarrays, now we have to find minimum of such maximums

// now since subarrays are contiguous, so the divide must also be contiguous
// so we have split it in such a way that maximum subarray sum is minimum

// this is same as book allocation, there we had to split n books into m students and find min of max pages
// similarly here we have to split the wall, (n elements of the array) into k painters or subarray such that max sum of its subarrays is min

// so the min value of answer is max_element, when each painter is painting only a single part of wall the min time will be max_element of array and max value of answer is sum of all elements (when there is single painter)

int splitArrayBrute(vector<int> &nums, int k) {
    int minTime = *max_element(nums.begin(), nums.end());
    int maxTime = reduce(nums.begin(), nums.end(), 0);
    for(int time = minTime; time <= maxTime; time++) {
        // now how to calculate total time, simply divide n elements to k painters
        int painterNo = 1, painterPainted = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(painterPainted + nums[i] <= time) {
                painterPainted += nums[i];
            } else {
                painterNo++;
                painterPainted = nums[i];
            }
        }
        if(painterNo <= k) return time;
    }
    return -1; // would not hit
} // gives TLE on leetcode

int splitArrayOptimal(vector<int> &nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = reduce(nums.begin(), nums.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int painterNo = 1, painterPainted = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(painterPainted + nums[i] <= mid) {
                painterPainted += nums[i];
            } else {
                painterNo++;
                painterPainted = nums[i];
            }
        }
        if(painterNo <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int splitArrayOptimal(vector<int> &nums, int k) {

}

int main() {
    
    return 0;
}