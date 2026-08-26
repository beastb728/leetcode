class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            }
        }
        erase(nums, 0);
        for (int j = 0; j < count; j++) {
            nums.push_back(0);
        }
    }
};