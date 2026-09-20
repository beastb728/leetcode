class Solution {
public:
    const int inf=1e9;
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        vector<bool>isValid(26,true);
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(start[ch]==-1) start[ch]=i;
            end[ch]=i;
        }
        for(int i=0;i<26;i++){
            if(start[i]==-1) continue;
            int st=start[i] ,e=end[i];
            for(int j=st;j<=end[i];j++){
                int currCh=s[j]-'a';
                if(start[currCh]<st){
                    isValid[i]=false;
                    break;
                }
                end[i]=max(end[i],end[currCh]);
            }
        }
        vector<string>ans;
        int lastStart=inf;
        for(int i=n-1;i>=0;i--){
            int currCh=s[i]-'a';
            if(!isValid[currCh]) continue;
            if(i==start[currCh] && end[currCh]<lastStart){
                ans.push_back(s.substr(i,end[currCh]-i+1));
                lastStart=i;
            }
        }
        return ans;
    }
};