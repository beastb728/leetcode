class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> count_divisible(max_val + 1, 0);
        for (int g = 1; g <= max_val; ++g) {
            for (int multiple = g; multiple <= max_val; multiple += g) {
                count_divisible[g] += freq[multiple];
            }
        }

        vector<long long> count_gcd(max_val + 1, 0);
        for (int g = max_val; g >= 1; --g) {
            long long total_elements = count_divisible[g];
            long long total_pairs = total_elements * (total_elements - 1) / 2;

            for (int multiple = 2 * g; multiple <= max_val; multiple += g) {
                total_pairs -= count_gcd[multiple];
            }
            count_gcd[g] = total_pairs;
        }

        vector<long long> prefix_sums(max_val + 1, 0);
        for (int g = 1; g <= max_val; ++g) {
            prefix_sums[g] = prefix_sums[g - 1] + count_gcd[g];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            int gcd_value = distance(prefix_sums.begin(), it);
            ans.push_back(gcd_value);
        }

        return ans;
    }
};