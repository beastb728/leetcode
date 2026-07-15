class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 1 || x == 0 || x == 1)
            return x;
        if (n < 0)
            return myPow(1.0 / x, -n);
        double dp[32];
        dp[0] = x;
        for (int i = 1; i < 32; i++)
            dp[i] = dp[i - 1] * dp[i - 1];

        double answer = 1.0;
        int i = 0;
        while (n) {
            if (n & 1)
                answer *= dp[i];
            i++;
            n >>= 1;
        }
        return answer;
    }
};