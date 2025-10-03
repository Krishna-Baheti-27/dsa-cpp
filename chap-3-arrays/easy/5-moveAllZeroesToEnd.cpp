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

void moveZeroesBetter(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) nums[j++] = nums[i]; // store all the non zero
    }
    for(int k = j; k < nums.size(); k++) {
        nums[k] = 0; // store all the zeroes later
    }  
    // O(n + d) where d is number of zeroes
}

// now is the above better code we had to again go and place the zeroes in end because thats what the question demans unlike remove duplicated which said we dont care about duplicate elements
// now if we have to move all the zeroes in end, whenever we encounter a non zero element we must swap it with the first occuring zero, which will send the zero at the start to back in elements position and the element which is non zero in front which is exactly what we want

// so we have to find the position of the first zero, and then for any other non zero element swap it with position of first zero and increment that position since that is now occupied by non zero element so that wont be the position of zero anymore

// THIS IS THE BEST SOLUTION IF YOU ALSO FOCUS ON READABILITY
void moveZeroesOptimal1(vector<int> &arr) {
    int j = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) {
            j = i; // here we find the first zero
            break; 
        }
    }

    if(j == -1) return; // if no zero found then return early as no need to process

    for(int i = j + 1; i < arr.size(); i++) {
        if(arr[i] != 0) {
            // for non zero element we swap it with first zero found 
            swap(arr[i], arr[j]);
            j++; // since the next location now has zero value, and we can prove this
        }
    }
} // O(N) time and O(1) space

// How to prove that after j++, j woudl always point to the zero and everything on left (< j) is non zero 
// so we know that if there is streak of zeroes then j++ woudl certainly make it point to 0
// if i is the immediate non zero element after j , which means i == j + 1, so when we swap them now arr[i] = 0, so when j++ , j now point to 0, HENCE PROVED

void moveZeroesOptimal2(vector<int>& nums) {
    int lastPosToPlace = 0; 
    // keeps track of what is the last position to place a non zero element
    // or basically keeps track of the first zero found and maintains it
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[lastPosToPlace]);
            lastPosToPlace++; // after swap index of first zero has increased by 1 since that position is now occupied by a non zero number and hence move the pointer
        }
    }
} // O(N) time, more better way to write

// so both solution take O(N) time but second one performs unnecessary swaps, in worst case N swap if array does not contain zero whereas the first one would simply check for no zeroes and wont waste time in performing unnecessary swaps


int main() {
    vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
    for(int num : arr) cout << num << ' ';
    cout << '\n';
    moveZeroesOptimal1(arr);
    for(int num : arr) cout << num << ' ';
    cout << '\n';
    return 0;
}