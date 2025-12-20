class Solution {
public:

    int find(int n , vector<int>&nums, vector<int> &dp){
        if(n<0) return 0;
        if(n==0){
            return nums[n];
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int first = nums[n] + find(n-2, nums, dp);
        int second = find(n-1, nums ,dp);
        return dp[n] = max(first, second);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(n-1, nums, dp);
    }
};