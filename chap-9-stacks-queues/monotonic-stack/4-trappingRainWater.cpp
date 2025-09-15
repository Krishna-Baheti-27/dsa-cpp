#include<bits/stdc++.h>
using namespace std;

// the amount of water trapped = min(leftMax, rightMax) - arr[i] for one building, if and only if arr[i] < leftMaz and arr[i] < rightMax (basically formation of valley) and the total water trapped is sum of all the water trapped

// now how to find this leftMax and rightMax, for that we maintain two arrays prefixMax which stores the max encoutered at each element from left up untill that element and suffixMax which stores the max encountered at each element from right up untill that element

int trapWaterBrute(vector<int> &arr) {
    // first compute prefixMax and suffixMax
    vector<int> prefixMax(arr.size()), suffixMax(arr.size());
    prefixMax[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }
    suffixMax[arr.size() - 1] = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--) {
        suffixMax[i] = max(arr[i], suffixMax[i + 1]);
    }
    // now water trapped = min(leftMax or prefixMax, rightMax or suffixMax) - arr[i]
    int waterTrapped = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < prefixMax[i] && arr[i] < suffixMax[i]) { // condition for valley
            waterTrapped += min(prefixMax[i], suffixMax[i]) - arr[i];
        }
    }
    return waterTrapped;
} // O(3N) time and O(2N) space

// we can actually optimise this by just computing suffixMax and maintaining a leftMax variable instead of an array since we are anyway traversing from left to right

int trapWaterBetter(vector<int> &arr) {
    vector<int> suffixMax(arr.size());
    suffixMax[arr.size() - 1] = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }
    int leftMax = arr[0]; // initially
    int waterTrapped = 0;
    for(int i = 0; i < arr.size(); i++) {
        leftMax = max(leftMax, arr[i]);
        if(arr[i] < leftMax && arr[i] < suffixMax[i]) { // condition for valley
            waterTrapped += min(leftMax, suffixMax[i]) - arr[i];
        }
    }
    return waterTrapped;
} // O(2N) time and O(N) space

// Optimal remaining in O(1) space

int trapWaterOptimal(vector<int> &arr) {
    int lMax = 0, rMax = 0, waterTrapped = 0, l = 0, r = arr.size() - 1;
    // we only have to focus on min(lMax, rMax) so if we sure that we processing smaller first so if arr[l] <= arr[r] then it is guranteed that lMax < rMax => min(lMax, rMax) = lMax
    while(l < r) {
        if(arr[l] <= arr[r]) {
            // we always process the smaller element first
            if(arr[l] < lMax) waterTrapped += lMax - arr[l]; // only in this case water will be trapped
            else lMax = arr[l]; // new left max
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

int main() {
    
    return 0;
}