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
} // O(nlogm) time because it may happen that target can occur in multiple rows and hence we would have to check all those rows, unlike in previous example where it was guranteed that target can occur only in one row and if not there then nowhere

// the approach of last question on standing on top-right and getting till bottom left works and here is the most optimal solution, it works because when we stand at top -right we are still guranteed that going on left would decrease the value and going down would increase it since the matrix is row and column wise sorted

// here we are taking advantage of the fact that each row is sorted and first element of new row is greater than the last element of previous row
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

// this isnt really binary search, but the concept of elimination in each iteration is still there

int main() {
    
    return 0;
}