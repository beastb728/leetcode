class Solution {
public:
    int rec(vector<int>&dp, int i) {
        if (dp[i] == -1) {
            dp[i] = rec(dp, i - 1) + rec(dp, i - 2);
            return dp[i];
        }
        else {
            return dp[i];
        }
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return rec(dp, n);
    }
};