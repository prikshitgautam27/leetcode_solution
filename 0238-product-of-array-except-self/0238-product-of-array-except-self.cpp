class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        int product=1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                product*=nums[i];
            }
        }
vector<int>res(n,0);
        if(count>1){
            return res;
        }
        if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    res[i]=product;
                }
            }
            return res;
        }

        for(int i=0;i<n;i++){
            res[i]=product/nums[i];
        }
        return res;
    }
};