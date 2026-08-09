class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int idx, int m, vector<int> &piles){
        if(idx>= piles.size()) return 0;

        if(dp[idx][m] != -1) return dp[idx][m];

        int ans = 0;

        for(int x = 1; x <= 2*m && x < piles.size(); x++){
            int newM = max(m, x);

            int taken = suffix[idx] - solve(idx + x, newM, piles);

            ans = max(ans, taken);
        }

        return dp[idx][m] = ans;

    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int> (n+1, -1));
        suffix.assign(n+1, 0);
        
        for(int i = n-1; i>= 0; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }
        if(piles.size() <= 2 ){
            return suffix[piles.size() - 1];
        }

        return (solve(0, 1, piles));
    }
};