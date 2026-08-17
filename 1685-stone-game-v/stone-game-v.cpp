class Solution {
public:
    vector<int> pref;
    vector<vector<int>> dp;
    


    int solve(int st, int en){
        if(st >= en) return 0;
        if(dp[st][en] != -1){
            return dp[st][en];
        }
        int ans = 0;
        for(int mid = st; mid < en; mid++){
            int leftSum = pref[mid+1] - pref[st];
            int rightSum = pref[en+1] - pref[mid + 1];
            if(leftSum == rightSum){
                ans = max(ans, leftSum + max(solve(st , mid), solve(mid + 1, en)));
            }
            else if(leftSum > rightSum){
               ans = max(ans, rightSum + solve(mid + 1, en));
            }
            else{
                ans = max(ans, leftSum + solve(st, mid));
            }
        }
        return dp[st][en] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n+1, 0);
        dp.assign(n, vector<int> (n, -1));
        for(int i = 0 ; i< n; i++){
            pref[i+1] = pref[i] + stoneValue[i];
        }
        return solve(0, n-1);

    }
};