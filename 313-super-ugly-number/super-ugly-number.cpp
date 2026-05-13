class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> index(k, 0);
        // priority_queue<int, vector<int> , greater<int> > pq;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            long long min_ele = INT_MAX;
            // int prime_idx = -1;
            for(int j = 0 ; j < k; j++){
                if(min_ele > 1LL*primes[j]*dp[index[j]]){
                    min_ele = 1LL * primes[j] * dp[index[j]];
                }
            }

            dp[i] = min_ele;
          
            for(int j = 0 ; j < k ; j++){
                if(min_ele == 1LL*dp[index[j]] * primes[j]){
                    index[j]++;
                }
            }

        }
        return dp[n-1];

    }
};