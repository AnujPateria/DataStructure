class Solution {
public:
    vector<vector<int>>dp;
    int sum = 0;
    int dfs(int n, vector<int> &nums,int curr, int &target){
        if( n == 0 ){
            return curr == target;
        }
        if(dp[curr + sum][n - 1] != -1){
            return dp[curr + sum][n - 1];
        }
        int take = dfs(n-1, nums, curr + nums[n-1], target);
        int notTake = dfs(n-1, nums, curr - nums[n-1], target);
        return dp[curr + sum][n - 1] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int curr = 0;
        // int sum = 0;
        for(int i = 0 ;i < nums.size(); i++){
            sum+=(abs(nums[i]));
        }
        dp.assign(2* 1e3+1, vector<int> (2* 1e3+1, -1));
        return dfs(n, nums, curr, target);
    }
};