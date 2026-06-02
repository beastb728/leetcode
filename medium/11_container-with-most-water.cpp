// Tags: Two-Pointers, Array, Greedy
// Difficulty: Medium
// Leetcode 11: Container With Most Water

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // TODO: Implement the solution here.
        // Return the maximum amount of water a container can store.
        return 0;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1 Output: " << obj.maxArea(height1) << endl;
    cout << "Expected:      49" << endl << endl;

    // Test Case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2 Output: " << obj.maxArea(height2) << endl;
    cout << "Expected:      1" << endl;

    return 0;
}
