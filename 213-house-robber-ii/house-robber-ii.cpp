class Solution {
public:
    int find(int n , vector<int>&nums){
        // int n = nums.size() - 1;
        vector<int> dp(n, -1);
        
        if(n==1){
            return nums[0];
        }
        if(n==2){
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
    }
    int find2(int n , vector<int>&nums){
        // int n = nums.size() - 1;
        vector<int> dp(n, -1);
        
        if(n==2){
            return nums[1];
        }
        if(n==2){
            return max(nums[1], nums[2]);
        }

        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        int first = nums[1];
        int second = max(nums[2], nums[1]);

        // int ans =0;/

        // if(n==1){
        //     return dp[n];
        // }

        for(int i = 3 ; i < n ; i++){
            
            int ans = max(nums[i] + first, second);
            first = second;
            second = ans;



            // dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        int ans1 = find(nums.size() - 1, nums);
        int ans2 = find2(nums.size() , nums);
        return max(ans1, ans2);
    }
};