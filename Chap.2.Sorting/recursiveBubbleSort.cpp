// recursive bubble sort algo

#include<iostream>
using namespace std;

void recursiveBubbleSort(int arr[], int n) {
    if(n == 1) return;
    int swapped = 0;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i + 1] < arr[i]) {
            int temp = arr[i + 1];
            arr[i+1] = arr[i];
            arr[i] = temp;
            swapped = 1;
        }
    }
    if(swapped == 0) return;
    // now max element is at the last, now again call bubble sort to sort the remaining n - 1 elements
    recursiveBubbleSort(arr,n-1);
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    cout << "Before Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    recursiveBubbleSort(arr, n);

    cout << "After Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}