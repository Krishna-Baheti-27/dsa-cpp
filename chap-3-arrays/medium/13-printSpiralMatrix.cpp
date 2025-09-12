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
        for(int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
} // O(n * m) time and O(n * m) space

int main() {
    
    return 0;
}