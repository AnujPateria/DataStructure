class Solution {
public:

    vector<pair<int, int> > vec;
    vector<int> count;

    void merge(int i, int mid, int j){
        vector<pair<int, int> > temp(j - i + 1);
        int k = 0;
        int st = i;
        int en = mid + 1; //i
        while(st<=mid && en<=j){
            if(vec[st].first <= vec[en].first){
                temp[k++] = vec[en++];
            }
            else{
                count[vec[st].second] += (j - en + 1);
                temp[k++] = vec[st++];
            }
        }
        while(st <= mid){
            temp[k++] = vec[st++];
        }
        while(en<=j){
            temp[k++] = vec[en++];
        }
        for(int a = i ; a <= j ; a++){
            vec[a] = temp[a - i];
        }
    }

    void mergesort(int i, int j){
        if(i>=j) return;
        int mid = (i+j)/2;
        mergesort(i, mid);
        mergesort(mid + 1, j);
        merge(i, mid, j);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            vec.push_back({nums[i], i});
        }
        count = vector<int> (n, 0);

        mergesort(0, n-1);
        return count;
    }
};