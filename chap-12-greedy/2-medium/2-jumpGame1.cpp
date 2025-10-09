#include<bits/stdc++.h>
using namespace std;

// if the array doesnt have zeroes then we are guranteed to reach the last index of the array since there is no one stopping us

// ok so how do we solve it

// we maintain a maxIdx vairable which tells us how far at max we can go, maxIdx is obtained by replacing it with with index + nums[index] if it is greater, if in an iteration we get maxIdx >= nums.size() - 1 then we can reach the end but in any moment if of iteration if i crossed maxIdx then we return false as its not possible

// here the greedy approach is always trying to jump the max and checking if we made it or crossed the limit to which we were allowed, the main catch is 0, if you are able to cross zero you will reach it else not and if there are no zeroes then you are guranteed to reach the end

bool canJump(vector<int> &nums) {
    int maxIdx = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(i > maxIdx) return false;
        maxIdx = max(maxIdx, i + nums[i]);
        if(maxIdx >= nums.size() - 1) return true;
    }
    return true; // not really needed
} // O(N) time

int main() {
    
    return 0;
}