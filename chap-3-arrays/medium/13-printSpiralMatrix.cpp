#include<bits/stdc++.h>
using namespace std;

// this is an implementation based problem, it only has one and only one optimal solution
// so lets see how to do it

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1 ,top = 0, bottom = n - 1;
    vector<int> ans;

    while(top <= bottom && left <= right) {
        // we already have left <= right enforced here due to for loop
        for(int i = left; i <= right; i++) { 
            ans.push_back(matrix[top][i]);
        }
        top++;
        // we already have top <= bottom enforced here due to for loop
        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom) { // it maybe that top > bottom in that case we have no element in that row and when top == bottom we have single row left to traversed from right to left
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) { // it maybe that left > right in that case we have no element in the column and when left == right we have single column left to be traversed from bottom to top
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
} // O(n * m) time 

int main() {
    
    return 0;
}