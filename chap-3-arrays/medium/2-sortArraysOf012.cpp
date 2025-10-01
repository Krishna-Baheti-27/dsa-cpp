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

void sortArrOptimal(vector<int> &arr) {
    // dutch national flag says,
    // 0 to low - 1 => 0
    // low to mid - 1 => 1
    // mid to high => is the unsorted part of array (contains, 0,1,2)
    // high + 1 to n - 1 => 2

    // so we use three pointers to sort the array, we can already see the array from 0 to mid - 1 and from high + 1 to n - 1 is already sorted, if we can sort the array from mid to high then we are done

    int low = 0, mid = 0, high = arr.size() - 1; // since initially entire array is unsorted hence lies in range of mid to high
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            mid++;
            low++;  
        } else if(arr[mid] == 1) {
            // already sorted
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
            // here we dont do mid++, since we dont know what was arr[high], if it was 0 or 2 then we again need to sort it and cant ignore it
        }
    }
    // in each case we are either moving mid ahead or high behind so essentially if every element was unosrted then we would move exactly n times
    // O(N) time and O(1) space
}

// Of course. The algorithm you've implemented is the Dutch National Flag algorithm, and its core idea is three-way partitioning. While sorting 0s, 1s, and 2s is the classic textbook example, its applications are much broader.

// The main application is to efficiently partition an array into three distinct sections based on a pivot value: elements less than the pivot, elements equal to the pivot, and elements greater than the pivot.

// Key Applications of the Dutch National Flag Algorithm
// 1. Optimizing Quicksort 🚀
// This is the most significant application. A standard Quicksort algorithm uses a two-way partition (elements less than the pivot and elements greater than the pivot). This works well but has a major weakness: it performs poorly on arrays with many duplicate elements.

// If the chosen pivot is a value that appears many times, the partition can become very unbalanced, degrading Quicksort's performance to its worst case, O(N 
// 2
//  ).

// How the Dutch National Flag Algorithm Helps:
// By using a three-way partition, we can group all elements equal to the pivot into a "middle" section in a single pass. The recursive Quicksort calls are then only made on the "less than" and "greater than" sections, completely ignoring the middle part which is already in its final sorted position.

// Standard Partition: [ < pivot | >= pivot ]

// DNF Partition: [ < pivot | == pivot | > pivot ]

// This optimization is crucial for handling real-world data and is used in many modern sort() library implementations to keep performance consistently close to O(NlogN).

// 2. General-Purpose Array Partitioning
// The algorithm is a highly efficient, single-pass tool for any problem that requires segregating elements into three categories.

// Segregating Positive, Negative, and Zero Numbers: You can partition an array to have all negative numbers first, then all zeros, and finally all positive numbers.

// Partitioning Around a Range: It can be adapted to partition elements into three groups: less than min, between min and max, and greater than max.

// Categorizing Objects: Imagine you have a list of products and you want to sort them in-place based on their status: Available, Backordered, and Discontinued. The DNF algorithm can do this in O(N) time.

// 3. Reordering Linked Lists
// While your example uses an array, the same partitioning logic can be applied to other data structures. You can reorder the nodes of a linked list in a single pass according to a pivot value, manipulating pointers instead of swapping array elements. This allows you to achieve the same three-way partition in-place for a linked list.

int main() {
    
    return 0;
}