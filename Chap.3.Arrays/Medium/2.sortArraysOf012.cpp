#include<bits/stdc++.h>
using namespace std;

// use mergesort or quick sort for brute

void sortBetter012(vector<int> &arr) { // O(2N) time solution
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    cout << count0 << ' ' << count1 << ' ' << count2 << endl;
    int i = 0;
    for(int j = 0; j < count0; j++) arr[i++] = 0;
    for(int j = 0; j < count1; j++) arr[i++] = 1;
    for(int j = 0; j < count2; j++) arr[i++] = 2;
}

void sort012Optimal(vector<int> &arr) {
    // Using dutch national flag algo cna be extended to k-way partition, can be used to optimise quick sort
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) mid++;
        else if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    // main advantage that we do this in one pass
}

int main() {
    vector<int> arr = {2,2,2,2,0,2,1,0,1,1,0};
    sort012Optimal(arr);
    for(int num : arr) cout << num << ' ';
    cout << endl; 
    return 0;
}