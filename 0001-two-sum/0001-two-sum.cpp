class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> uo;
        for (int i = 0; i < nums.size(); i++) {
            int loc = target - nums[i];
            if (uo.contains(loc)) {
                return {i, uo[loc]};
            }
            else {
                uo[nums[i]] = i;
            }
        }
        return {};
    }
};