class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;
        for(int num : nums){
            XOR^=num;
        }
        int n = nums.size() - 2;
        for(int num = 0 ; num < n ; num++){
            XOR^=num;
        }
        int trailing_zeroes = __builtin_ctz(XOR);
        int mask = 1<<trailing_zeroes;

        int g1 = 0;
        int g2 = 0;
        for(int num : nums){
            if(num & mask){
                g1^=num;
            }
            else{
                g2^=num;
            }
        }
        for(int num = 0 ; num< n ; num++){
            if(num&mask){
                g1^=num;
            }
            else{
                g2^=num;
            }
        }
        vector<int> ans;
        ans.push_back(g1);
        ans.push_back(g2);
        return ans;
    }
};