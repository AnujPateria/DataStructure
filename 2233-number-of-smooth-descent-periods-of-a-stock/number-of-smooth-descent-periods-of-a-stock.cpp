// #define int long long
class Solution {
public:

    long long sum_n(int n){
        return (1LL*n*(n+1))/2;
    }

    long long getDescentPeriods(vector<int>& prices) {
        
        int count = 1;
        long long ans = 0;
        // int check = prices[0];
        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i] == prices[i-1] - 1){
                count++;
            }
            else{
                ans+=(sum_n(count));
                count = 1;
            }
        }

        ans+=(sum_n(count));
        return ans;


    }
};