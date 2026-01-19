class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int n, int amount, vector<int> coins )
    {
        if( amount == 0) return 1;
        if(n==0) return 0;
        if(dp[amount][n-1]!=-1){
            return dp[amount][n-1];
        }
        int take = 0;
        if(amount >= coins[n-1])
        {
            take = dfs(n, amount- coins[n-1], coins);
        }
        int notTake = dfs(n-1, amount, coins);
        return dp[amount][n-1] = take + notTake;

    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(amount+1, vector<int> (n+1, -1));
        return dfs(n, amount, coins);
    }
};