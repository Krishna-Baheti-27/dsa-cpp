#include<bits/stdc++.h>
using namespace std;

bool searchInSortedMatrixBrute(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
} // O(mn) time

bool searchInSortedMatrixBetter(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        if(matrix[i][0] <= target && matrix[i][m - 1] >= target) { // only true for one row
            // then only we find the target inside the ith row using binary search
            int low = 0, high = m - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
    }
    return false;
} // O(nlogm) time

bool searchInSortedMatrixOptimal(vector<vector<int>> &matrix, int target) {
    // hypothetically flattening out the matrix so we have one big vector of size m + n which is sorted and we can simply search on it using binary search to get O(log(m + n)) time
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = m * n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        // to convert a 1-d point to a 2-d point get the row, col we use the formula
        // row = index / m and col = index % m
        // for row we have index / m because the hypothetical 1-d index of the first column would be always multiple of m, and hence divide it by m to get the row number and similarly now we have to find the distance of point from the point in first column and hence index % m
        if(matrix[mid/m][mid % m] == target) return true;
        else if(matrix[mid/m][mid % m] > target) high = mid - 1;
        else low = mid + 1; 
    }
    return false;
} // O(log(mn))

int main() {
    
    return 0;
}