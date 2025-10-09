#include<bits/stdc++.h>
using namespace std;

// same as jump game 1 but here are guranteed to reach the index n - 1 but we have to do in min number of jumps, so return the min jumps to reach index n - 1

// the brute force involves trying all ways to jump and counting the number of jums in each way and then returning the min, and here we have to try all possible ways and hence recursion and since we want min possible jumps so as soon as we get to the n - 1 th index we stop and return the answer

int helper(int index, vector<int> &nums, int jumps) {
    if(index >= nums.size() - 1) return jumps; // this would return all possible answers we want minimum number of jumps
    int minJumps = INT_MAX; // this will help us return the min at each level of recursive call and thus the total minJumps
    for(int i = 1; i <= nums[index]; i++) {
        minJumps = min(minJumps, helper(index + i, nums, jumps + 1)); 
    }
    return minJumps;
}

// The computed minimum isn't lost because it's propagated upwards through the call stack via return statements. The parent call uses the child call's returned value to update its own local minimum. This process continues all the way up to the initial call in jumpsBrute.

int jumpsBrute(vector<int> &nums) {
    return helper(0, nums, 0);
} // O(N^N) time assuming all indexes jump to N in worst case and O(N) recursion stack space

// we can optimise it using dynamic programming in O(N^2) time 

// now we have to optimise it to O(N), similar to valid parenthesis where we optimised the recursion for all possible combinations by maintaining the range of answer, similarly here we maintain the range we can reach in jump using l and r to point at indices, so in each jump l goes 1 place ahead of r and reached max till we can jump thus maintaining our range and jumps variable

int jumpsOptimal(vector<int> &nums) {
    int jumps = 0, l = 0, r = 0;
    while(r < nums.size() - 1) { // if r >= n - 1 we stop since we reached our answer
        // this while loop is just to check did you reach
        int farthest = 0;
        // for the range [l ,r] we find the farthest we can travel
        for(int index = l; index <= r; index++) { // we are travelling every index
            farthest = max(farthest, index + nums[index]);
        }
        // the new range would be [r + 1, farthest]
        l = r + 1;
        r = farthest;
        jumps++; // and for travelling each range we take one jump
    }
    return jumps;
} // O(N) time in total

// so how does greedy work here, see to get to the index n - 1 in minJumps we always had to take the farthes possible jumps, so in our range of [l,r] we are always finding farthes possible jumps and taking it thus getting new range

int main() {
    
    return 0;
}