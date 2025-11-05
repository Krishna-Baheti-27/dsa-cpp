#include<bits/stdc++.h>
using namespace std;

// the peak element of a matrix is defined as the element which is greater than the elements on its left, right, top and bottom, where no two adjacent cells have same value and entire matrix is surrounded by -1

/////////////////////////////////////////////////////////////////////////////////////////

// brute involves scanning through entire matrix and making 4 checks at top right bottom left so O(4 * m * n) time
// but we can optimise this by simpply returning the largest element in matrix so O(m * n)

/////////////////////////////////////////////////////////////////////////////////////////

// now the most optimal solution here still uses the intuition from peakEl1
// we do binary search across columns or rows, by finding max in cols/rows and then checking it with left and right so that we know which portion to eliminate

// we start it with kets midcol then find the global max of that col then check to its left and right, if left is greater we eliminate right, if right is greater we eliminate left and if both are lesser then thats our answer

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

} // O(logm * n) time

////////////////////////////////////////////////////////////////////////////////////////

// this is incorrect way to applu binary search as we have not written the condition to eliminate either half

// vector<int> peakEl2Optimal2(vector<vector<int>> &matrix) {

//     int n = matrix.size(), m = matrix[0].size();

//     int drow[] = {-1, 0, +1 , 0};
//     int dcol[] = {0, 1, 0, -1};
    
//     for(int i = 0; i < n; i++) {

//         int low = 0, high = m - 1;

//         while(low <= high) {

//             int mid = low + (high - low) / 2;

//             // for mid to be peak element it must be greater from 4 sides

//             bool flag = true;

//             for(int j = 0; j < 4; j++) {

//                 int row = i + drow[j];
//                 int col = mid + dcol[j];

//                 if(row < n && row >= 0 && col < m && col >= 0) {
//                     if(matrix[i][mid] < matrix[row][col]) {
//                         flag = false;
//                     }
//                 }
//             }

//             if(flag == true) {
//                 return {i, mid};
//             } 
            
//         }
//     }

//     return {-1, -1};
// }

int main() {
    
    return 0;
}