// Tags: Array, Math
// Difficulty: Easy
// Leetcode 118: Pascal's Triangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> generateRow(int row) {

        long long ans = 1;
        vector<int> temp;

        temp.push_back(1);

        for(int col = 1; col < row; col++) {

            ans = ans * (row - col);
            ans = ans / col;

            temp.push_back(ans);
        }

        return temp;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;

        for(int row = 1; row <= numRows; row++) {
            triangle.push_back(generateRow(row));
        }

        return triangle;
    }
};

int main() {
    Solution s;

    // Example 1: numRows = 5
    int numRows1 = 5;
    cout << "Generating Pascal's Triangle for numRows = " << numRows1 << ":\n";
    vector<vector<int>> result1 = s.generate(numRows1);
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Example 2: numRows = 1
    int numRows2 = 1;
    cout << "Generating Pascal's Triangle for numRows = " << numRows2 << ":\n";
    vector<vector<int>> result2 = s.generate(numRows2);
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
