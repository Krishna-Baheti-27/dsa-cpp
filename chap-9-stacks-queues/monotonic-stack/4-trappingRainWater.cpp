#include<bits/stdc++.h>
using namespace std;

// water would be trapped only if there exists a valley or if there is a taller building on left and right both 
// here leftMax means max height building on left of arr[i] and similary rightMax

// the amount of water trapped by one building = min(leftMax, rightMax) - arr[i] for one building, and the total water trapped is sum of all the water trapped, if arr[i] == leftMax or rightMax then this would be 0 which makes sense

// now how to find this leftMax and rightMax, for that we maintain two arrays prefixMax which stores the max encoutered at each element from left up until that element and suffixMax which stores the max encountered at each element from right up until that element and thus we would be able to access the leftMax and rightMax thus far for all elements 

int trapWaterBrute(vector<int> &arr) { 

    vector<int> prefixMax(arr.size()), suffixMax(arr.size());

    // first compute prefixMax and suffixMax
    int leftMax = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        leftMax = max(leftMax, arr[i]);
        prefixMax[i] = leftMax;
    }
    int rightMax = arr[arr.size() - 1];
    for(int i = arr.size() - 1; i >= 0; i--) {
        rightMax = max(rightMax, arr[i]);
        suffixMax[i] = rightMax;
    }

    // now water trapped = min(prefixMax, suffixMax) - arr[i]

    int waterTrapped = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < prefixMax[i] && arr[i] < suffixMax[i]) { // condition for valley
            waterTrapped += min(prefixMax[i], suffixMax[i]) - arr[i];
        // if arr[i] == prefixMax or suffixMax then it would be 0 and its logical since no valley
        }
    }

    return waterTrapped;
} // O(3N) time and O(2N) space


// we can actually optimise this by just computing suffixMax and maintaining a leftMax variable instead of an array since we are anyway traversing from left to right

int trapWaterBetter(vector<int> &arr) {

    vector<int> suffixMax(arr.size());

    int leftMax = arr[0]; // initially

    int rightMax = arr[arr.size() - 1];
    for(int i = arr.size() - 1; i >= 0; i--) {
        rightMax = max(rightMax, arr[i]);
        suffixMax[i] = rightMax;
    }
     
    int waterTrapped = 0;
    for(int i = 0; i < arr.size(); i++) {
        leftMax = max(leftMax, arr[i]);
        if(arr[i] < leftMax && arr[i] < suffixMax[i]) { // condition for valley
            waterTrapped += min(leftMax, suffixMax[i]) - arr[i];
        }
    }
    return waterTrapped;
} // O(2N) time and O(N) space

// now we know water trapped, min(leftMax, rightMax) - arr[i], so we dont actually need both leftMax and rightMax but only min of them so we need only one of leftMax or rightMax to calculate thw water blocked by building and that too smaller one

// we only have to focus on min(lMax, rMax) so if we sure that we processing smaller first so if arr[l] <= arr[r] then it is guranteed that lMax < rMax => min(lMax, rMax) = lMax and if arr[r] < arr[l], so here arr[r] is smaller to min(lMax, rMax) = rMax

int trapWaterOptimal(vector<int> &arr) {
    int lMax = 0, rMax = 0, waterTrapped = 0, l = 0, r = arr.size() - 1;
    
    while(l < r) {
        if(arr[l] <= arr[r]) {
            // we always process the smaller element first
            if(arr[l] < lMax) waterTrapped += lMax - arr[l];  // water trapped
            else lMax = arr[l]; // new left max (no water since arr[l] is itself new lMax)
            l++; // move l ahead
        } else {
            // process arr[r] since its smaller
            if(rMax > arr[r]) waterTrapped += rMax - arr[r];
            else rMax = arr[r];
            r--; // move r behind
        }
    }
    
    return waterTrapped;
} // O(N) time and O(1) space

// now to the core of how this works, when we are standing at l, we know the true lMax, since we are traversing from left, and if we have arr[l] <= arr[r] then it is guranteed that there is atleast one bar on right taller than our current wall arr[l], becuase arr[r] exists the true rMax is guranteed to be as tall as arr[r], 

// rMax >= arr[r] >= arr[l] 

// Now, consider the lMax we are tracking. It was built from bars to the left of l. When we calculate water at position l, the formula needs min(lMax, rMax).

// Since we already know rMax >= arr[r] and we are in the case where arr[r] >= arr[l], the rMax is guaranteed to be greater than or equal to the current lMax (because lMax is also built from walls that are arr[l] or smaller). Therefore, it is guaranteed that lMax <= rMax

// this means min(lMax, rMax) = lMax, so we can confidently trap the water without ever knowing true value of rMax

int main() {
    
    return 0;
}