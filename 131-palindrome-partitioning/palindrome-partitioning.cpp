class Solution {
public:
    vector<vector<int>> dp;
    bool check(int st, int en, string &s){
        if(st >= en) {
            return true;
        }
        if(dp[st][en] != -1){
            return dp[st][en];
        }
        if(s[st] != s[en]) {
            return dp[st][en] = 0;
        }
        return dp[st][en] = check(st+1, en-1, s);
    }

    void solve(int idx, string &s, vector<vector<string>>&ans, vector<string> &temp){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i < s.length(); i++){
            if(check(idx, i, s)){
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        dp.assign(s.length(), vector<int> (s.length() , -1));
        vector<vector<string>> vec;
        vector<string> temp ;
        solve(0, s, vec, temp);
        return vec;
    }
};