#include<iostream>
#include<vector>
using namespace std;

// In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

int binarySearch(vector<int> &arr, int key) {

    int low = 0, high  = arr.size() - 1;

    while(low <= high) {

        // to avoid overflow for INT_MAX, we can also use long long but this is better

        int mid = low + (high - low) / 2; 

        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1; // if key is greater we remove the lower half
        else high = mid - 1; // if key is smaller we remove the higher half
    }

    return -1;
}

// explaining the overflow case in Binary Search on Array
// Scenario:

// Assume we are using 32-bit signed integers.

// The maximum possible integer value (INT_MAX) is 2,147,483,647.

// Let's say our search range is in the upper half of a giant array:

// low = 1,500,000,000

// high = 2,000,000,000

// Now, let's try the flawed calculation:

// The Sum: low + high
// 1,500,000,000 + 2,000,000,000 = 3,500,000,000

// The Overflow: The result, 3,500,000,000, is greater than the maximum value for a 32-bit signed integer (2,147,483,647). The sum overflows.

// The Consequence: The overflowed value wraps around and becomes a negative number. For example, it might become -794,967,296.

// The Error: The code then calculates mid = -794,967,296 / 2, which results in a negative mid index. When your program tries to access array[mid], it will use this negative index, causing an ArrayIndexOutOfBoundsException (in Java/C#) or undefined behavior (in C/C++), crashing your program or leading to incorrect results.

/////////////////////////////////////////////////////////////////////////////////////////

int recursiveBinarySearch(vector<int> &arr, int low, int high, int key) {
    if(low > high) return -1; // not found
    int mid = low + (high - low) / 2;
    if(arr[mid] == key) return mid; // index to be returned
    else if(arr[mid] > key) return recursiveBinarySearch(arr,low,mid-1,key);
    else return recursiveBinarySearch(arr,mid+1,high,key);
}

// in both iterative and recursive versions O(logN) time, but for recursion we take extra space of O(logN) because is logN is the maximum number of times we will call the function, creating logN number of function stacks

//////////////////////////////////////////////////////////////////////////////////////

int main() {
    
    return 0;
}