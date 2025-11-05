#include<bits/stdc++.h>
using namespace std;

// Brute force involves generating all permutations and then going from there, just make sure to sort all the permutations and return the next permutation
// Time complexity : O(n!). Total possible permutations is n!.
// Space complexity : O(n). Since an array will be used to store the permutations.

// Better solution is using cpp stl's inbuilt next_permutation function 
void nextPermutationBetter(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
}

// so we have to make the changes in the nums array 
// find the breakpoint or the index where we have the longest prefix match
// REVISE THIS THOUROUGHLY

void nextPermutationOptimal(vector<int> &nums) { // we have to do it in in-place in nums

    int breakPoint = -1;
    for(int i = nums.size() - 2; i >= 0; i--) { // starting from back since we want longest prefix
        if(nums[i] < nums[i + 1]) {
            breakPoint = i;
            break;
        }
    }
    if(breakPoint == -1) {
        // there is no dip since it is last permutation, so just reverse and return the answer
        reverse(nums.begin(), nums.end()); 
        return;
    }
    // now we find the next greater element for arr[breakPoint] to replace it with (just slightly greater than arr[breakPoint]), thats why we start from back since we know it is decreasing order so we would get just greater from the back
    for(int i = nums.size() - 1; i >= breakPoint; i--) {
        if(nums[i] > nums[breakPoint]) {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    // now place remaining in sorted order, since we know arr from breakPoint to n - 1 is sorted in descending order we reverse it to get the arrangement
    reverse(nums.begin() + breakPoint + 1, nums.end());

} // O(3N) time and O(1) space

int main() {
    
    return 0;
}