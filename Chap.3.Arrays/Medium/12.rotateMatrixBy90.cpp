#include<bits/stdc++.h>
using namespace std;

void rotateMatrixBrute(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int> (n)); // O(N^N) extra space for getting the result
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

// find optimal yourself
void rotateMatrixOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // we have to optimise the space which basically means, do something in the matrix itself
}

int main() {
    
    return 0;
}