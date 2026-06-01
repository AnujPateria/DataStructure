class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        for(int i = 1 ; i < nums.size(); i++){
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};