class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j = 0;
        int product = 1;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            product = product * nums[i];

            while(product >= k && j <= i){
                product = (product/nums[j]);
                j++;
            }
            ans += (i-j+1);
        }
      
        return ans ;
    }
};