// Tags: Backtracking, Array, String, Sorting, Enumeration
// Difficulty: Medium
// Leetcode 3799: Word Squares II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> result;

        for (int t = 0; t < n; t++) {
            for (int l = 0; l < n; l++) {
                if (l == t) continue;

                for (int r = 0; r < n; r++) {
                    if (r == t || r == l) continue;

                    for (int b = 0; b < n; b++) {
                        if (b == t || b == l || b == r) continue;

                        string& top = words[t];
                        string& left = words[l];
                        string& right = words[r];
                        string& bottom = words[b];

                        if (top[0] == left[0] &&
                            top[3] == right[0] &&
                            bottom[0] == left[3] &&
                            bottom[3] == right[3]) {

                            result.push_back({
                                top,
                                left,
                                right,
                                bottom
                            });
                        }
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};


void printResult(const vector<vector<string>>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << "\"" << res[i][j] << "\"" << (j + 1 < res[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < res.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test Case 1
    vector<string> words1 = {"able", "area", "echo", "also"};
    cout << "Test 1 Output: ";
    printResult(obj.wordSquares(words1));
    cout << "Expected:      [[\"able\", \"area\", \"echo\", \"also\"], [\"area\", \"able\", \"also\", \"echo\"]]" << endl << endl;

    // Test Case 2
    vector<string> words2 = {"code", "cafe", "eden", "edge"};
    cout << "Test 2 Output: ";
    printResult(obj.wordSquares(words2));
    cout << "Expected:      []" << endl;

    return 0;
}
