#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        // you can also use a while loop if you feel like not writing the condition in for loop
        for(int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            // basically you should check till the left side is in correct order so swap stuff till arr[j-1] > arr[j] but you need to make sure that j > 0 since negative indices are not allowed and there is no point in checking for index 0
      
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
          
        }
    }
}

// it takes O(N^2) but just like bubble sort the best case is O(N)

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    insertionSort(arr,n);
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}
