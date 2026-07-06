class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int current_row = -1;
        for (int i = 0; i < row; i++) {
            int a = matrix[i][col-1];
            current_row = i;
            if (target <= a) {
                break;
            }
        }

        for (int j = 0; j < col; j++) {
            if (matrix[current_row][j] == target) {
                return true;
            }
        }
        return false;
    }
};