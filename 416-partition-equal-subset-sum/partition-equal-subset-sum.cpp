class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(int i , int n , vector<int> &nums, int sum){
        if(i>=n || sum < 0){
            return false;
        }
        if(sum == 0){
            return true;//check
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int left = dfs(i + 1, n, nums, sum - nums[i]);
        int right = dfs(i + 1, n, nums, sum);
        
        return dp[i][sum] = left | right;
    }



    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // dp.assign(n , vector<int>(sum/2,-1));
        for(int i = 0 ; i < nums.size(); i++) sum+=nums[i];
        dp.assign(n , vector<int>(sum/2 + 1,-1));
        if(sum & 1 == 1){
            return false;
        }
        return dfs(0, n, nums, sum/2);
        
    }
};