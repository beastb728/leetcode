class Solution {
public:
    int rec(vector<int>& dp, int n) {
        if (dp[n] == -1) {
            dp[n] = rec(dp, n - 1) + rec(dp, n - 2) + rec(dp, n - 3);
            return dp[n];
        }
        else {
            return dp[n];
        }
    }

    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return rec(dp, n);
    }
};