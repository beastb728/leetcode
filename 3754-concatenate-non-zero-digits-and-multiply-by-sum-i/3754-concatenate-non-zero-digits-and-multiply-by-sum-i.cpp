class Solution {
public:
    long long sumAndMultiply(int n) {
        int mul = 1;
        int val = 0;
        long long sum = 0;
        int copy = n;

        while (copy > 0) {
            int d = copy % 10;
            sum += d;

            if (d != 0) {
                val = d * mul + val;
                mul *= 10;
            }
            copy /= 10;
        }

        return sum * val;
    }
};