class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        // long long sum = 0;÷
        // long long nn = n;
        while(true){
            long long sum = 0;
            while(n>=1){
                int temp = n % 10;
                n = n/10;
                sum = 1LL*sum + 1LL*pow(temp,2);
            }

            
            mp[sum]++;
            n = sum;
            cout<<n<<" ";
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