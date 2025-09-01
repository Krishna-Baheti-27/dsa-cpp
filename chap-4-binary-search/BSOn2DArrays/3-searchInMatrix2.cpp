#include<bits/stdc++.h>
using namespace std;

vector<int> searchInMatrixBrute(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == target) return {i,j};
        }
    }
    return {-1, -1};
} // O(mn) time

vector<int> searchInMatrixBetter(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        if(matrix[i][0] <= target && matrix[i][m - 1] >= target) {
            // do the binary search
            int low = 0, high = m - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target) return {i,mid};
                else if(matrix[i][mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
    }
    return {-1,-1};
} // O(n) + O(logm) time

vector<int> searchInMatrixOptimal(vector<vector<int>> &matrix, int target) {
    // we start from the last element of first row and start eliminating, this works because the first row combined with last column and similarly every other pair is definitely sorted
    // you can also start from last row first column
    int row = 0, col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0) {
        if(matrix[row][col] == target) return {row, col};
        else if(matrix[row][col] > target) col--; // eliminate that column
        else row++; // eliminate that row
    }
    return {-1,-1};
} // O(m + n) in worst case as we have to move from one corner to another and we dont move across horizontal, we either move down the row or along the column

// this isnt really binary search, but the concept of elimination in each iteration is still there

int main() {
    
    return 0;
}