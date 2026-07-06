class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0) {
            return grid;
        }
        int numberOfRow = grid.size();
        int numberOfCol = grid[0].size();
        vector<vector<int>> grid_answer(numberOfRow, vector<int>(numberOfCol));

        while (k--) {
            for (int i = 0; i < numberOfRow; i++) {
                for (int j = 0; j < numberOfCol; j++) {
                    if (j == numberOfCol - 1) {
                        grid_answer[i][0] = grid[i][j];
                    }
                    else {
                        grid_answer[i][j+1] = grid[i][j];
                    }
                }
            }

            grid_answer[0][0] = grid[numberOfRow - 1][numberOfCol - 1];

            for (int k = 1; k < numberOfRow; k++) {
                grid_answer[k][0] = grid[k - 1][numberOfCol - 1];
            }

            grid = grid_answer;
        }

        return grid_answer;
    }
};