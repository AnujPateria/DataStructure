class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        int left = 0, maxcnt = 0;
        for(int right = 0 ; right < nums.size(); right++){
            while(nums[right] - nums[left] >= n){
                left++;
            }
            maxcnt = max(maxcnt , right - left + 1);
        }
        return n - maxcnt;

    }
};