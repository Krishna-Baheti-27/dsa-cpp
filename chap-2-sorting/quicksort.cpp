#include<bits/stdc++.h>
using namespace std;

// for partition remember simple logic, place elements lesser or equal on left and greater on right, start i = low and j = high and run or swap only if (i < j), once the loop is over j points to the correct index for pivot

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // select the pivot (here as first)
    // now we have to place the pivot at its correct position
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= pivot && i < high) i++; 
        // on the left side we stop when we find a element greater than the pivot
        while(arr[j] > pivot && j > low) j--; 
        // on the right side we stop when we find a element less than or eqaul to pivot
        if(i < j) swap(arr[i], arr[j]); // then only swap
    }
    // now i and j have crossed and hence j now points to a position appropriate for pivot
    swap(arr[j], arr[low]);
    return j; // we return the index where we placed our pivot
}

void quickSort(int arr[], int low, int high) {
    if(low >= high) return;
    int partitionIdx = partition(arr,low,high);
    quickSort(arr, low, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, high);
}
// O(NlogN) avg case but O(N^2) if we pick the pivot as first or last element in a sorted array

// Now implement quick sort using pivot as last element, middle element and random element

void quickSortLast(int arr[], int low, int high) {
    if(low >= high) return;
    swap(arr[low], arr[high]);
    int partitionIdx = partition(arr, low, high);
    quickSortLast(arr, low, partitionIdx - 1);
    quickSortLast(arr, partitionIdx + 1, high);
}

void quickSortMiddle(int arr[], int low, int high) {
    if(low >= high) return;
    int midIdx = low + (high - low) / 2;
    swap(arr[low], arr[midIdx]);
    int partitionIdx = partition(arr, low, high);
    quickSortMiddle(arr, low, partitionIdx - 1);
    quickSortMiddle(arr, partitionIdx + 1, high);
}

void quickSortRandom(int arr[], int low, int high) {
    if(low >= high) return;
    int randomIdx = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIdx]);
    int partitionIdx = partition(arr, low, high);
    quickSortRandom(arr, low, partitionIdx - 1);
    quickSortRandom(arr, partitionIdx + 1, high);
}

// here we are placing lesser or equal elements on left of pivot and greater on right, i = low
// if you want such that we have lesser on left and equal or greater on right, we can simply switch the equality but remember i should start from low + 1 for that case

// also some other things change there so i recomment to develop this logic of putting lesser or equal on left and greater on right opposed to its inverse

int partition_alternative(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        // Move the 'i' pointer to find an element that is >= pivot
        while (i <= j && arr[i] < pivot) {
            i++;
        }

        // Move the 'j' pointer to find an element that is < pivot
        while (i <= j && arr[j] >= pivot) {
            j--;
        }

        // If the pointers have crossed, the partitioning process is done
        if (i > j) {
            break;
        }

        // Swap the elements at i and j
        std::swap(arr[i], arr[j]);
    }

    // Finally, place the pivot value in its correct position by swapping it with arr[j]
    std::swap(arr[low], arr[j]);
    
    return j; // Return the pivot's final index
}

int main() {
    int arr[] = {5,4,1,3,2};
    quickSortRandom(arr,0,4);
    for(int num : arr) cout << num << ' ';
    return 0;
}