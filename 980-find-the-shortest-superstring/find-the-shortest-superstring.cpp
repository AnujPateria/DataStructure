class Solution {
public:

    int getOverlap(string &s1, string &s2){
        int len = min(s1.size(), s2.size());
        for(int k = len; k >= 1; k--){
            bool possible = true;
            for(int i = 0 ; i < k; i++){
                if(s1[s1.size() - k + i] != s2[i]){
                    possible = false;
                    break;
                }
            }
            if(possible) {return k;}
        }
        return 0;
    }

    int tsp(int mask, int curr, vector<vector<int>> &overlp, vector<vector<int>> &dp){
        int n = overlp.size();
        if(mask == (1 << n ) - 1){
            return 0;
        }
        if(dp[curr][mask] != -1){
            return dp[curr][mask];
        }
        int ans = 0;
        for(int i = 0; i< n; i++){
            if((mask & (1 << i)) == 0){
                ans = max(ans, overlp[curr][i] + tsp(mask | (1 << i), i, overlp, dp));
            }
        }
        return dp[curr][mask] = ans;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlp(n, vector<int> (n, 0));

        //for overlap
        for(int i = 0 ;i< n ; i++){
            for(int j= 0 ;j < n ; j++){
                if(i != j){
                    overlp[i][j] = getOverlap(words[i], words[j]);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int> (1<<n, -1));
        int bestOverlp = -1;
        int st = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = tsp(1 << i, i, overlp, dp);
            if(curr > bestOverlp){
                bestOverlp = curr;
                st = i;
            }
        }

        string ans = words[st];
        int mask = 1 << st;
        int curr = st;
        while(mask != (1 << n) -1){
            int bestNext = -1;
            int bestVal = -1;
            for(int next = 0; next < n; next++){
                if(mask & (1 << next)) continue;
                int newMask = mask | (1<<next);
                int val = overlp[curr][next] + tsp(newMask, next, overlp, dp);
                if(val > bestVal){
                    bestVal = val;
                    bestNext = next;
                }
            }
            int comman = overlp[curr][bestNext];
            ans += words[bestNext].substr(comman);
            mask |= (1 << bestNext);
            curr = bestNext;
        }
        return ans;
    } 
};
