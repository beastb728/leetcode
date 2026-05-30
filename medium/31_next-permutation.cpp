// Tags: Array, Two Pointers
// Difficulty: Medium
// Leetcode 31: Next Permutation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1 Input:  ";
    printVector(nums1);
    obj.nextPermutation(nums1);
    cout << "Test 1 Output: ";
    printVector(nums1);
    cout << "Expected:      [1, 3, 2]" << endl << endl;

    vector<int> nums2 = {3, 2, 1};
    cout << "Test 2 Input:  ";
    printVector(nums2);
    obj.nextPermutation(nums2);
    cout << "Test 2 Output: ";
    printVector(nums2);
    cout << "Expected:      [1, 2, 3]" << endl << endl;

    vector<int> nums3 = {1, 1, 5};
    cout << "Test 3 Input:  ";
    printVector(nums3);
    obj.nextPermutation(nums3);
    cout << "Test 3 Output: ";
    printVector(nums3);
    cout << "Expected:      [1, 5, 1]" << endl;

    return 0;
}
