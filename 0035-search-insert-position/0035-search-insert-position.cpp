class Solution {
public:
int binary(vector<int>& arr, int x){
      int l = 0;
    int r = arr.size()-1;
    while (l <= r) {
        int mid =l+(r-l)/2;

        if (arr[mid]==x)
            return mid;

        if (arr[mid]<x)
            l = mid+1;
        else{
            r=mid-1;
        }

}
   return l;
    }
 


    int searchInsert(vector<int>& nums, int target) {
        int res= binary(nums, target);
        return res;
    }
};