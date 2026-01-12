#include<bits/stdc++.h>
using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

/////////////////////////////////////////////////////////////////////////////////////

// so we have to merge all the overlapping intervals, the interval would be overlapping if the array is sorted and the endi of 1 >= starti of 2

// now what will be the final value of interval depends on other points
// start = min(start1, start2) and end = max(end1, end2)

bool xGreaterY(const vector<int> &v1, const vector<int> &v2) {
    return v1[0] >= v2[0];
}

void process(vector<vector<int>> &arr) {

    if(arr.size() == 1) {
        return;
    }

    if(arr[])
}

vector<vector<int>> mergeIntervalsBrute(vector<vector<int>> &arr) {

    vector<vector<int>> ans;
    
    sort(arr.begin(), arr.end(), xGreaterY);

    for(int i = 0; i < arr.size(); i++) {

    }
    
}

int main() {
    
    return 0;
}