#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int searchInRotatedSortedArrayBrute(vector<int> &arr, int key) {
    // simple linear search, // no duplicates
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) return i;
    }
    return -1;
} // O(N) time


// First, we identify the sorted half of the array. 
// Once found, we determine if the target is located within this sorted half. 
// If not, we eliminate that half from further consideration. 
// Conversely, if the target does exist in the sorted half, we eliminate the other half.
int searchInRotatedSortedArrayOptimal(vector<int> &arr, int key) {
    // no duplicates
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return mid;
        // identify the sorted half and check if the element is there, if it is there we aplly binary search else we trim the sorted half, this way we trim the array each time by half because atleast one portion ought to be sorted since a sorted array has been rotated
        if(arr[mid] >= arr[low]) {
            // when left is sorted and we can apply binary search there but first we check if key exists in the range of low to mid
            if(arr[low] <= key && arr[mid] >= key) high = mid - 1; // if key exists in range low to mid we trime our search area from right
            else low = mid + 1; // else we trime search area from left
        } else if(arr[mid] <= arr[high]) {
            // when right half is sorted
           if(arr[high] >= key && arr[mid] <= key) low = mid + 1;
           else high = mid - 1; 
        }
        // How this works is pretty easy, we either trim the sorted half since element is not present in there or we apply binary search in the sorted half since the element is present there (thereby trimming the unsorted half) and hence in each iteration we are reducing the array size by half hecne time is O(logN)
    }
    return -1;
}

bool searchInRotatedSortedArrayDuplicates(vector<int> &arr, int key) {
    // for duplicates
    // whenever problem for duplicates, and with very minor changes in that code you would be able to do it for duplicates
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return true;
        // this is the only case where it fails
        if(arr[low] == arr[mid] == arr[high]) {
            // when all three are equal we cannot tell using simple if-else that which half is sorted
            // to overcome this since we have already checked thar arr[mid] != target, which implies neither will be arr[low] or arr[high]
            low++;
            high--;
            // we trim down our search space and continue from next iteration
            continue; // it maybe possible that, due to low++ and high--, we might have arr[newmid] == key so in order to not miss that , we continue from the next iteration and skip this one
        }
        // we continue since if atleast one of them is not equal, then we can solve them easily
        if(arr[mid] >= arr[low]) {
            // when left is sorted
            if(arr[low] <= key && arr[mid] >= key) high = mid - 1;
            else low = mid + 1;
        } else if(arr[mid] <= arr[high]) {
            // when right half is sorted
           if(arr[high] >= key && arr[mid] <= key) low = mid + 1;
           else high = mid - 1; 
        }
    }
    return false;
} // in worst case it can go to O(n/2) if there are lot of duplicates on the both left and right half, then we might have to shrink the array nearly half
// When the array contains many duplicate elements, the condition arr[low] == arr[mid] == arr[high] triggers frequently. In these cases:

// The algorithm increments low and decrements high by 1 in each iteration.

// This reduces the search space by only 2 elements per iteration instead of halving it, due to continue.
// hence array does not get halved in each iteration and in worst case we might have to traverse half the array since low++ and high-- will meet after exactly n / 2 traversals hence worst is O(n/2)
// In the worst case (e.g., all elements are identical and the target is absent), this leads to a linear scan of the array.

int main() {
    vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    cout << searchInRotatedSortedArrayBrute(arr,3) << endl;
    cout << searchInRotatedSortedArrayOptimal(arr,3) << endl;
    cout << searchInRotatedSortedArrayDuplicates(arr,2) << endl;
    return 0;
}