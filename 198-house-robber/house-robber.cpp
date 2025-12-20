class Solution {
public:

    // int find(int n , vector<int>&nums, vector<int> &dp){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(n==0){
    //         return nums[n];
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return dp[n] = max(nums[n] + find(n-2,nums, dp), find(n-1, nums, dp));
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        if(n==1){
            return nums[0];
        }
        if(n==1){
            return max(nums[0], nums[1]);
        }

        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        int first = nums[0];
        int second = max(nums[0], nums[1]);

        // int ans =0;/

        // if(n==1){
        //     return dp[n];
        // }

        for(int i = 2 ; i < n ; i++){
            
            int ans = max(nums[i] + first, second);
            first = second ;
            second = ans;



            // dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return second;


        // return find(n-1, nums, dp);
    }
};