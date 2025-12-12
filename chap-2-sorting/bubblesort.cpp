#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        // we can optimise this by exiting early if we realise there are no swappings
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break; // exit if no swapping done, since array is already sorted
        // THIS WAY BUBBLE SORT IS MORE ADVANTAGEOUS THAN SELECTION SORT BECAUSE WE CAN BREAK OUT OF THE LOOP IF ARRAY IS ALREADY SORTED AND BEST CASE COMPLEXITY IS O(N) but in Selection Sort TC is always O(N^2) and will do all the procedure even if the array is aorted beforehand
    }
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    bubbleSort(arr,n);
    for(int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}