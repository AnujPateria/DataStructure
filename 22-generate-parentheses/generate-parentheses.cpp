class Solution {
public:

    bool isValid(string s){
        stack<char>  st;
        // st.push(s[0]);
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }

    vector<string> generateParenthesis(int n) {
        string st;
        string en;
        for(int i = 0 ; i < n ; i++){
            st+='(';
            en+=')';
        }
        st+=en;
        sort(st.begin(), st.end());
        vector<string> vec;
        // vector<string> ans;
        do{
            if(isValid(st))
                vec.push_back(st);
        }
        while(next_permutation(st.begin(), st.end()));
        // for(int i = 0 ; i < vec.size(); i++){
        //     if(isValid(vec[i])){

        //     }
        //     cout<<vec[i]<<" ";
        // }
        return vec;
    }
};