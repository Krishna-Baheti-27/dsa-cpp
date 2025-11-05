#include<bits/stdc++.h>
using namespace std;

// we have to rotate the matrix by 90 degree in clockwise fashion

///////////////////////////////////////////////////////////////////////////////

// in the brute force we simply create a new matrix and insert by manipulating indices

void rotateMatrixBrute(vector<vector<int>> &matrix) {

    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int> (n)); // O(N^2) extra space for getting the result

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][n - i - 1] = matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = ans[i][j];
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

// we have to optimise the space which basically means, do something in the matrix itself

// so you have to know this observation you cant figure out in interview

// 90 = transpose + reverse row
// 180 = reverse row + reverse column
// 270 = transpose + reverse col

// here we have to rotate by 90 clockwise so first find transpose and reverse all rows

void rotateMatrixOptimal(vector<vector<int>> &matrix) {

    int n = matrix.size();
    
    // to find transpose of matrix in place we have this observation 

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // and now just reverse the rows

    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    
    return 0;
}