class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        int count = 0;
        int prev = -1;
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            for(int j = n-1 ; j>=i ; j--){
                if(ch == s[j]){
                    count = max(j, count);
                    break;
                }
            }
            if(i == count){
                ans.push_back(count - prev);
                prev = count;
                // count = 0;
            }
        }
        return ans;

    }
};