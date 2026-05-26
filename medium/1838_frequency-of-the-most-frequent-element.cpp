// Tags: Sliding Window, Sorting, Prefix Sum
// Difficulty: Medium
// Leetcode 1838

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        long long total = 0;

        int left = 0;
        int max_freq = 1;

        for (int right = 0; right < nums.size(); right++) {

            total += nums[right];

            while ((long long)nums[right] * (right - left + 1) - total > k) {

                total -= nums[left];
                left++;
            }

            max_freq = max(max_freq, right - left + 1);
        }

        return max_freq;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 4};
    int k = 5;

    int ans = obj.maxFrequency(nums, k);

    cout << "Maximum Frequency = " << ans << endl;

    return 0;
}