class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int temp = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '1') temp++;
        }
        int ans = temp;
        int a = 0;
        int b = 0;
        bool flag = false;
        bool check = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1' && check) {
                continue;
            }
            if(s[i] == '0' && flag == false){
                a++;
            }
            else if(s[i] == '1'){
                check = true;
                if(flag == false){
                    flag = true;
                }
                else{
                    if(a != 0 && b != 0){
                    ans = max(ans, a + b + temp);}
                    a = b;
                    b = 0;
                }
            }
            else{
                check = false;
                b++;
            }
        }
        if(a != 0 && b != 0){
            ans = max(ans, a + b + temp);
        }
        return ans;
    }
};