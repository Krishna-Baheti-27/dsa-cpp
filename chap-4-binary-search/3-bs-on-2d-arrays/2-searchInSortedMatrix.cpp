#include<bits/stdc++.h>
using namespace std;

// give a sorted matrix both row-wise and col-wise we have to return whether the target is present in it or not, matrix is sorted in such a way that the last element of previous row is smaller than the first element of next row

// in simple words, if you elongate a matrix into a 1-d vector then that vector would be sorted

//////////////////////////////////////////////////////////////////////////////////

// the brute force involves going through the matrix and element by element and checking if its target or not

bool searchInSortedMatrixBrute(vector<vector<int>> &matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == target) return true;
        }
    }

    return false;

} // O(m * n) time

///////////////////////////////////////////////////////////////////////////////////

// here we are taking advantage of the fact that each row is sorted in both col-wise and row-wise fashion and going left on the row decreases value and going down on the column increases the value
// we start from top right, if el == target we return true, if el < target we move down the row to increase value of el and if el > target we move left the row for decreasing target till we reach it or reach the other corner instead which would mean element does not exist

bool searchInSortedMatrixBruteBetter(vector<vector<int>> &matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();

    int movLeft = m - 1, movBotm = 0;

    while(movLeft >= 0 && movBotm < n) {

        if(matrix[movBotm][movLeft] == target) return true;
        else if(matrix[movBotm][movLeft] < target) movBotm++;
        else movLeft--;
    }

    return false;

} // O(m + n) time approach

// this approach is very crucial and would help in cae where we only have row-wise  and col-wise sorted matrix but the last element of previous row is not smaller than the first element of next row

/////////////////////////////////////////////////////////////////////////////////////////

// we search for the row having target element and perform binary search on only that row

bool searchInSortedMatrixBetter(vector<vector<int>> &matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++) {

        // we find the row that has possibility of having target element, (only true for one row)
        // because of the properties that the matrix has
        // then only we find the target inside the ith row using binary search

        if(matrix[i][0] <= target && matrix[i][m - 1] >= target) { 

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

} // O(n) + O(logm) time, since binary search happens for only one row where target can be possibly present

////////////////////////////////////////////////////////////////////////////////////

// the optimal solution involves hypothetically flatenning the matrix with the help for indices to apply bianry search on sorted array
// hypothetically flattening out the matrix so we have one big vector of size m + n which is sorted and we can simply search on it using binary search to get O(log(m + n)) time

// to convert a 1-d point to a 2-d point get the row, col we use the formula
// row = index / m and col = index % m
// for row we have index / m because the hypothetical 1-d index of the first column would be always multiple of m, and hence divide it by m to get the row number and similarly now we have to find the distance of point from the point in first column and hence index % m

bool searchInSortedMatrixMoreOptimal1(vector<vector<int>> &matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = m * n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(matrix[mid / m][mid % m] == target) return true;
        else if(matrix[mid / m][mid % m] > target) high = mid - 1;
        else low = mid + 1; 
    }
    return false;
} // O(log(mn))

// first using binary search on rows, of matrix we find out which row has chances of containing target, then we apply binary search on that row for finding if target is present or not

bool searchInSortedMatrixOptimal2(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
            // target belongs to this row and hence we apply binary search on midth row
            int l = 0, h = m - 1;
            while(l <= h) {
                int m = (l + h) / 2;
                if(matrix[mid][m] == target) return true;
                else if(matrix[mid][m] > target) h = m - 1;
                else l = m + 1;
            }
            // if we cant find target here we return false that it doesnt exist
            return false;
        } else if(matrix[mid][m - 1] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
} // O(logn + logm) time since both binary searches are performed only once
// but we know logm + logn == log(mn) so both approaches optimal

int main() {
    
    return 0;
}