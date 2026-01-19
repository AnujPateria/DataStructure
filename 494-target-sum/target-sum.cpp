class Solution {
public:

    int dfs(int n, vector<int> &nums,int curr, int target){
        if( n == 0 ){
            return curr == target;
        }
        int take = dfs(n-1, nums, curr + nums[n-1], target);
        int notTake = dfs(n-1, nums, curr - nums[n-1], target);
        return take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int curr = 0;
        return dfs(n, nums, curr, target);
    }
};