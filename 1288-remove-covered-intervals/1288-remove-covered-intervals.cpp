class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) noexcept {
        ranges::sort(a, less{}, [&](auto& x) {
            return tuple{x[0], -x[1]};
        });
        int r = 0;
        for (int p = 0; auto& x : a) {
            int e = x[1];
            r += e > p;
            p = max(p, e);
        }
        return r;
    }
};