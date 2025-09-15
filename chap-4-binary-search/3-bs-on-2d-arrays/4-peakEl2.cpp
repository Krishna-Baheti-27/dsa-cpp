#include<bits/stdc++.h>
using namespace std;

// brute involves scanning through entire matrix and making 4 checks at top right bottom left so O(4mn)
// but we can optimise this by simpply returning the largest element in matrix so O(mn)

// now the most optimal solution here still uses the intuition from peakEl1
// we do binary search across columns or rows, by finding max in cols/rows and then checking it with left and right so that we know which portion to eliminate

int rowNo(vector<vector<int>> &matrix,int mid) {
    int maxel = INT_MIN, maxrow = 0;
    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][mid] > maxel) {
            maxel = matrix[i][mid];
            maxrow = i;
        }
    }
    return maxrow;
}

vector<int> peakEl2Optimal(vector<vector<int>> &matrix) {
    int low = 0, high = matrix[0].size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int maxelRow = rowNo(matrix, mid);
        int left = mid - 1 >= 0 ? matrix[maxelRow][mid - 1] : -1;
        int right = mid + 1 < matrix[0].size() ? matrix[maxelRow][mid + 1] : -1;
        if(matrix[maxelRow][mid] > left && matrix[maxelRow][mid] > right) return {maxelRow, mid};
        else if(matrix[maxelRow][mid] < left) high = mid - 1;
        else if(matrix[maxelRow][mid] < right) low = mid + 1;
    }
    return {-1,-1};
}

int main() {
    
    return 0;
}