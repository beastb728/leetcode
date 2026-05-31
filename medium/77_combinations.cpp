// Tags: Backtracking
// Difficulty: Medium
// Leetcode 77: Combinations

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> store;
        solve(result, store, 1, n, k);
        return result;
    }
    void solve(vector<vector<int>>& result, vector<int>& store, int start, int n, int k) {
    	if (store.size() == k) {
    		result.push_back(store);
    		return;
    	}
    	for (int i = start; i <= n; i++) {
    		store.push_back(i);
    		solve(result, store, i + 1, n, k);
    		store.pop_back();
    	}
    }
};

void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << (j + 1 < res[i].size() ? ", " : "");
        }
        cout << "]" << (i + 1 < res.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    cout << "Test 1 Output: ";
    printResult(obj.combine(4, 2));
    cout << "Expected:      [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]" << endl << endl;

    cout << "Test 2 Output: ";
    printResult(obj.combine(1, 1));
    cout << "Expected:      [[1]]" << endl;

    return 0;
}
