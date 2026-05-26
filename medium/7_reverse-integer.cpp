// Tags: Math
// Difficulty: Medium
// Leetcode 7

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {
            int digit = x % 10;

            // overflow check
            if (rev > INT_MAX / 10 || 
               (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            // underflow check
            if (rev < INT_MIN / 10 || 
               (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev;
    }
};

int main() {

    Solution s;

    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(120) << endl;
    cout << s.reverse(1534236469) << endl;

    return 0;
}