#include<bits/stdc++.h>
using namespace std;

// we are given a 2-d matrix having odd number of integers and it is row wise sorted, so we have to find its median, since it has odd integers when we arrange all elements in increasing order we are guranteed to have a middle element (arr[n / 2]) and that would be our answer

//////////////////////////////////////////////////////////////////////////////////////////

// in the brute force we simply go through each and every element in matrix and then put it into the 2d-arr and sort it in the end and just extract the middle value thats our answer

int medianOfRowWiseSortedBrute(vector<vector<int>> &matrix) {

    vector<int> oneDArr;
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            oneDArr.push_back(matrix[i][j]);
        }
    }

    sort(oneDArr.begin(), oneDArr.end());

    return oneDArr[n * m / 2]; // since we have odd number of elements hence arr[n / 2] is median

} // O(nm) + O(nm * log(m + n)) time and O(n * m) space 

///////////////////////////////////////////////////////////////////////////////////////

// the more optimal approach uses the fact that for an element to be median, the number of elements <= it must be greater than > (n * m) / 2
// so the first occuring element (when elements are arranged in sorted order) which has ( number of element <= to it ) > (n * m) / 2 will be the median

int smallerOrEqualElements(vector<vector<int>> &matrix, int mid) {

    int count = 0;

    for(int i = 0; i < matrix.size(); i++) {
        count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }

    return count;

} // O(n * logm) time

int medianOfRowWiseSortedOptimal(vector<vector<int>> &matrix) {

    int n = matrix.size(), m = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;

    for(int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m ) / 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int smallerOrEqual = smallerOrEqualElements(matrix, mid);

        if(smallerOrEqual <= req) {
            low = mid + 1; // not reached so increase
        } else {
            high = mid - 1;
        }
    }

    return low; // this is the median

} // O(log(max element - min element) * n * logm) time 

int main() {
    
    return 0;
}