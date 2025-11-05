#include<bits/stdc++.h>
using namespace std;

// we are given a n x n chess board and we have to place n queens such that no two queens attack each other

// we can return the board configuration in any order

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

/////////////////////////////////////////////////////////////////////////////////////

// the main logic is in checking if the queen is safe or not and since we are placing queens from left to right we dont have to check in right direction and since we placing queen only one in each column we dont have to check for up and down, we only have to check for left side, upper diagonal and lower diagonal

bool isSafe(int row, int col, vector<string> &board, int n) {

    int duprow = row;
    int dupcol = col;

    // checking for upper diagonal

    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // checking for left columns

    row = duprow;
    col = dupcol;

    while(col >= 0) {
        if(board[row][col] == 'Q') return false;
        col--;
    }

    // checking for lower diagonal

    row = duprow;
    col = dupcol;

    while(row < n && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true; // if everywhere safe

}

void solveBrute(int col, vector<string> &board, vector<vector<string>> &ans, int n) {

    // if we have exceeded the last column then we have surely placed all the queens and hence append the current board config to our answer

    if(col >= n) {
        ans.push_back(board);
        return;
    }

    // try for each row in a particular column

    for(int i = 0; i < n; i++) {
        if(isSafe(i, col, board, n)) {
            board[i][col] = 'Q';
            solveBrute(col + 1, board, ans, n);
            board[i][col] = '.'; // remove it (our backtracking step)
        }
    }

}

vector<vector<string>> nQueensBrute(int n) {

    vector<vector<string>> ans; // to store our answers
    vector<string> board(n); // the config for a particular board where a string represents a row

    string s(n , '.'); // string of n length having all empty cols => "....." like this

    for(int i = 0; i < n; i++) {
        board[i] = s; // make each row of board to be that empty col string
    }

    solveBrute(0, board, ans, n); // start solving from 0th column

    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////

// we can optimise the isSafe function so that we dont take O(3n) time for that by using hashing to mark the left side row, left upper diagonal and left lower diagonal

void solveOptimal(int col, vector<string> &board, vector<vector<string>> &ans, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, int n) {

    // if we have exceeded the last column then we have surely placed all the queens and hence append the current board config to our answer

    if(col >= n) {
        ans.push_back(board);
        return;
    }

    // try for each row in a particular column

    for(int i = 0; i < n; i++) {

        if(leftRow[i] == false && lowerDiagonal[i + col] == false && upperDiagonal[n - 1 + col - i] == false) {

            board[i][col] = 'Q';

            leftRow[i] = true;
            lowerDiagonal[i + col] = true;
            upperDiagonal[n - 1 + col - i] = true;

            solveOptimal(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            board[i][col] = '.'; // remove it (our backtracking step)
            leftRow[i] = false;
            lowerDiagonal[i + col] = false;
            upperDiagonal[n - 1 + col - i] = false;

        }
    }

}

vector<vector<string>> nQueensBrute(int n) {

    vector<vector<string>> ans; // to store our answers
    vector<string> board(n); // the config for a particular board where a string represents a row

    string s(n , '.'); // string of n length having all empty cols => "....." like this

    for(int i = 0; i < n; i++) {
        board[i] = s; // make each row of board to be that empty col string
    }

    vector<bool> leftRow(n, false), upperDiagonal(2 * n - 1, false), lowerDiagonal(2 * n - 1, false);

    solveOptimal(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // start solving from 0th column

    return ans;
}

int main() {
    
    return 0;
}