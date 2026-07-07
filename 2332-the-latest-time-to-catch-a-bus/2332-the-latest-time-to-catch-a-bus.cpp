class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        unordered_set<int> s(passengers.begin(), passengers.end());

        int idx = 0;
        int lastToSit = 0;
        bool lastBusFull = false;

        for (int bus : buses) {
            int current = capacity;

            while (current && idx < passengers.size() && passengers[idx] <= bus) {
                lastToSit = passengers[idx];
                idx++;
                current--;
            }

            if (bus == buses.back())
                lastBusFull = (current == 0);
        }

        int ans;
        if (lastBusFull)
            ans = lastToSit - 1;
        else
            ans = buses.back();

        while (ans >= 0 && s.count(ans))
            ans--;

        return ans;
    }
};