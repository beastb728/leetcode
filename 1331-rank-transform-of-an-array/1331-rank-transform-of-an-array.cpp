class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> ranks(arr.size());
        int rank = 1;

        for(int i : temp){
            if(ranks.count(i) == 0)
                ranks[i] = rank++;
        }

        for(int &i : arr)
            i = ranks[i];

        return arr;
    }
};