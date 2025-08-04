#include<iostream>
#include<vector>
using namespace std;

// MUST REVISE EXCELLENT CODE
// THE TIME COMPLEXITY IS NlogN which is in best , worst and avg cases the same
// the derivation of TC is not important 
// Space complexity is O(N) since we are using a temporary array

void merge(int arr[], int low, int mid, int high) {
    vector<int> sortedArray; // temp storeage for array elements
    // it shoudl be fresh for each merge call beacuse each time different portion of the array is going to get sorted so we cannot continue with a global variable maintaining its value
    int i = low, j = mid + 1;
    while(i <= mid && j <= high) {
        if(arr[i] > arr[j]) {
            sortedArray.push_back(arr[j]); // push the smaller one but from right subarray
            j++;
        } else {
            sortedArray.push_back(arr[i]); // push greater than or equal from left subarray
            i++;
        }
    }

    // if loop breaks due to i > mid
    while(j <= high) {
        sortedArray.push_back(arr[j]);
        j++;
    }
    // if loop breaks due to j > high
    while(i <= mid) {
        sortedArray.push_back(arr[i]);
        i++;
    }

     // now just copy the elements from the temporary array to original array but not all the elements, onyl those which have been nerged and those are from [low,high]
    for(int i = low; i <= high; i++) {
        arr[i] = sortedArray[i - low]; // as for the low the index is temp would be zero and it would gradually increase to its max value which is high - low,
        // where as for arr it is from low to high
    }

}

void mergeSort(int arr[], int low, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid); // sort the first hypothetical array
    mergeSort(arr, mid + 1, high); // sort the second hypothetical array
    merge(arr,low,mid,high); // merge the two sorted arrays
    // here is the main part, as we provide it with low, mid and high, using these we can now form our new hypothetical sorted array
    // so in reality the mergeSort() function doe nothing but just gives us with sub arrays which we can merge using the merge function which plays the pivotal role
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    mergeSort(arr,0,n-1);
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}