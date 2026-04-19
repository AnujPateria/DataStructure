class Solution {
public:

    vector<vector<int>> dp;
    bool solve(int i, int j , string &s){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1, j-1, s);
        }
        return dp[i][j] = false;


    }

    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 0;
        dp.assign(n, vector<int> (n,-1));
        int st = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solve(i, j, s)){
                    if(j-i+1 > max_len){
                        st = i;
                        max_len = j-i+1;
                    }
                }
            }
        }
        return s.substr(st, max_len);
    }
};