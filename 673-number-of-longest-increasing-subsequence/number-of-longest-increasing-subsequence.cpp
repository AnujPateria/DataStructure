class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> dp;

    // returns {maxLISLength, count}
    pair<int,int> solve(int idx, int prev, vector<int>& nums) {
        if (idx == n) {
            return {0, 1};   // length 0, one valid way
        }

        if (dp[idx][prev + 1].first != -1) {
            return dp[idx][prev + 1];
        }

        // Option 1: NOT TAKE
        auto notTake = solve(idx + 1, prev, nums);

        // Option 2: TAKE (if valid)
        pair<int,int> take = {0, 0};
        if (prev == -1 || nums[prev] < nums[idx]) {
            auto next = solve(idx + 1, idx, nums);
            take.first = 1 + next.first;
            take.second = next.second;
        }

        // Choose best
        pair<int,int> res;
        if (take.first > notTake.first) {
            res = take;
        }
        else if (take.first < notTake.first) {
            res = notTake;
        }
        else {
            res.first = take.first;
            res.second = take.second + notTake.second;
        }

        return dp[idx][prev + 1] = res;
    }

    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<pair<int,int>>(n + 1, {-1, -1}));

        return solve(0, -1, nums).second;
    }
};
