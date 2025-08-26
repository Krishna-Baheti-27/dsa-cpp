#include<bits/stdc++.h>
using namespace std;

// three types
// first given row, col give the element
// given the row number, give the nth row
// generate entire pascal triangle for n rows

int getElementOptimal(int row, int col) {
    // formula is r-1Cc-1 so r-1 combination with c - 1
    // but we know this boils down to c * (c-1) * (c - 2) * ...1  for n times, so we also open the r till n times
    long long prod = 1;
    for(int i = 0; i < col - 1; i++) {
        prod *= (row - 1 - i); // first multiply then divide to handle integer division errors
        prod /= (i + 1);
    }
    // for 10c3 it would be 10/1 * 9/2 * 8/3
    return prod;
}

vector<int> getRowBrute(int n) {
    // we know the nth row will have exactly n elements, so nth row we generate elements for all columns using the formula n - 1 C c - 1
    vector<int> ans;
    
    for(int c = 1; c <= n; c++) {
        ans.push_back(getElementOptimal(n, c));
    }
    
    return ans;
}

vector<int> getRowOptimal(int n) {
    int prod = 1;
    vector<int> ans;
    ans.push_back(1); // initial one
    for(int top = n - 1; top >= 1; top--) {
        prod *= top;
        prod /= (n - top);
        ans.push_back(prod);
    }
    return ans;
}

vector<vector<int>> getTriangleBrute(int n) {
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++) {
        vector<int> row;
        for(int j = 1; j <= i; j++) {
            row.push_back(getElementOptimal(i,j));
        }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<int>> getTriangleOptimal(int n) {
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++) {
        // generate all rows using the generate rows function
        vector<int> row = getRowOptimal(i);
        ans.push_back(row);
    }
    return ans;
}

int main() {
    vector<int> ans = getRowOptimal(6);
    for(int el : ans) cout << el << ' ';
    return 0;
}