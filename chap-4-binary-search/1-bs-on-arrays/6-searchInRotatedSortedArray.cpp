#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// we are given a rotated sorted array and we have to search for the given key (array may be left or right rotated, it doesnt matter), there are no duplicates in the array

//////////////////////////////////////////////////////////////////////////////

// simple linear search

int searchInRotatedSortedArrayBrute(vector<int> &arr, int key) {
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) return i;
    }

    return -1;
} // O(N) time

///////////////////////////////////////////////////////////////////////

// here we use the property of a rotated sorted array, that is at any instant, if you pick any element, atleast one half will be sorted, (either left or right)

// So, first, we identify the sorted half of the array. 
// Once found, we determine if the target is located within this sorted half. 
// If not, we eliminate the sorted half from further consideration. 
// Conversely, if the target does exist in the sorted half, we eliminate the unsorted half.
// This way we are always eliminating the array by half hence logN time

int searchInRotatedSortedArrayOptimal(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == key) return mid; // check if we found then return 

        if(arr[mid] >= arr[low]) { 

            // left half is sorted that is [low...mid]

            if(arr[low] <= key && arr[mid] >= key) {
                high = mid - 1; // key exists in sorted half
            } else {
                low = mid + 1; // key doesnt exist in sorted half
            }

        } else if(arr[mid] <= arr[high]) {

            // right half is sorted that is [mid...high]

            if(arr[mid] <= key && arr[high] >= key) {
                low = mid + 1; // key exists in sorted half
            } else {
                high = mid - 1;  // key doesnt exist in sorted half
            }
        }
    }

    return -1; // key not found

} // O(logN) time

////////////////////////////////////////////////////////////////////////////

// whenever problem for duplicates, first write the solution for distinct elements and then think where does it break for duplicates and then change to make it work

// for array containing duplicates
// here we only have to return true or false whether the element is present in array or not

// the only problem here is that we might have arr[low] == arr[mid] == arr[high], since duplicates are allowed and in that case it is not possible to tell which half is sorted since both the conditions : 
// arr[low] <= key && arr[mid] >= key
// arr[mid] <= key && arr[high] >= key

// would be true so are both half sorted if yes then key is in which half ??

// to deal with that, we simply cut the array from both sides by one length low++ and high-- since they do not contain answer and these duplicates are causing trouble so we trim array and continue from the next iteration since new low and high woudl give new mid which we dont want to miss to chec if arr[mid] == key before trimming the array

bool searchInRotatedSortedArrayDuplicates(vector<int> &arr, int key) {

    int low = 0, high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == key) return true; // if found we return true

        // this is the only case where it fails, we can do low++ and high-- since we know arr[low] and arr[high] and arr[mid] are equal and these 3 are not equal to key

        // we have to continue or skip this iteration after low++ and high-- since we know that new value of low and high means new value of mid, so we again have to check arr[mid] == key as we dont want to miss any occurence therefore continue from next iteration

        if(arr[low] == arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // we continue since if atleast one of them is not equal, then we can solve them easily because then both the condtions in if and else if would not be true

        if(arr[mid] >= arr[low]) {
            
            if(arr[low] <= key && arr[mid] >= key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        } else if(arr[mid] <= arr[high]) {
            
            if(arr[high] >= key && arr[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
    }

    return false;

} // O(n/2) time in worst case and O(logn) in avg case

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