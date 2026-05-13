class Solution {
public:
    bool isUgly(int n) {
        vector<int> primes = {2,3,5};
        if(n<= 0) return false;
        
        for(int p : primes){
            while(n%p == 0) {
                n/=p;
            }
        }

        return n == 1;

        // we are checking for a number is this is perfect or not
    }
};