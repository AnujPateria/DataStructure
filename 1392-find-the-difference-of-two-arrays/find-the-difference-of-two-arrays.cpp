class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>mp(nums2.begin(), nums2.end());
        vector<int> ans1;
        for(int x: nums1){
            if(mp.find(x) == mp.end()){
                ans1.push_back(x);
                mp.insert(x);
            }
        }
        unordered_set<int>mpp(nums1.begin(), nums1.end());
        vector<int> ans2;
        for(int x: nums2){
            if(mpp.find(x) == mpp.end()){
                ans2.push_back(x);
                mpp.insert(x);
            }
        }
        return {ans1,ans2};
    }
};