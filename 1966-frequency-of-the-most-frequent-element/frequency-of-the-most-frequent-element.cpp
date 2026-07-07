class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0;
        int ans = 1;
        int count = 1;
        long long temp = 0;
        sort(nums.begin(), nums.end());
 
        for(int right = 1; right < nums.size(); right++){
            temp += 1LL * (nums[right] - nums[right - 1]) * count;
            count++;
            while(temp > k){
                temp -= (nums[right] - nums[left]);
                count--;
                left++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};