#include<bits/stdc++.h>
using namespace std;

// we have to find the minimum value of a positive integer called divisor, which when divides whole array and we sum the division's, the result should be <= threshold
// in the division consider the ceil values

///////////////////////////////////////////////////////////////////////////////////////

// so we again start by finding the range of answer, the min value of answer can be 1 since its clearly mentioned that divisor is a positive integer and the min positive integer == 1 and the max value of divisor can be max_element as that will divide everything and the sum of them will be n (size of array) and it is given that threshold >= n, so it will always be our answer

// now once we know the range we simply have to check one by one for all this values if sum <= threshold then we return that answer as the smallest possible divisor

int smallestDivisorBrute(vector<int> &nums, int threshold) {

    int maxDiv = *max_element(nums.begin(), nums.end());

    for(int div = 1; div <= maxDiv; div++) {

        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            result += ceil((double)nums[i] / div);
            if(result > threshold) break;
        }

        if(result <= threshold) return div;
    }

    return maxDiv; // we are guranteed to have an answer so will not be executed

} // O(maxel * n) time

//////////////////////////////////////////////////////////////////////////////////////

// since we already know the range of answer its pretty easy to write a binary search solution for this

int smallestDivisorOptimal(vector<int> &nums, int threshold) {

    int low = 1, high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // we check for the mid day

        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            result += ceil((double)nums[i] / mid);
            if(result > threshold) break;
        }

        if(result <= threshold) {
            ans = mid;
            high = mid - 1; // take it as an answer but look for smaller divisors on left
        } else {
            low = mid + 1; // we try to reach the answer  
        } 
    }

    return ans;

} // O(log(maxelement) * n) time

int main() {
    
    return 0;
}