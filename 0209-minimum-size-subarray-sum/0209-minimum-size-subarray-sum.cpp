class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int size;
        int finsize = 1e7;
        while (right < nums.size()) {            
            sum = sum + nums[right];;
            while (sum >= target) {
                size = right - left + 1;
                finsize = min(size, finsize);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        if (finsize == 1e7) {
            return 0;
        }

        return finsize;

    }
};