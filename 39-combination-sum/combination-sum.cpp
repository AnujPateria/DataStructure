#define vcc vector<vector<int>> 
#define vc vector<int> 

class Solution {
public:

    void solve(vc num , int tar, vcc &ans, vc sub, int curr, int i){
        if(curr == tar){
            ans.push_back(sub);
            return;
        }
        if(curr > tar || i >= num.size()){
            // sub.pop_back();
            // curr-=num[i];
            return;
        }

        sub.push_back(num[i]);
        // curr+=;
        solve(num , tar, ans, sub, curr + num[i], i);
        sub.pop_back();

        solve(num, tar, ans, sub , curr, i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(c, t, ans, sub, 0, 0);
        return ans;
    }
};