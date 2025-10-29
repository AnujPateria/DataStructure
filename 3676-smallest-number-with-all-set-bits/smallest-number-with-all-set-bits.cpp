class Solution {
public:
    int smallestNumber(int n) {
        int ans;
        for(int i = 1 ; i <= 8  ; i++){
            if(pow(2,i) > n){
                ans = pow(2,i) -1;
                break;
            }
        }
        return ans;

    }
};