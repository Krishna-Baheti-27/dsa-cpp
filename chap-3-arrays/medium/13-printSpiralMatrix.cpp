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

        // when we traverse from right to left we again have to ensure both conditions that is top <= bottom and left <= right, the second one is already enforced by for loop here so we only have to take care of top <= bottom

        if(top <= bottom) { 
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // when we traverse from bottom to top we again have to ensure both conditions that is top <= bottom and left <= right, the first one is already enforced by for loop here so we only have to take care of left <= right


        if(left <= right) { 
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