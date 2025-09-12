#include<bits/stdc++.h>
using namespace std;

int findKthMissingBrute(vector<int> &arr, int k) {
    // it just works, dry run it yourself
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] <= k ) k++;
        else return k;
    }
} // O(n) but the array is sorted and hence we can apply binary search to get logN run time but it wont be a typical binary search as the number is not present in the array

int findKthMissingOptimal(vector<int> &arr, int k) {
    // first figure out the indexes between which we would have the answer
    // for array [2,3,4,7,11] ideally it should have been [1,2,3,4,5] so we can find the numbers missing at each index by subtracting given array from ideal array
    // once we find the missing numbers we would know the range in which k lies, ultimately the range in which answer lies and from there its pretty easy to get the answer
    
    // so we basically apply binary search not on the array but on the  array of missing numbers if that makes sense

    // to find the number of missing numbers till that index use arr[i] - (i + 1)

    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        // we are applying binary search on number of missing numbers
        int mid = (low + high) / 2;
        if(arr[mid] - (mid + 1) >= k) high = mid - 1;
        else low = mid + 1;
    }
    // finally [high, low] is the range in which the number lies
    return low + k; // or hight + 1 + k , how exactly 
    // the number would be arr[high] - more = arr[high] + k - missing
    // arr[high] + k - (arr[high] - (high + 1) // we have used this before
}

int main() {
    
    return 0;
}