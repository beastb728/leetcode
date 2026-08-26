class Solution {
public:
    bool isPalindrome(string s) {
        string alphanum;
        for (char c : s) {
            if (isalnum(c)) {
                alphanum += tolower(c);
            }
        }
        int left = 0;
        int right = alphanum.size() - 1;
        while (left < right) {
            if (alphanum[left] != alphanum[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};