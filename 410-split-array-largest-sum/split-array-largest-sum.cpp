class Solution {
public:

    bool solve(vector<int> &nums, int k, int mid){
        int count = 1;
        int sum = 0;
        for(int num : nums){
            if(num + sum <= mid){
                sum+=num;
            } else {
                count++;
                sum = num;
            }
        }
        return count <= k;

    }

    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(), nums.end());
        int en = 0;
        for(int num : nums) en+=num;

        int ans = en;
        while(st <= en){
            int mid = (st+en)/2;
            if(solve(nums, k, mid)){
                ans = mid; 
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};