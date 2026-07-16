class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int sum = 0;
            for(auto num : nums) {
                int n = (num >> i);
                if((n & 1) == 1) {
                    sum++;
                }
            }
            sum = sum % 3;
            ans = (ans << 1);
            if(sum) {
                ans += 1;
            }
        }
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();