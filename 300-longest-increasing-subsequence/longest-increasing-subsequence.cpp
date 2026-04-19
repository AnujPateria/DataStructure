class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int n, int prev, vector<int> &nums){
        if(i == n){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1+solve(i + 1, n, i, nums);
        }

        return dp[i][prev+1] = max(solve(i+1, n, prev, nums), take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int n = nums.size();
        // for(int i = 0 ; i < nums.size(); i++/)e
        dp.assign(n, vector<int> (n+1, -1));
        return solve(0, n, prev, nums);
    }
};