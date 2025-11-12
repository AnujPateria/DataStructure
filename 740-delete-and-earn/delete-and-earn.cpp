#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mpp;

        // build frequency * value
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]] += nums[i]; // changed: directly store total value
        }

        vector<pair<int, int>> vec;
        for (auto n : mpp) {
            vec.push_back({n.first, n.second}); // corrected: key, total points
        }

        // sort by key (not by total value)
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.first < b.first;
        });

        // Debug print (optional)
        // for (int i = 0; i < vec.size(); i++) {
        //     cout << vec[i].first << " => " << vec[i].second << endl;
        // }

        int prev2 = 0, prev1 = 0; // like dp[i-2], dp[i-1]

        for (int i = 0; i < vec.size(); i++) {
            int curr = 0;
            if (i > 0 && vec[i].first == vec[i - 1].first + 1)
                curr = max(prev1, prev2 + vec[i].second);  // adjacent
            else
                curr = prev1 + vec[i].second;              // not adjacent

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
