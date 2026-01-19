class Solution {
public:
    vector<vector<int>> dp;
    int dfs( int n , vector<int> & coins, int amount){
        if(amount == 0) {
            return 0;
        }
        if(n <= 0){
            return 1e9;
        }
        if(dp[amount][n-1] != -1){
            return dp[amount][n-1];
        }
        int take = 1e9;
        if(coins[n-1] <= amount){
            // count++;
            take = 1+ dfs( n, coins, amount- coins[n-1]);
        }
        int notTake = dfs(n - 1, coins, amount);
        return dp[amount][n-1] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        int count = 0;
        dp.assign(amount + 1, vector<int> (n+1, -1));
        int res = dfs(n, coins, amount);

        if (res  == 1e9) return -1;
        return res;
    }
};