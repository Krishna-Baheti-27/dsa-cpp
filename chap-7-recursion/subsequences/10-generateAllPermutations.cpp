#include<bits/stdc++.h>
using namespace std;

// given an integer array we have to generate all permutations of the array
// it has distinct elements so total number of permutations = n!

///////////////////////////////////////////////////////////////////////////////

// ok so iterate the nums array and for those elements which are not visited which means we dont have them in our visited array we add them to our temporary and visited array and again call the function to generate permutations until we get all the elements visited and when returning we pop_back the inserted element and make it false in our visited array so we can explore other permutations

void helperBrute(vector<int> &nums, vector<int> &arr, vector<bool> &visited, vector<vector<int>> &ds) {

    if(arr.size() == nums.size()) {
        ds.push_back(arr);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {

        if(!visited[i]) {
            visited[i] = true;
            arr.push_back(nums[i]);
            helperBrute(nums, arr, visited, ds);
            arr.pop_back();
            visited[i] = false;
        } 

    }
}

vector<vector<int>> generateAllPermutationsBrute(vector<int> &nums) {

    vector<int> arr; // temporary array
    vector<bool> visited(nums.size(), false); // to check for visited or not
    vector<vector<int>> ds; // to store the answer

    helperBrute(nums, arr, visited, ds);

    return ds;

} // O(n! * n) time and O(2n) space for visited and temporary array and O(n) recursion stack space

// since total n! permutations would be generated each having length n so O(n) time to store them in ds and we are ignoring space to store the permutations

///////////////////////////////////////////////////////////////////////////////////////

// in the more optimal solution, we dont use the extra space required by the visited array or the temporary array arr, but instead we do it by swapping in-place and modifying the original array

// we start from first index then we swap first element with itself and move ahead then we swap second element with the first and so on
// so at any given index we swap from that index till end of array to generate all possible permutations from that index and when index >= n we simply store the current state of nums in ds and very important is when we are returning from the function we have to again swap so that the original nums is restored for future function calls

void helperOptimal(int index, vector<int> &nums, vector<vector<int>> &ds) {

    if(index >= nums.size()) {
        ds.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        helperOptimal(index + 1, nums, ds); // call for index + 1 since thats what we want to fill
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> generateAllPermutationsOptimal(vector<int> &nums) {

    vector<vector<int>> ds;

    helperOptimal(0, nums, ds);

    return ds;

} // O(n! * n) time and O(n) recursion stack space ignoring space to return the answer

int main() {
    
    return 0;
}