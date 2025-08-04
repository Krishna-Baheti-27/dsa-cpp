#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // select the pivot (here as first)
    // now we have to place the pivot at its correct position
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= pivot && i < high) i++; // on the left side we stop when we find a element greater than the pivot
        while(arr[j] > pivot && j > low) j--; // on the right side we stop when we find a element less than or eqaul to pivot
        // it is really our choice, we have decided that we want to put the elements = pivot on the left side
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]); // now our pivot is placed at correct position which is j
    return j; // we return where we placed our pivot
}

void quickSort(int arr[], int low, int high) {
    if(low >= high) return;
    int partitionIdx = partition(arr,low,high);
    quickSort(arr, low, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, high);
}
// O(NlogN) avg case but O(N^N) if we pick the pivot as first or last element in a sorted array

// Now implement quick sort using pivot as last element, middle element and random element

int main() {
    int arr[] = {5,4,1,3,2};
    quickSort(arr,0,4);
    for(int num : arr) cout << num << ' ';
    return 0;
}