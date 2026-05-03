class Solution {
public:
    int maxFixedPoints(vector<int> &nums) {

    int n = nums.size();
    vector<pair<long long, long long>> v;

    // Step 1: collect valid pairs
    for(int i = 0; i < n; i++) {
        long long val = nums[i];
        if(val <= i) {
            long long d = i - val;
            v.push_back({d, val});
        }
    }

    // Step 2: sort by (i - val)
    sort(v.begin(), v.end());

    // Step 3: LIS on second value
    vector<long long> dp;

    for(int i = 0; i < v.size(); i++) {
        long long val = v[i].second;

        auto it = lower_bound(dp.begin(), dp.end(), val);

        if(it == dp.end()) {
            dp.push_back(val);
        } else {
            *it = val;
        }
    }

    return dp.size();
}
};