class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first_non_zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                    nums[first_non_zero]=nums[i];
                    first_non_zero++;
            }
        }

        for(int i=first_non_zero;i<nums.size();i++){

            nums[i]=0;

        }

        
    }
};