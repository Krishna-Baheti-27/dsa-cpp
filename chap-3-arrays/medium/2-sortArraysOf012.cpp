#include<bits/stdc++.h>
using namespace std;

// question sort the array of 0's, 1's and 2's

// Brute simply sort, O(nlogn) time, O(logN) or O(N) space as per your sorting algo

void sortArrBetter(vector<int> &arr) {
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    int i;
    for(i = 0; i < count0; i++) arr[i] = 0;
    for(i = count0; i < count0 + count1; i++) arr[i] = 1;
    for(i = count0 + count1; i < arr.size(); i++) arr[i] = 2;
} // O(2n) time, O(1) space

// dutch national flag says, (all indices are inclusive)
// 0 to low - 1 => 0
// low to mid - 1 => 1
// mid to high => is the unsorted part of array (contains, 0,1,2)
// high + 1 to n - 1 => 2

// note that all the elments in the range [mid, high] are unsorted including mid and high


// so we use three pointers to sort the array, we can already see the array from 0 to mid - 1 and from high + 1 to n - 1 is already sorted, if we can sort the array from mid to high then we are done

void sortArrOptimal(vector<int> &arr) {

    int low = 0, mid = 0, high = arr.size() - 1; 
    // since initially entire array is unsorted hence lies in range of mid to high

    while(mid <= high) {
        if(arr[mid] == 0) { // 0 to low - 1 holds 0's so what would be the next position to insert 0, that would be low and once we do that we move low ahead
            swap(arr[low], arr[mid]); // send zero to low
            mid++; // it is guaranteed we would get a 1 back since low to mid - 1 is 1's
            low++;  // and hence expand the interval 0 to low - 1 to right by low++
        } else if(arr[mid] == 1) {
            mid++; // already sorted
        } else {
            swap(arr[mid], arr[high]); // send 2 to high
            high--; // and hence expand the interval high + 1 to n - 1 to left by high--

            // here we dont do mid++, since we dont know what was arr[high], if it was 0 or 2 then we again need to sort it and cant ignore it
        }
    }

    // in each case we are either moving mid ahead or high behind so essentially if every element was unosrted then we would move exactly n times
    // O(N) time and O(1) space
}

int main() {
    
    return 0;
}