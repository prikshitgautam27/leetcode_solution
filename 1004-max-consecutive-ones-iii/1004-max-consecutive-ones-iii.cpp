class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int maxlen=0;
        int count_zeros=0;
        while(j<n){
            if(nums[j]==0) count_zeros++;

            while(count_zeros>k ){
                if(nums[i]==0) {count_zeros--;}

                i++;

            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};