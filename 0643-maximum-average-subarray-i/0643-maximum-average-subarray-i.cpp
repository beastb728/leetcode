class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxsum = sum;
        while (right + 1 < nums.size()) {
            right++;
            sum = sum - nums[left] + nums[right];
            left++;
            maxsum = max(sum, maxsum);
        }
        double finalsum = maxsum;
        return finalsum / k;
    }
};