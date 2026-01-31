class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int idx, vector<int>&nums, bool check,int prev ){
        if(idx == nums.size()){
            
            return 0;
        }
        if(dp[idx][prev+1][check] != -1){
            return dp[idx][prev+1][check];
        }
        int notTake = solve(idx + 1,nums, check, prev);
        int take = 0;
        if(prev == -1 || (nums[idx] > nums[prev] && check ) || (nums[idx] < nums[prev] && !check) ){
            // check = !check;
            take = 1 + solve(idx + 1, nums, !check, idx);
        }
        return dp[idx][prev+1][check] = max(take, notTake);
    }


    int wiggleMaxLength(vector<int>& nums) {
        int idx = 0;
        bool check = true;
        dp.resize(nums.size(), vector<vector<int>>(nums.size()+1,vector<int>(2,-1)));
        // if(nums.size() == 1){
        //     return 1;
        // }
        return max(solve(idx, nums, check, -1), solve(idx, nums, !check, -1));
    }
};