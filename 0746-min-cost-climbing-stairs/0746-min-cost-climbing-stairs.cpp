class Solution {
public:
    int rec(vector<int>&cost, vector<int>&dp, int i) {
        if (dp[i] == -1) {
            int t = min(rec(cost, dp, i - 1), rec(cost, dp, i - 2));
            dp[i] = t + cost[i];
            return dp[i];
        }
        else {
            return dp[i];
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        return min(rec(cost, dp, n - 1), rec(cost, dp, n - 2));
    }
};