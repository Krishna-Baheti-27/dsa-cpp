#include<iostream>
#include<vector>
using namespace std;

int floorInSortedArrayBrute(vector<int> &arr, int key) {
    // largest number <= key in array
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i] <= key) return arr[i];
    }
    return -1;
}

int floorInSortedArrayOptimised(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1, ans = -1; // positive only
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] <= key) {
            ans = arr[mid]; // posible answer but we can de better
            low = mid + 1; // hence look for better, and since we want largest, we trim the left search space since it consists of smaller numbers
        } else {
            high = mid - 1; // try to reach the answer
        }
    }
    return ans;
}

int ceilInSortedArrayBrute(vector<int> &arr, int key) {
    // smallest number >= key in array
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= key) return arr[i];
    }
    return -1;
}

int ceilInSortedArrayOptimised(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= key) {
            ans = arr[mid];
            high = mid - 1; // look on right for smallest
        } else {
            low = mid + 1; // try to reach atleast till the eqality of number
        }
    }
    return ans;
}

int main() {
    
    return 0;
}