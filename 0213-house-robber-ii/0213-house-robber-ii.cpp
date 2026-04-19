class Solution {
public: 
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n==1) return nums[0];
          return max(linear_rob(nums,1,n-1),linear_rob(nums,0,n-2));


    }
    private:
    int linear_rob(vector<int>nums,int left,int right){
        int prev2=0,prev1=0;
        for(int i=left;i<=right;i++){
            int cur=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=cur;
        }
return prev1;
    }
};