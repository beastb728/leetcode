// Tags: Backtracking, Matrix, Simulation
// Difficulty: Medium
// Leetcode 2596: Check Knight Tour Configuration

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkValidGrid(vector<vector<int>>& grid) {
		int sz = grid.size();
		if (grid[0][0] != 0) {
			return false;
		}
		return solve(grid, 0, sz, 0, 0);
	}
		
	bool solve(vector<vector<int>>& grid, int num, int size, int x, int y) {
		if(num == size * size - 1)
		    return true;

		int dx[8] = {2,2,-2,-2,1,1,-1,-1};
		int dy[8] = {1,-1,1,-1,2,-2,2,-2};

		for(int k = 0; k < 8; k++) {
		    int nx = x + dx[k];
		    int ny = y + dy[k];

		    if(nx >= 0 && nx < size && ny >= 0 && ny < size &&
		       grid[nx][ny] == num + 1) {
		        return solve(grid, num + 1, size, nx, ny);
		    }
		}

		return false;
	}
};

void printResult(bool result) {
	cout << (result ? "true" : "false") << endl;
}

int main() {
	Solution obj;

	// Test Case 1
	vector<vector<int>> grid1 = {
		{0, 11, 16, 5, 20},
		{17, 4, 19, 10, 15},
		{12, 1, 8, 21, 6},
		{3, 18, 23, 14, 9},
		{24, 13, 2, 7, 22}
	};
	cout << "Test 1 Output: ";
	printResult(obj.checkValidGrid(grid1));
	cout << "Expected:      true" << endl << endl;

	// Test Case 2
	vector<vector<int>> grid2 = {
		{0, 3, 6},
		{5, 8, 1},
		{2, 7, 4}
	};
	cout << "Test 2 Output: ";
	printResult(obj.checkValidGrid(grid2));
	cout << "Expected:      false" << endl;

	return 0;
}
