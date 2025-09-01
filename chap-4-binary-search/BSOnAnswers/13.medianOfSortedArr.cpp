#include<bits/stdc++.h>
using namespace std;

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
}

int main() {
    
    return 0;
}