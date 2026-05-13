class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int i2 = 0 , i3 = 0, i4 = 0;
        for(int i = 1 ; i < n ; i++){
            int next1 = dp[i2] * 2;
            int next2 = dp[i3] * 3;
            int next3 = dp[i4] * 5;

            dp[i] = min({next1, next2, next3});
            if(dp[i] == next1) i2++;
            if(dp[i] == next2) i3++;
            if(dp[i] == next3) i4++;
        }
        return dp[n-1];
    }
};