class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        int n = word.size();
        int depth = 1; 
        while (n > 0){
            res = res + min(8, n) * depth;
            n = n - 8;
            depth = depth + 1;
        }
        return res;
    }
};