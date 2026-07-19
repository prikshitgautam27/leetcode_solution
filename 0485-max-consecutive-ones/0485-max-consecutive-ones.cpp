class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length=0;
        int maxcount=0;
int i=0;int j=0;
int n=nums.size();
       while(j<n){
          if (nums[j]==1){
           
        maxcount=max(maxcount,j-i+1);
          }
          else {
            
           i=j+1;
          }
          j++;
       }


        return maxcount;
    }
};