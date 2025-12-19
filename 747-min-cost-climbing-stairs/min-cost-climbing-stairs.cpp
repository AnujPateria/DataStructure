class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // vector<int> dp(n+1, -1);

        int x = cost[0];
        int y = cost[1];
      
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++){
            int temp = cost[i] + min(x,y);
            x = y;
            y = temp;
            // dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(x,y);

    }
};