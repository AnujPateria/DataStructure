class Solution {
public:

    // bool check(int i, int j, vector<int> &nums){
    //     if(nums[i] > 2*nums[j]) return true;
    //     return false;
    // }

    vector<pair<int, int> > vec;
    int count = 0;

    void merge(int st, int mid, int en){

        int j = mid + 1;
        for(int i = st ; i<=mid ; i++){
            while(j<=en && (long long)vec[i].first > 2LL * vec[j].first){
                j++;
            }
            count += (j-(mid+ 1));
        }


        int i = st;
         j = mid + 1;
        vector<pair<int, int> > temp(en - st + 1);
        int k= 0;
        while(i<=mid && j<=en){
            if(vec[i].first <= vec[j].first){
                temp[k++] = vec[i++];
            }
            else{
                temp[k++] = vec[j++];
            }
        }
        while(i<=mid){
            temp[k++] = vec[i++];
        
        }
        while(j<=en){
            temp[k++] = vec[j++];
        }
        for(int i = st ; i <= en; i++){
            vec[i] = temp[i - st];
        }

    }

    void mergesort(int st, int en){
        if(st >= en){
            return;
        }
        int mid = (st + en)/2;
        mergesort(st , mid);
        mergesort(mid + 1, en);
        merge(st, mid, en);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        // vec.resize(n);
        for(int i = 0 ; i < n; i++){
            vec.push_back({nums[i], i});
        }
        mergesort(0, n-1);
        return count;
    }
};