#include<bits/stdc++.h>
using namespace std;

// three types
// first given row, col give the element
// given the row number, give the nth row
// generate entire pascal triangle for n rows

//////////////////////////////////////////////////////////////////////////////////////

 // formula is r-1Cc-1 so r-1 combination with c - 1 for r row and c col
// but we know this boils down to c * (c-1) * (c - 2) * ...1  for n times, so we also open the r till n times

// for 10c3 it would be 10/1 * 9/2 * 8/3

int nCombR(int row, int col) {
   
    long long prod = 1;
    for(int i = 0; i < col; i++) { 
        prod *= (row - i); // first multiply then divide to handle integer division errors
        prod /= (i + 1);
    }
    
    return prod;
} // O(col) time

/////////////////////////////////////////////////////////////////////////////

// we know the nth row will have exactly n elements, so nth row we generate elements for all columns using the formula n - 1 C c - 1

vector<int> getRowBrute(int n) {
    
    vector<int> ans;
    
    for(int c = 1; c <= n; c++) {
        ans.push_back(nCombR(n - 1, c - 1));
    }
    
    return ans;
} // O(n * c) where c is avg number of columns in thw worst case it is O(n^2) time

// instead of calculating for all elements one by one starting from scratch we simply, find all the values on the go starting from n - 1 C 0 to n - 1 C n - 1 by simplifying it, since we would have exactly n columns in the nth row 

vector<long long> getRowOptimal(int n) {
    long long prod = 1;
    vector<long long> ans;
    ans.push_back(1); // initial one
    for(int top = n - 1; top >= 1; top--) {
        prod *= top;
        prod /= (n - top);
        ans.push_back(prod);
    }
    return ans;
} // O(n) time

//////////////////////////////////////////////////////////////////////////////////////

// the brute involves we generate the triangle row by row and generate row by finding all elements using n - 1 C c - 1

vector<vector<int>> getTriangleBrute(int n) {
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++) {
        vector<int> row;
        for(int j = 1; j <= i; j++) {
            row.push_back(nCombR(i - 1,j - 1)); // since its n - 1 C c - 1
        }
        ans.push_back(row);
    }
    return ans;
} // O(n^3) time

vector<vector<long long>> getTriangleOptimal(int n) {
    vector<vector<long long>> ans;
    for(int i = 1; i <= n; i++) {
        // generate all rows using the generate rows function
        vector<long long> row = getRowOptimal(i);
        ans.push_back(row);
    }
    return ans;
} // O(n^2) time 

int main() {
    vector<long long> ans = getRowOptimal(6);
    for(int el : ans) cout << el << ' ';
    return 0;
}