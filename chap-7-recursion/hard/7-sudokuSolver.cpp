#include<bits/stdc++.h>
using namespace std;

// we are given a sudoku puzzle and we have to follow the rules of sudoku and return any possible answer

// so sudoku is a 9 x 9 board which must satisfy the following constraints
// the digits from 1 to 9 must appear exactly once in each row
// the digits from 1 to 9 must appear exactly once in each col
// the digits from 1 to 9 must appear exactly once in the 3 x3 subboard

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == c) {
            return false;
        } 
        if(board[row][i] == c) {
            return false;
        }
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
            return false;
        }
    }

    return true; // if can place on row, col and the 3 x 3 matrix
}

bool solve(vector<vector<char>> &board) {

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == '.') {

                for(char c = '1'; c <= '9'; c++) {

                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if(solve(board) == true) {
                            return true;
                        } else {
                            board[i][j] = '.'; // backtrack step to remove if no solution possible
                        }
                    }
                }

                return false; // couldn place from 1 to 9 hence return false
            }
        }
    }

    return true; // nothing is empty which means successfully solved
}

void solveSudoku(vector<vector<char>> &board) {
    solve(board);
}

int main() {
    
    return 0;
}