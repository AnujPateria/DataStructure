class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost = 0;
        int modu = 1e9 + 7;
        int temp = k;
        for(int i = 0 ;i < nums.size(); i++){
            if(temp >= nums[i]) {
                temp-=nums[i];
            }
            else{
                int rem = nums[i] / k;
                int mod = nums[i] % k;
                
                if(mod  > temp){
                    rem++;
                }else if(mod == 0 && temp == k) rem--;
                temp += (k*rem);
                cost += 1LL * rem;
                temp-=nums[i];
            }
        }
        const long long MOD = 1e9 + 7;
const long long inv2 = 500000004;

return ((1LL * cost % MOD) * ((cost + 1) % MOD) % MOD) * inv2 % MOD;


    }
};