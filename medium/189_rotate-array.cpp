// Tags: Array, Two Pointers
// Difficulty: Medium
// Leetcode 189: Rotate Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if((i + k) > nums.size()-1) {
                ans.push_back(nums[i + k - nums.size()]);
            }
            else {
                ans.push_back(nums[i + k]);
            }
        }
        for(auto x : ans) {
            cout << x << " ";
        }
    }
};

int main() {
    Solution s;

    // Example 1: nums = [1,2,3,4,5,6,7], k = 3
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Original 1: ";
    for (int x : nums1) cout << x << " ";
    cout << "\nRotating by " << k1 << "...\n";
    s.rotate(nums1, k1);
    cout << "Result 1:   ";
    for (int x : nums1) cout << x << " ";
    cout << "\n\n";

    // Example 2: nums = [-1,-100,3,99], k = 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    cout << "Original 2: ";
    for (int x : nums2) cout << x << " ";
    cout << "\nRotating by " << k2 << "...\n";
    s.rotate(nums2, k2);
    cout << "Result 2:   ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}
