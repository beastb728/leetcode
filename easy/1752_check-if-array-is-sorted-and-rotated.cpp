// Leetcode 1752
// Difficulty: Easy
// Tags: Array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 4, 5, 1, 2};

    if (sol.check(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}