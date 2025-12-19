class Solution {
public:
    int dep(int n , vector<int> &dp){

        if(n==0 || n==1){return n;}

        

        return dp[n-1] = dep(n-1, dp) + dep(n-2,dp);
    }

    int fib(int n) {
        vector<int> dp(n+1);
        return dep(n, dp);
        // return dp[n];
    }
};