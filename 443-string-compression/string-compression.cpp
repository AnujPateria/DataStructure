class Solution {
public:
    int compress(vector<char>& chars) {
        // string s;
        int n = chars.size();
        int count = 1;
        int seq = 0;
        for(int i = 1 ; i < chars.size(); i++){
            if(chars[i-1] == chars[i]){
                count++;
            }
            else{
                if(count == 1){
                    chars[seq++] = chars[i-1];
                }
                else{
                    chars[seq++] = chars[i-1];
                    string s = to_string(count);
                    int idx = 0;
                    while(idx < s.length()){
                        chars[seq++] = s[idx++];
                    }
                }
                count = 1;
            }
        }
        if(count == 1){
            chars[seq++] = chars[n-1];
        }
        else{
            chars[seq++] = chars[n-1];
            string s = to_string(count);
            int idx = 0;
            while(idx < s.length()){
                chars[seq++] = s[idx++];
            }
        }
        
        
        return seq;
    }
};