class Solution {
public:
    vector<int> dp;
    int solve(int i, int n, string s){
        if(i == n){
            return 1;
        }
        if(s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int ways = 0;
        // if((s[i]) != '0'){
            ways += solve(i+1, n, s);
        // }
        if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1]  <= '6'))){
            ways += solve(i+2, n, s);
        }
        return dp[i]=ways;
    }

    int numDecodings(string s) {
        dp.assign(s.length(), -1);
        return solve(0, s.length(), s);
    }
};