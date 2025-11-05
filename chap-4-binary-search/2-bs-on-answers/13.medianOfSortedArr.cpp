#include<bits/stdc++.h>
using namespace std;

// we are given two sorted arrays and we have to find the median of the combined sorted array, if the number of elements are even the median = avg of two middlemost elements

/////////////////////////////////////////////////////////////////////////////////////

// the brute force involves merging the two sorted arrays into one like in merge sorted and then finding the median of the final combined array  

double medianOfTwoSortedArrBrute(const vector<int> &arr1, const vector<int> &arr2) {

    vector<int> arr3;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {

        if(arr1[i] >= arr2[j]) {
            arr3.push_back(arr2[j++]);
        } else {
            arr3.push_back(arr1[i++]);
        }
    }

    while(i < arr1.size()) {
        arr3.push_back(arr1[i++]);
    }

    while(j < arr2.size()) {
        arr3.push_back(arr2[j++]);
    }

    // now they have been successfully merged
    // lets find the median of newly created array

    if(arr3.size() % 2 == 0) {
        return (arr3[arr3.size() / 2] + arr3[arr3.size() / 2 - 1]) / 2.0;
    } else {
        return (double)arr3[arr3.size() / 2];
    }

    // at the last make sure that it is double since integer divison gives us integer, even though the type is double

} // O(n + m) time and O(n + m) space

//////////////////////////////////////////////////////////////////////////////////////

// so in the better approach we have to do it in constant space, and we can do this by just playing with the pointers, we dont have to store the entire merged array but just the el1 and el2 which will be used to compute our median as (el1 + el2) / 2 for even elements and el2 for odd elements where ind1 = n/2 - 1 and ind2 = n / 2 are the indices of el1 and el2 respectively and n = n1 + n2 where n1 and n2 are number of elements in arr1 and arr2

double medianOfTwoSortedArraysBetter(const vector<int> &arr1, const vector<int> &arr2) {

    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = n / 2 - 1;
    int i = 0, j = 0;
    int count = 0; // to store our hypothetical index of merged array
    int el1 = INT_MIN, el2 = INT_MIN; // intially both not found

    while(i < n1 && j < n2) {

        if(el1 != INT_MIN && el2 != INT_MIN) break;

        if(arr1[i] > arr2[j]) {
            if(count == ind1) {
                el1 = arr2[j];
            } else if(count == ind2) {
                el2 = arr2[j];
            }
            count++;
            j++;
        } else {
            if(count == ind1) {
                el1 = arr1[i];
            } else if(count == ind2) {
                el2 = arr1[i];
            }
            count++;
            i++;
        }
    }

    if(el1 != INT_MIN && el2 != INT_MIN) {
        if(n % 2 == 0) return (el1 + el2) / 2.0;
        return (double)el2;
    }

    while(i < n1) {
        if(count == ind1) {
            el1 = arr1[i];
        } else if(count == ind2) {
            el2 = arr1[i];
        }
        count++;
        i++;
    }

    while(j < n2) {
        if(count == ind1) {
            el1 = arr2[j];
        } else if(count == ind2) {
            el2 = arr2[j];
        }
        count++;
        j++;   
    }

    if(n % 2 == 0) return (el1 + el2) / 2.0;
    return (double)el2;

}  // O(n1 + n2) time and O(1) space

////////////////////////////////////////////////////////////////////////////////////

// this is the most optimal solution usig binary search since we have two sorted arrays

int main() {
    
    return 0;
}