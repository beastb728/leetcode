// Tags: Array, Math
// Difficulty: Easy
// Leetcode 3300: Minimum Element After Replacement With Digit Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int x : nums) {
            int sum = 0;
            int temp = x;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {10, 12, 13, 14};
    cout << "Test 1: " << obj.minElement(nums1) << " (Expected: 1)" << endl;

    vector<int> nums2 = {999, 19, 199};
    cout << "Test 2: " << obj.minElement(nums2) << " (Expected: 10)" << endl;

    return 0;
}
