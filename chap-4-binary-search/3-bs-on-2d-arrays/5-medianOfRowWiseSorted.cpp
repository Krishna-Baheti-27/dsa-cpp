#include<bits/stdc++.h>
using namespace std;

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