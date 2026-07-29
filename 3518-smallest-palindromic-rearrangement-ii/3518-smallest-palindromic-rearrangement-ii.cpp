#define ll long long
class Solution {
public:
    ll countPerms(map<char, int>& freq) {
        vector<int> denoms;
        int total = 0;

        for (auto& [_, cnt] : freq) {
            if (cnt > 1)
                for (int i = 2; i <= cnt; ++i)
                    denoms.push_back(i);
            total += cnt;
        }

        ll result = 1;
        int d = 0;

        for (int i = 2; i <= total; ++i) {
            result *= i;

            while (d < denoms.size() && result % denoms[d] == 0) {
                result /= denoms[d++];
            }

            if (result > 1e6)
                return result;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        map<char, int> freq;
        for (char c : s) freq[c]++;

        int oddCount = 0;
        char oddChar = 0;
        for (auto& [c, cnt] : freq) {
            if (cnt % 2) {
                oddCount++;
                oddChar = c;
            }
        }

        map<char, int> halfFreq;
        for (auto& [c, cnt] : freq){
            if(cnt/2==0)continue;
            halfFreq[c] = cnt / 2;
        }
            

        int halfLen = 0;
        for (auto& [_, cnt] : halfFreq)
            halfLen += cnt;

        string leftHalf = "";
        for (int i = 0; i < halfLen; ++i) {
            bool flg=false;
            for (auto& [c, cnt] : halfFreq) {
                if (cnt == 0) continue;

                cnt--;
                ll perms = countPerms(halfFreq);
                if (perms >= k) {
                    leftHalf += c;
                    flg=true;
                    break;
                } 
                else {
                    k -= perms;
                    cnt++;
                }
            }
            if(!flg)return "";
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        string middle = (oddCount == 1 ? string(1, oddChar) : "");

        return leftHalf + middle + rightHalf;
    }
};