class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();int m = nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0 ; int r = n;
        int total = n + m;
        double ans = 0 , rem = 0;
        while(l<=r){
            int x = (l+r)/2;
            int y = (total+1)/2-x;
            int l1 =  ( x > 0 ? nums1[x-1] : INT_MIN);
            int l2 =  ( y > 0 ? nums2[y-1] : INT_MIN);
            int r1 =  ( x < n ? nums1[x] : INT_MAX);
            int r2 =  ( y < m ? nums2[y] : INT_MAX);
            if(l1<=r2 && l2<=r1){
                ans = max(l1,l2);
                if(total%2==0){
                    rem = min(r1,r2);
                }
                break;
            }
            else if(l1>r2){
                r = x-1;
            }
            else{
                l = x+1;
            }
            
        }
          if(total % 2 == 0) return (ans + rem)/2.0;
        return ans;
    }
};