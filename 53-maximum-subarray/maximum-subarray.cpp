class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, curr_sum = 0;
        int min_ele = INT_MIN;
        for(int i=0 ; i < nums.size(); i++){
            min_ele = max(nums[i], min_ele);
            curr_sum+=nums[i];
            if(curr_sum < 0 ) {
                curr_sum = 0;
            }
            ans = max(ans , curr_sum);
        }
        return ans == 0 ? min_ele : ans;
    }
};