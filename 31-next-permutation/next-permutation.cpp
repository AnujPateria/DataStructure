class Solution {
public:

    void sortArray(vector<int> &nums, int st, int en){
        for(int i = st; i < en; i++){
            for(int j = i + 1; j<=en; j++){
                if(nums[i] > nums[j]){
                    cout<<nums[i]<<" "<<nums[j]<<endl;
                    swap(nums[i], nums[j]);
                }
            }
        }
    }

    void checkIndex(vector<int> &nums, int st, int en){
        // bool check = false;
        for(int i = en; i>=1; i--){
            if(nums[i] > nums[i-1]){
                int max_ele = i;
                
                for(int j = en; j>=i ; j--){
                    if(nums[i-1] < nums[j] && nums[max_ele] > nums[j]){
                        max_ele = j;
                    }
                }
                cout<<nums[i-1]<<endl<<nums[max_ele]<<endl;
                cout<<nums[i]<<endl;
                swap(nums[i-1], nums[max_ele]);  // just greater than i- 1 then swap with that element;
                cout<<nums[i-1]<<endl<<nums[max_ele];
                sortArray(nums, i, en);
                return;
            }
        }
        sort(nums.begin(), nums.end());

    }

    void nextPermutation(vector<int>& nums) {
        checkIndex(nums, 0, nums.size() - 1);

    }
};