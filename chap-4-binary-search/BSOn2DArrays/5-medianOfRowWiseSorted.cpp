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
    if(n * m % 2 == 0) return oneDArr[n * m / 2];
    else return (oneDArr[n * m / 2] + oneDArr[(n * m / 2) - 1]) / 2;
} // O(nm) + O(nm * log(m + n)) time

int main() {
    
    return 0;
}