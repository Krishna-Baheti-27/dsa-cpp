#include<bits/stdc++.h>
using namespace std;

// we are given a 2-d matrix having odd number of integers and it is row wise sorted, so we have to find its median, since it has odd integers when we arrange all elements in increasing order we are guranteed to have a middle element and that would be our answer

double medianOfRowWiseSortedBrute(vector<vector<int>> &matrix) {
    vector<int> oneDArr;
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            oneDArr.push_back(matrix[i][j]);
        }
    }
    sort(oneDArr.begin(), oneDArr.end());
    return oneDArr[n * m / 2]; // sinnce there will always be odd number of elements since both m and n are odd and hence only value of median is straight forward
} // O(nm) + O(nm * log(m + n)) time



int main() {
    
    return 0;
}