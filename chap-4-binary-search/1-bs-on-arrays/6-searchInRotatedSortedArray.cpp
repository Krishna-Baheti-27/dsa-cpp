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

///////////////////////////////////////////////////////////////////////

// For array not containing any duplicates

// First, we identify the sorted half of the array. 
// Once found, we determine if the target is located within this sorted half. 
// If not, we eliminate that half from further consideration. 
// Conversely, if the target does exist in the sorted half, we eliminate the other half.
// This way we are always eliminating the array by half hence logN time

int searchInRotatedSortedArrayOptimal(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return mid;
        // check if left is sorted
        if(arr[mid] >= arr[low]) {
            if(arr[low] <= key && arr[mid] >= key) high = mid - 1; // key exists in sorted half
            else low = mid + 1; // key doesnt exists in sorted half
        } else if(arr[mid] <= arr[high]) {
            // when right half is sorted
           if(arr[high] >= key && arr[mid] <= key) low = mid + 1;
           else high = mid - 1; 
        }
    }
    return -1;
}

////////////////////////////////////////////////////////////////////////////

// for duplicates
// whenever problem for duplicates, and with very minor changes in that code you would be able to do it for duplicates

// here we have to search if given key exists in the array containing duplicates
// the only problem here is that we might have arr[low] == arr[mid] == arr[high] and in that case it is not possible to tell which half is sorted or if both are sorted then key is in whci half ??

// to deal with that, we simply cut the array from both sides by one length low++ and high-- since they do not contain answer and these duplicates are causing trouble so we trim array and continue from the next iteration since new low and high woudl give new mid which we dont want to miss to chec if arr[mid] == key

bool searchInRotatedSortedArrayDuplicates(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return true; // if found we return true

        // this is the only case where it fails, we can do low++ and high-- since we know arr[low] and arr[high] and arr[mid] are equal and these 3 are not equal to key
        if(arr[low] == arr[mid] == arr[high]) {
            // we trim down our search space and continue from next iteration
            low++;
            high--;
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
} 
// in worst case it can go to O(n/2) if there are lot of duplicates on the both left and right half, then we might have to shrink the array nearly half
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