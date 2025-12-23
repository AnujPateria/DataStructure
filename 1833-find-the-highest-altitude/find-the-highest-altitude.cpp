class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> vec(n+1);
        vec[0] = 0;
        int max_val = 0;
        for(int i = 0 ; i < n ; i++){
            vec[i+1] += vec[i] + gain[i];
            max_val = max(max_val, vec[i+1]);
        }
        return max_val;
    }
};