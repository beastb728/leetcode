// Tags: Backtracking, Matrix
// Difficulty: Hard
// Leetcode 37: Sudoku Solver

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
	
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					continue;
				}
				for (char k = '1'; k <= '9'; k++) {
					if (isSafe(board, k, i, j)) {
						board[i][j] = k;
						if (solve(board)) {
							return true;
						}
						board[i][j] = '.';
					}
				}
				return false;
				
			}
		}
		return true;	
	}

	bool isSafe(vector<vector<char>>& board, char num, int row, int col) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == num) {
				return false;
			}
			if (board[i][col] == num) {
				return false;
			}
		}
		int startRow = (row / 3) * 3;
		int startCol = (col / 3) * 3;
		for (int i = startRow; i < startRow + 3; i++) {
    		for (int j = startCol; j < startCol + 3; j++) {
        		if (board[i][j] == num) {
            		return false;
        		}
    		}
		}
		return true;
	}

};

void printResult(const vector<vector<char>>& board) {
    cout << "[" << endl;
    for (size_t i = 0; i < board.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << "\"" << board[i][j] << "\"" << (j + 1 < board[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < board.size() ? "," : "") << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test Case 1
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Test 1 Output:" << endl;
    obj.solveSudoku(board1);
    printResult(board1);

    cout << "Expected:" << endl;
    vector<vector<char>> expected1 = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };
    printResult(expected1);

    return 0;
}
