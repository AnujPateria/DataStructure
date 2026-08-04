
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = -1;
        for(int i = 0 ;i< nums.size() - 1; i++){
            for(int j = i+1; j< nums.size(); j++){
                long long mul = 1LL * nums[i] * nums[j];
                long long gcdNo = 1LL * gcd(nums[i], nums[j]);
                ans = max(ans, mul / (gcdNo * gcdNo));
            }
        }return ans;
    }
};