#include<bits/stdc++.h>
using namespace std;

// same as jump game 1 but here are guranteed to reach the index n - 1 but we have to do in min number of jumps, so return the min jumps to reach index n - 1

//////////////////////////////////////////////////////////////////////////////////////

// the brute force involves trying all ways to jump and counting the number of jumps in each way and then returning the min, and here we have to try all possible ways and hence recursion and since we want min possible jumps so as soon as we get to the n - 1 th index we stop and return the answer

int helper(int index, vector<int> &nums, int jumps) {

    // this would return all possible answers we want minimum number of jumps

    if(index >= nums.size() - 1) {
        return jumps;
    }

    // this will help us return the min at each level of recursive call and thus the total minJumps

    int minJumps = INT_MAX;

    // for the give index you can jump from index + 1 to index + nums[index] because nums[index] is the max value you can jump, so we try all possible combinations for given index from index + 1 to index + nums[index] and store the min in our answer and then return

    // for each level we calculate new minJumps which is then returned to parents by propagating upwards, we can also pass minJumps by reference if you dont want to do it personally

    for(int i = 1; i <= nums[index]; i++) {
        minJumps = min(minJumps, helper(index + i, nums, jumps + 1)); 
    }

    return minJumps;
}

int jumpsBrute(vector<int> &nums) {
    return helper(0, nums, 0);
} // O(n ^ n) time assuming all indexes jump to n in worst case and O(n) recursion stack space

// The computed minimum isn't lost because it's propagated upwards through the call stack via return statements. The parent call uses the child call's returned value to update its own local minimum. This process continues all the way up to the initial call in jumpsBrute.

///////////////////////////////////////////////////////////////////////////////////

// we can optimise it using dynamic programming to O(N^2) time and O(N^2) space

///////////////////////////////////////////////////////////////////////////////////

// now we have to optimise it to O(N), similar to valid parenthesis where we optimised the recursion for all possible combinations by maintaining the range of answer, similarly here we maintain the range we can reach in jump using l and r to point at indices, so in each jump l goes 1 place ahead of r and r reaches max till we can jump thus maintaining our range and jumps variable

int jumpsOptimal(vector<int> &nums) {

    int jumps = 0, l = 0, r = 0;

    // if r >= n - 1 we stop since we reached our answer
    // this while loop is just to check did you reach
    // and its guranteed that we will reach the end (thats what the question states)

    while(r < nums.size() - 1) { 

        int farthest = 0;

        // for the range [l ,r] we check every index to find the farthest we can travel

        for(int index = l; index <= r; index++) { 
            farthest = max(farthest, index + nums[index]);
        }

        // the new range would be [r + 1, farthest], initially it was [l,r] so we are not skipping anything and it is continuous

        l = r + 1;
        r = farthest;

        // and for travelling each range we take one jump since we can take max jump and that what we are doing in each iteration

        jumps++; 

    }

    return jumps;

} // O(N) time in total

// so how does greedy work here, see to get to the index n - 1 in minJumps we always had to take the farthest possible jumps, so in our range of [l,r] we are always finding farthest possible jumps and taking it thus getting new range, so greedly look for the max possible jump in each range and take that update the range accordingly

// MAJOR DOUBT / WORRY

// we took the farthest possible jump in the range which got us somehere which was small and instead if we had taken a little bit smaller jump than the farthest we would have reached an index that takes way far

// ??????????????????????????????????????

// The code doesn't just check one jump. The for loop iterates through every single index in the entire current range [l, r].
// farthest is not "the farthest I can jump from l". farthest is "the farthest I can jump from any index I could have possibly landed on in my previous jump (checking everythin from l to r to not miss any).

int main() {
    
    return 0;
}