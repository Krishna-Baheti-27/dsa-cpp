#include<bits/stdc++.h>
using namespace std;

void setZeroesBrute(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                // mark the entire row and column as 0
                for(int k = 0; k < m; k++) {
                    ans[i][k] = 0; // marking the row
                }
                for(int k = 0; k < n; k++) {
                    ans[k][j] = 0; // marking the column
                }
            }
        }
    }
} // O(m * n * (n + m)) time and O(m * n) space

// There are two solutions, use an external array having space O(n + m) for marking the rows and columns to be 0
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

void setZeroesOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size(), col0 = 1;
    // we would be considering first row and first column as markers
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0; 
                if(j != 0)
                matrix[0][j] = 0;
                else col0 = 0;
                // here zero is similar to marking them as true, this means when we iterate again, we will have to turn ith and jth row to 0
            }
        }
    }
    // but here we start iterating inner elements first, starting from last and not first row and column because those are our markers and hampering those would result in incorrect solution or more number of zeroes being marked then what was required
    for(int i = n - 1; i >= 1; i--) {
        for(int j = m - 1; m >= 1; m--) {
            if(matrix[i][j] != 0) {
                // then only convert right else no sense in converting 0 back to 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    
    return 0;
}