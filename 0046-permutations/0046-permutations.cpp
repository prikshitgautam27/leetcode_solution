class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>list1;
        permutation(nums,ans,list1);
        return ans;

    }
    void permutation(vector<int>&nums, vector<vector<int>>&ans, vector<int>&list1){
        if(list1.size()==nums.size()){
            ans.push_back(list1);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(list1.begin(),list1.end(),nums[i])!=list1.end()){
                continue;
            }
                list1.push_back(nums[i]);
                permutation(nums,ans,list1);
                list1.pop_back();
        }
    }
};