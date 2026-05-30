class Solution {
public:

    bool kSplit(int mid, int k, vector<int> &nums, int &ans){
        int curr = 0;
        int count = 1;
        // int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            curr += nums[i];
            if(curr > mid){
                count++;
                curr = nums[i];
            }
            ans = max(ans, curr);
        }
        return count <= k;

    }

    int splitArray(vector<int>& nums, int k) {
        int st = *min_element(nums.begin(), nums.end());
        int en = 0;
        for(int i = 0 ; i< nums.size(); i++){
            en+=(nums[i]);
        }
        int ans = 0;
        while(st <= en){
            int mid = (st + en)/2;
            int temp = 0;
            if(kSplit(mid, k, nums, temp)){
                ans = temp;
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};