// Tags: Segment Tree, Binary Indexed Tree, Set, Binary Search
// Difficulty: Hard
// Leetcode 3161: Block Placement Queries


// Not used the recommended SEGMENT TREE but rather done with Ordered Set + Ordered Map + Interval Splitting
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(10000000);

        // gap_length -> set of starting positions
        map<int, set<int>> gaps;

        gaps[10000000].insert(0);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto itRight = obstacles.lower_bound(x);
                int right = *itRight;
                int left = *prev(itRight);

                int oldGap = right - left;

                gaps[oldGap].erase(left);
                if (gaps[oldGap].empty()) {
                    gaps.erase(oldGap);
                }

                int leftGap = x - left;
                int rightGap = right - x;

                gaps[leftGap].insert(left);
                gaps[rightGap].insert(x);

                obstacles.insert(x);
            }
            else {
                int x = q[1];
                int sz = q[2];

                bool possible = false;

                auto it = gaps.lower_bound(sz);

                while (it != gaps.end()) {
                    int gapLen = it->first;
                    const set<int>& starts = it->second;

                    if (!starts.empty()) {
                        int startPos = *starts.begin();

                        if (startPos + sz <= x) {
                            possible = true;
                            break;
                        }
                    }

                    ++it;
                }

                ans.push_back(possible);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> queries1 = {
        {1, 2},
        {2, 3, 3},
        {2, 3, 1},
        {2, 2, 2}
    };
    cout << "Test 1 Output: ";
    printBoolVector(obj.getResults(queries1));
    cout << "Expected: [false, true, true]" << endl << endl;

    vector<vector<int>> queries2 = {
        {1, 7},
        {2, 7, 6},
        {1, 2},
        {2, 7, 5},
        {2, 7, 6}
    };
    cout << "Test 2 Output: ";
    printBoolVector(obj.getResults(queries2));
    cout << "Expected: [true, true, false]" << endl;

    return 0;
}
