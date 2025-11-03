class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        if(n==1){
            return ans;
        }
        char ch = colors[0];
        int summ = neededTime[0];
        int maxi = neededTime[0];
        for(int i = 1 ; i < colors.size(); i++){
            if(ch == colors[i]){
                summ+=neededTime[i];
                maxi = max(maxi, neededTime[i]);
                // count++;
            }
            else{
                ans += (summ-maxi);
                summ = neededTime[i];
                maxi= neededTime[i];
                ch = colors[i];
                // count = 0;
            }
        }
        return max(ans, ans+(summ-maxi));
    }
};