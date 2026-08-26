class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix = 0;
        int minPrefix = 0;
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            prefix = prefix + nums[i];
            ans = max(ans, prefix - minPrefix);
            minPrefix = min(minPrefix, prefix);
        }

        return ans;
    }
};