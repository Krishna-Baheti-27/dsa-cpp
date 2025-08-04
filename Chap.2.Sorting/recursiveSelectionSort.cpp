#include<iostream>
using namespace std;

void recursiveSelectionSort(int arr[], int j, int n) {
    if(j == n - 1) return;
    int minIdx = j;
    for(int i = j + 1; i < n; i++) {
        if(arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    int temp = arr[minIdx];
    arr[minIdx] = arr[j];
    arr[j] = temp;
    recursiveSelectionSort(arr, j + 1, n);
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    cout << "Before Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    recursiveSelectionSort(arr, 0, n);

    cout << "After Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}