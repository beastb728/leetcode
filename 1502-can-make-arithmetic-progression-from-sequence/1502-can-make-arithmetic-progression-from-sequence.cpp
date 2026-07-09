class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int x = arr.size();
        if (x == 1 || x == 2) {
            return true;
        }
        int diff = 0;
        while (x--) {
            diff = arr[1] - arr[0];
            for (int i = 1; i < x; i++) {
                if (diff != arr[i + 1] - arr[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};