class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;int n = nums.size();
        int count = 0;
        for(int num : nums){
            XOR^=num;
            if(count<n-2){
            XOR^=count;}
            count++;
        }
        
        int trailing_zeroes = __builtin_ctz(XOR);
        int mask = 1<<trailing_zeroes;

        int g1 = 0;
        int g2 = 0;
        count = 0;
        for(int num : nums){
            if(num & mask){
                g1^=num;
            }
            else{
                g2^=num;
            }
            if((mask & count) && count < n - 2){
                g1^=count;
            }
            else if(count<n-2){
                g2^=count;
            }
            count++;
        }
        vector<int> ans;
        ans.push_back(g1);
        ans.push_back(g2);
        return ans;
    }
};