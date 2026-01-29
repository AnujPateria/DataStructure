class Solution {
public:
    vector<vector<pair<int, int>>> dp;
    pair<int, int>  dfs(int idx, vector<int>&nums, int n, int prev, int &lcs, int count, int &ans){
        if(n == idx){
            return {0,1};
            // if(lcs < count){
            //     lcs = count;
            //     ans = 1;
            // }
            // else if(lcs == count){
            //     ans = ans+1;
            // }
            // return;
        }
        if(dp[idx][prev+1].first != -1){
            return dp[idx][prev + 1];
        }
        //NotTake;
        auto notTake = dfs(idx+1, nums, n, prev, lcs, count, ans);
        //Take
        pair<int, int>  take = {0,0};
        if(prev == -1 || nums[prev] < nums[idx]){
            
            auto next = dfs(idx+1, nums, n, idx, lcs, count+1, ans);
            take.first = next.first + 1;
            take.second = next.second;   
        }
        pair<int, int> res;
        if(take.first > notTake.first){
            res = take;
        }
        else if(take.first < notTake.first){
            res = notTake;
        }
        else{
            res.first = take.first;
            res.second = take.second+notTake.second;
        }
        return dp[idx][prev+1] = res;
        // return;
    }


    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0;
        int lcs = 0;
        int n = nums.size();
        int sum = (n*(n-1)) / 2;
        dp.assign(n + 1, vector<pair<int, int>> (n+1, {-1, -1}));
        return dfs(0, nums, nums.size(), -1, lcs, 0, ans).second;
        // return ans;
    }
};