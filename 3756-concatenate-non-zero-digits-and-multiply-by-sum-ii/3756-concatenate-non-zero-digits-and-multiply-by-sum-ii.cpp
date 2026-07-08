class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod = 1000000007;
        int n = s.size();

        vector<long long> pw(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % mod;

        vector<long long> prefVal(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);
        vector<int> prefCnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            prefSum[i + 1] = prefSum[i] + d;
            prefVal[i + 1] = prefVal[i];
            prefCnt[i + 1] = prefCnt[i];

            if (d != 0) {
                prefVal[i + 1] = (prefVal[i] * 10 + d) % mod;
                prefCnt[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int digits = prefCnt[r + 1] - prefCnt[l];
            long long val = (prefVal[r + 1] - (prefVal[l] * pw[digits]) % mod + mod) % mod;
            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((val * sum) % mod);
        }

        return ans;
    }
};