class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> st;
        for (int i = 0; i < strs.size(); i++) {
            map<char, int> freq;
            for (int j = 0; j < strs[i].size(); j++) {
                char c = strs[i][j];
                freq[c]++;
            }
            st[freq].push_back(strs[i]);
        }
        vector<vector<string>> sol;
        for (auto x : st) {
            sol.push_back(x.second);
        }
        return sol;
    }
};