#include<bits/stdc++.h>
using namespace std;

// Brute force involves generating all permutations and then going from there, just make sure to sort all the permutations and return the next permutation

// Better solution is using cpp stl's inbuilt next_permutation function 

void nextPermutationOptimal(vector<int> &nums) {
    // so we have to make the changes in the nums array 
    // find the breakpoint or the index where we have the longest suffix match
    int breakPoint = -1;
    for(int i = nums.size() - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            breakPoint = i;
            break;
        }
    }
    if(breakPoint == -1) {
        reverse(nums.begin(), nums.end()); 
        // there is no dip since it is last permutation, so just reverse and return the answer
        return;
    }
    // now we find the next greater element for arr[breakPoint] to replace it with (just slightly greater)
    for(int i = nums.size() - 1; i >= breakPoint; i--) {
        if(nums[i] > nums[breakPoint]) {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    reverse(nums.begin() + breakPoint + 1, nums.end());
} // O(3N) time and O(1) space

int main() {
    
    return 0;
}