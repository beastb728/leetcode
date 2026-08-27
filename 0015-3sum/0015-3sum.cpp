class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -4, -1, -1, 0, 1, 2
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum;
                sum = nums[left] + nums[right];
                if (sum > target) {
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    vector<int> vec = {nums[i], nums[left], nums[right]};
                    sol.push_back(vec);
                    left++;
                    right--;
                }
            }
        }
        return sol;
    }
};