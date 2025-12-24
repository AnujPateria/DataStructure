class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int temp = 0;
        for(int i = 0 ; i < apple.size(); i++){
            temp+=apple[i];
        }
        sort(capacity.begin(),capacity.end(), greater<int>());
        for(int i = 0 ; i < capacity.size(); i++){
            temp-=capacity[i];
            if(temp<=0){
                return i+1;
            }
        }
        return capacity.size();
    }
};