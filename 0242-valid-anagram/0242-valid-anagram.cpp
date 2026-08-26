class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        for (int j = 0; j < t.size(); j++) {
            freq[t[j]]--;
        }
        for (auto x : freq) {
            if (freq[x.first] != 0) {
                return false;
            }
        }
        return true;
    }
};