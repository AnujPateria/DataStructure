class Solution {
public:
    int climbStairs(int n) {
        if(n==2 || n==1){
            return n;
        }
        int x = 1;
        int y = 2;
        for(int i = 3 ; i <= n ;i++){
            int ans = x+y;
            x = y;
            y = ans;
        }
        return y;
    }
};