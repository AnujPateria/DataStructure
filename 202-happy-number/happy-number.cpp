class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while(true){
            int sum = 0;
            while(n>=1){
                int temp = n % 10;
                n = n/10;
                sum = sum + pow(temp,2);
            }

            
            mp[sum]++;
            n = sum;
            if(sum == 1){
                break;
            }
            if(mp[sum] > 1){
                return false;
            }
            
        }
        return true;
    }
};