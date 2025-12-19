class Solution {
public:
    int fib(int n) {
        int x = 0 ;
        int y = 1 ;

        if(n==0 || n==1)
            return n;
        

        for(int i = 2 ; i <= n; i++){
            int ans  = x + y;
            x = y;
            y = ans;
        }
        return y;
    }
};