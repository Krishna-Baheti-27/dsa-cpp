#include<bits/stdc++.h>
using namespace std;

void moveZeroesBrute(vector<int> &arr) {
    vector<int> temp;
    // storing all non zero numbers
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != 0) temp.push_back(arr[i]);
    }
    // copying them back to main array, and all the remining elements are zero
    for(int i = 0; i < arr.size(); i++) {
        if(i < temp.size()) arr[i] = temp[i];
        else arr[i] = 0;
    }
}

void moveZeroesOptimised(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) nums[j++] = nums[i]; // store all the non zero
    }
    for(int k = j; k < nums.size(); k++) {
        nums[k] = 0; // store all the zeroes later
    }  
        // O(n + d) where d is number of zeroes
}

// THIS IS THE BEST SOLUTION IF YOU ALSO FOCUS ON READABILITY
void moveZeroesMostOptimised(vector<int> &arr) {
    int j = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) {
            j = i; // here we find the first zero
            break; // runs O(x) times since we break out where x is the length  from 0th index to first zero
        }
    }
    // here we are finding the first zero which is not needed, as we can simply use the approach discussed below
    // If no zero found, no need to process
    if(j == -1) return;
    for(int i = j + 1; i < arr.size(); i++) {
        if(arr[i] != 0) {
            // we swap arr[i] with arr[j] essentially swapping so that non zero elements come before and if it is a zero we dont swap, as arr[j] is zero and arr[i] is not zero
            swap(arr[i], arr[j]);
            j++; // we move j ahead because since the zero has been swapped, j should point to index of last encountered zero
        }
    }
} // O(N) time

void moveZeroesSwapSinglePassMostOptimal(vector<int>& nums) {
    int lastPosToPlace = 0; // keeps track of what is the last position to place a non zero element
    // or basically keeps track of the first zero found and maintains it
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[lastPosToPlace]);
            lastPosToPlace++; // after swap index of first zero has increased by 1 since that position is now occupied by a non zero number and hence move the pointer
        }
    }
} // O(N) time, more better way to write


int main() {
    vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
    for(int num : arr) cout << num << ' ';
    cout << '\n';
    moveZeroesSwapSinglePassMostOptimal(arr);
    for(int num : arr) cout << num << ' ';
    cout << '\n';
    return 0;
}