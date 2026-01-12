#include<bits/stdc++.h>
using namespace std;

// given an array having values which represent how much max can you jump from that index
// assuming we are starting from the 0th index, we have to tell whether we can reach the last index or not, if encounter a 0 that means max jump of 0 which means we are stuck and cant reach the last index

///////////////////////////////////////////////////////////////////////////////////////

// again dp works but no need to do this much effort

// if the array doesnt have zeroes then we are guranteed to reach the last index of the array since there is no one stopping us

// we maintain a maxIdx vairable which tells us how far at max we can go, maxIdx is obtained by replacing it with with index + nums[index] if it is greater, if in an iteration we get maxIdx >= nums.size() - 1 then it straight up tells us that we can reach the end but in any moment of iteration if i crossed maxIdx then we return false as its not possible

// because as we kept that we can atmax reach the max index so if i > maxIdx means it was not possible to reach here but we somehow did hence return false

// here main reason greedy works because an index represents the max jump and not the exact jump so we just have to hit that index which gives us enough fire power

bool canJump(vector<int> &nums) {

    int maxIdx = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(i > maxIdx) return false;
        maxIdx = max(maxIdx, i + nums[i]);
        if(maxIdx >= nums.size() - 1) return true;
    }

    return true; // not really needed but to avoid warnings
    
} // O(N) time

int main() {
    
    return 0;
}