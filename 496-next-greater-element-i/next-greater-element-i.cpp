class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        int m = n2.size();
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i = 0 ; i < m ; i++){
            int ch = -1;
            while(!st.empty() && n2[st.top()] < n2[i]){
                ch = st.top();
                mpp[n2[ch]] = n2[i]; 
                st.pop();
            }
            if(st.empty() || n2[st.top()] > n2[i]){
                st.push(i);
            }
            // for(int j = ch ; j < st.top(); j++){
            //     mpp[n2[j]] = n2[st.top()];
            // }
        }
        for(auto i : mpp){
            cout<<i.first <<" "<<i.second<<endl;
        }
        for(int i = 0 ; i < n ; i++){
            if(mpp.find(n1[i]) != mpp.end()){
                ans.push_back(mpp[n1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};