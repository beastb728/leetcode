// Tags: String, Hash Table
// Difficulty: Medium
// Leetcode 3121: Count the Number of Special Characters II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if (ch >= 'a' && ch <= 'z') {
                
                int idx = ch - 'a';
                lastLower[idx] = i;
            }
            else {

                int idx = ch - 'A';

                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            // character must exist in both lowercase and uppercase
            if (lastLower[i] != -1 && firstUpper[i] != -1) {

                // every lowercase occurrence before first uppercase
                if (lastLower[i] < firstUpper[i]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string word1 = "aaAbcBC";
    cout << obj.numberOfSpecialChars(word1) << endl;

    // string word2 = "abc";
    // cout << obj.numberOfSpecialChars(word2) << endl;

    // string word3 = "AbBCab";
    // cout << obj.numberOfSpecialChars(word3) << endl;

    return 0;
}