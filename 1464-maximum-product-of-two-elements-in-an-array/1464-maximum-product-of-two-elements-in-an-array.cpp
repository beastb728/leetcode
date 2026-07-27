class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for (int i : nums) {
            pq.push(i);
        }
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        int ans = (x - 1) * (y - 1);
        return ans;
    }
};