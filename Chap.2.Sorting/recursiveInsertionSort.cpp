#include<iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int j, int n) {
    if(j == n - 1) return;
    for(int i = 1 + j; i > 0 && arr[i - 1] > arr[i]; i--) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
    }
    recursiveInsertionSort(arr,j+1,n);
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    cout << "Before Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    recursiveInsertionSort(arr,0,n);

    cout << "After Sorting: ";
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}