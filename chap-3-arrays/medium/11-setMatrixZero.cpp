#include<bits/stdc++.h>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

////////////////////////////////////////////////////////////////////////////////////

// in the brute force we simply traverse the matrix and if we encounter a 0 then we simply set the entire column and row for that 0 to be 0

void setZeroesBrute(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                // mark the entire row and column as 0
                for(int k = 0; k < m; k++) {
                    ans[i][k] = 0; // marking the ith row
                }
                for(int k = 0; k < n; k++) {
                    ans[k][j] = 0; // marking the jth column
                }
            }
        }
    }
} // O(m * n * (n + m)) time and O(m * n) space

//////////////////////////////////////////////////////////////////////////////////////

// the better solution is using an external array for both rows and cols in which we mark them when we see a 0, and then again iterate and change all the elements to 0 which have either row or col marked as 0

void setZeroesBetter(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> rowMarker(n,false);
    vector<int> colMarker(m,false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                rowMarker[i] = true; // mark the entire row
                colMarker[j] = true; // mark the entire col
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rowMarker[i] == true || colMarker[j] == true) {
                matrix[i][j] = 0;
            }
        }
    }
} // O(2 * n * m) time and O(n + m) space

///////////////////////////////////////////////////////////////////////////////////

void setZeroesOptimal(vector<vector<int>> &matrix) {

    int n = matrix.size(), m = matrix[0].size(), col0 = 1;

    // we would be considering first row and first column as markers and col0 as marker for 0th col

    // here zero is similar to marking them as true, this means when we iterate again, we will have to turn ith and jth row to 0

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0; // marker for rows
                if(j != 0) {
                    matrix[0][j] = 0; // marker for columns
                } else {
                    col0 = 0; // since col0 acts as marker for 0th column
                }
            }
        }
    }
    
    // but here we start iterating inner elements first, starting from last and not first row and first column because those are our markers and hampering those would result in incorrect solution or more number of zeroes being marked then what was required

    for(int i = n - 1; i >= 1; i--) {
        for(int j = m - 1; m >= 1; j--) {

            // if either row or col marked then turn into 0

            if(matrix[i][0] == 0 || matrix[0][j] == 0) { 
                matrix[i][j] = 0;
            }

        }
    }

    // also very important to mark first row firsr because its marker is mat[0][0] and if we mark first column first then it can be changed hence mark first row then col using col0

    if(matrix[0][0] == 0) { // this was for the first row
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0) { // marker for the first column
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

}

int main() {
    
    return 0;
}