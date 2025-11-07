class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();
        for(int xx = 0 ; xx <= n-k ; xx++){
            int ans = 0;
            unordered_map<int, int> mpp;
            mpp.clear();
            for(int i = xx ; i < k+xx ; i++){
                mpp[nums[i]]++;
            }
            vector<pair<int, int >> vec(mpp.begin(), mpp.end());

            sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });

            for(int i = 0 ; i < min((int)vec.size(), x) ; i++)
            {
                ans+=(vec[i].first*vec[i].second);
            }
            res.push_back(ans);


        }
        return res;
        

    }
};