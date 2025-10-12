class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.length();
        
        for(int i = 0 ;i < n ; i++){
        std::unordered_map<char, int > mpp;
        for(int j = i ; j < n ; j++){
            char ch = s[j];
            mpp[ch]++;
            
            int min_freq = INT_MAX;
            int max_freq = 0;
            
            for(const auto &pair : mpp){
                int current_freq = pair.second;
                min_freq = min(min_freq, current_freq);
                max_freq = max(max_freq, current_freq);
            }
            
            if(min_freq == max_freq){
                ans = std::max(ans , j-i+1);
            }
        }
        }
        return ans;
    }
    

        
    
};