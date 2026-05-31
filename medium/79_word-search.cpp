// Tags: Array, String, Backtracking, Matrix
// Difficulty: Medium
// Leetcode 79: Word Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {
    	int row = board.size();
    	int col = board[0].size();
    	int position = 0;
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
				if (board[i][j] == word[position]) {
					board[i][j] = ' ';
					if(solve(i, j, position + 1, board, word)) return 1;
					board[i][j] = word[position];
				}
        	}
        }
        return false;
    }
    bool solve(int row, int col, int position, vector<vector<char>>& board, string& word) {
        if (position == word.size()) {
        	return 1;
        }
        int r, c;
    	int raw = board.size();
    	int cal = board[0].size();
    	
        r = row - 1, c = col;
        if ( r > -1 && c > -1 && r < raw && c < cal) {
		    if (board[r][c] == word[position]) {
				board[r][c] = ' ';
		    	if(solve(r, c, position + 1, board, word)) return 1;
		    	board[r][c] = word[position];
		    }
        }
        
        r = row + 1, c = col;
        if ( r > -1 && c > -1 && r < raw && c < cal) {
		    if (board[r][c] == word[position]) {
				board[r][c] = ' ';
		    	if(solve(r, c, position + 1, board, word)) return 1;
		    	board[r][c] = word[position];
		    }
        }

        r = row, c = col - 1;
        if ( r > -1 && c > -1 && r < raw && c < cal) {
		    if (board[r][c] == word[position]) {
				board[r][c] = ' ';
		    	if(solve(r, c, position + 1, board, word)) return 1;
		    	board[r][c] = word[position];
		    }
        }

        r = row, c = col + 1;
        if ( r > -1 && c > -1 && r < raw && c < cal) {
		    if (board[r][c] == word[position]) {
				board[r][c] = ' ';
		    	if(solve(r, c, position + 1, board, word)) return 1;
		    	board[r][c] = word[position];
		    }
        }
        
        return 0;

    }
};

int main() {
    Solution obj;

    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    cout << "Test 1: " << (obj.exist(board1, word1) ? "true" : "false") << " (Expected: true)" << endl;

    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "SEE";
    cout << "Test 2: " << (obj.exist(board2, word2) ? "true" : "false") << " (Expected: true)" << endl;

    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word3 = "ABCB";
    cout << "Test 3: " << (obj.exist(board3, word3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}
