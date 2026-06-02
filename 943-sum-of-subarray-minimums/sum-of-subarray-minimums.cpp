class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = 1e9 + 7;
        int n = arr.size();
        vector<int> next_sml(n, n), prev_sml(n, -1);

        vector<long long> dp(n, 0);

        stack<long long> st;
        for(int i = 0 ; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                next_sml[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i = n - 1; i >=0; i--){
            long long temp = 0;
            if(next_sml[i] != n){
                temp = dp[next_sml[i]];
            }
            dp[i] = 1LL*arr[i] * (next_sml[i] - i) + temp;
        }
        long long ans = 0;
        for(int num : dp){
            ans+=(num );
        }
        return ans%mod;
        

        return -1;
        

    }
};