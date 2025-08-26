#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // swap minimum with the starting index
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    // this way in each iteration we are shifting smaller elements on the left and larger elements on the right
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    selectionSort(arr,n);
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}