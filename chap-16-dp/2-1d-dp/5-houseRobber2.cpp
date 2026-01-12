#include<bits/stdc++.h>
using namespace std;

// same question as in house robber part 1 or in max sum subsequence consisting of non adjacent elements but here we have the array as circular which means the last house is neighbour of the first one

///////////////////////////////////////////////////////////////////////////////////////

// so if you pay close attention here then the only thing which is different here is that the first and last house are also adjacent apart from the previous constraints so this means we cant break into first and last house both and hence we first find max sum subsequence of non adjacent without considering the last element and then without considering the first element then return the max amongst these two as these are the only two possible cases and we cant have both first and last and if we skip both first and last then we wont get max as all elements are positive and skipping both positive elements wouldnt make a optimal solution

int maxSumOptimal(vector<int> &arr) {

    int n = arr.size();

    if(n == 1) {
        return arr[0];
    }

    int pickSum = arr[0], notPickSum = max(arr[0], arr[1]);

    for(int i = 2; i < n; i++) {

        int curr = max(arr[i] + pickSum, 0 + notPickSum);
        pickSum = notPickSum;
        notPickSum = curr;
    }

    return notPickSum;

}  // O(N) time and O(N) space

int maxSum(vector<int> &arr) {

    if(arr.size() == 1) {
        return arr[0];
    }

    vector<int> temp1, temp2;
    
    for(int i = 0; i < arr.size(); i++) {
        if(i != 0) {
            temp1.push_back(arr[i]);
        } 
        if(i != arr.size() - 1) {
            temp2.push_back(arr[i]);
        }
    }

    return max(maxSumOptimal(temp1), maxSumOptimal(temp2));

} // O(3N) time and O(2N) space

// and we can also optimise it a little bit more like using 0 extra space by changing our maxSumOptimal function to operate on a range of array passed and etc but still this solution remains the most optimal if we talk about worst case analysis in which we ignore constants

int main() {
    
    return 0;
}