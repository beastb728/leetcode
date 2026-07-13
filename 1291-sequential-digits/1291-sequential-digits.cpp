class Solution {
public:
    void rec(vector<int>& res, int curr, int num, int low, int high) {
        if (num == 10)
            return;

        curr = curr * 10 + num;

        if (curr >= low && curr <= high) {
            res.push_back(curr);
            rec(res, curr, num + 1, low, high);
        }
        if (curr > high)
            return;

        if (curr < low)
            rec(res, curr, num + 1, low, high);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int i = 1; i < 10; i++)
            rec(res, 0, i, low, high);

        sort(res.begin(), res.end());

        return res;
    }
};