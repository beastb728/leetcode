class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        set<int> r;
        set<int> c;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for (const auto& a : r) {
            for (int c = 0; c < col; c++) {
                matrix[a][c] = 0;
            }
        }

        for (const auto& b : c) {
            for (int d = 0; d < row; d++) {
                matrix[d][b] = 0;
            }
        }
    }
};