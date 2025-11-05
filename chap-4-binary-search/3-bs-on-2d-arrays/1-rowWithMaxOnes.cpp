#include<bits/stdc++.h>
using namespace std;

// matrix only consists of 0's and 1's and is row wise sorted so we have to return the row having max number of ones

/////////////////////////////////////////////////////////////////////////////////////

// the brute force involves going through each row and and counting total number of ones and thus finding the row having max ones 

int rowWithMaxOnesBrute(vector<vector<int>> &matrix) {

    int n = matrix.size(), m = matrix[0].size();

    int maxOnes = 0, maxRow = 0;

    for(int i = 0; i < n; i++) {

        int ones = 0;

        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 1) ones++;
        }

        if(ones > maxOnes) {
            maxOnes = ones;
            maxRow = i;
        }
    }

    return maxRow;

} // O(n * m) time and O(1) space

/////////////////////////////////////////////////////////////////////////////////////

// we can optimise the brute force little bit since we know that rows are sorted so as soon as we get the first occurence of 1 we know eveything after that will be 1 (matrix consists of only 0s and 1s) and thus we can break out early as number of ones will be m - index of first occurence of 1

// but again the worst case complexity remains similar thats why we use binary search to find the first occurence of 1 in logm time

///////////////////////////////////////////////////////////////////////////////////

// since matrix only consists of 0's and 1's and every row of matrix is sorted we can consider each row as vector and apply binary search there to quickly find the first one, since the array is sorted, the number of ones would be arr.size() - index of first one

int rowWithMaxOnesOptimal(vector<vector<int>> &matrix) {

    int n = matrix.size(), m = matrix[0].size();

    int maxOnes = 0, maxRow = 0;

    for(int i = 0; i < n; i++) {

        // now apply binary search on each vector

        int low = 0, high = m - 1;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(matrix[i][mid] == 1) {
                high = mid - 1; // we look for better
            } else {
                low = mid + 1; // try to reach 1
            } 
        }

        // high and low have switched polarity and hence low will point to the first index of 1, so total number of ones will be m - low since array is sorted and has m size

        if(m - low > maxOnes) {
            maxOnes = m - low;
            maxRow = i;
        }

    }

    return maxRow;

} // O(n * logm) time

int main() {
    
    return 0;
}