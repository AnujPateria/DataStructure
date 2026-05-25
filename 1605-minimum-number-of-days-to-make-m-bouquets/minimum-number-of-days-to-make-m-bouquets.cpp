class Solution {
public:

    bool isPossble(vector<int> &bloomDay, int m, int k, int mid){
        int count = 0;
        int ans = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            if((bloomDay[i] - mid) <= 0){
                count++;
                if(count == k){
                    ans++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
            
        }
        
        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (1LL*m*k)) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = right;

        while(left <= right){
            int mid = (left + right)/2;
            if(isPossble(bloomDay, m, k, mid)){
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;

    }
};