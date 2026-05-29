class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long > pref(n + 1, 0);
        // pref[0] = 0;

        for(int i = 0 ; i < n ; i++){
            pref[i + 1] = pref[i] + nums[i];
        }
        int ans = n + 1;
        for(int i = 0 ; i <= n ; i++){
            while(!dq.empty() && pref[i] - pref[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && pref[i] <= pref[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;

    }
};