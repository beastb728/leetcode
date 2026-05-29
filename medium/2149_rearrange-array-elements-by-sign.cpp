// Tags: Array, Two Pointers, Simulation
// Difficulty: Medium
// Leetcode 2149: Rearrange Array Elements by Sign

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Divide the array into two
        // give the positive part to one vector
        // give the negative part to other vector
        // merge them in alternate order

        vector<int> pos, neg;
        
        for(auto i : nums) {
            if (i > 0) {
                pos.push_back(i);
            }
            else {
                neg.push_back(i);
            }
        }
        vector<int> result;
        for(int j  = 0; j < pos.size(); j++) {
            result.push_back(pos[j]);
            result.push_back(neg[j]);
        }
        
        return result;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    cout << "Test 1 Output: ";
    printVector(obj.rearrangeArray(nums1));
    cout << "Expected: [3, -2, 1, -5, 2, -4]" << endl;

    vector<int> nums2 = {-1, 1};
    cout << "Test 2 Output: ";
    printVector(obj.rearrangeArray(nums2));
    cout << "Expected: [1, -1]" << endl;

    return 0;
}
