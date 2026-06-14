class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            digitSum += temp;
            squareSum += (temp * temp);
            cout<<digitSum <<" "<<squareSum << endl;
        }
        return squareSum - digitSum >= 50;
    }
};