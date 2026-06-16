class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result += s[i];
            }
            else if(s[i] == '#'){
                result += result;
            }
            else if(s[i] == '%'){
                reverse(result.begin(), result.end());
            }
            else {
                // int n = result.length();
                if(result.length() < 1){
                    continue;
                }
                result.pop_back();
            }
            
        }
        return result;
    }
};