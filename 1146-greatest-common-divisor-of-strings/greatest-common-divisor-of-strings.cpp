class Solution {
public:

    

    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int i = 0 , j = 0;
        string lar , sml ;
        if(n1 >= n2){
            lar = str1;
            sml = str2;
        }
        else{
            lar = str2;
            sml = str1;
        }
        string ans = "";
        string temp = "";
        for(int i = 0;i < sml.length(); i++){
            temp+=sml[i];
            bool check = true;
            for(int j = 0; j < lar.length(); j+=temp.length()){

                if(temp != lar.substr(j,temp.length())){
                    check = false;
                    break;
                }

            }
            for(int j = 0 ; j < sml.length(); j+=temp.length()){
                if(temp != sml.substr(j,temp.length())){
                    check = false;
                    break;
                }
            }
            if(check){
                ans = temp;
            }

        }
        return ans;
    }
};