class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int largest = 0;
        int smallest = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            smallest = min(smallest, prices[i]);

            largest = max(largest, prices[i] - smallest);
        }
        return largest;
    }
};