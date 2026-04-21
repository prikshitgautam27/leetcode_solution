class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int start=0;
        backtrack(start, nums , subset , ans);
        return ans;
    }

    void backtrack(int start, vector<int>&nums,vector<int>&subset ,  vector<vector<int>>&ans ){
        ans.push_back(subset);// pushing empty subset to sol vector ans first

for(int i=start;i<nums.size();i++){
        // checking dup condition
        if(i>start && nums[i] == nums[i-1]) continue;

        // inc element
        subset.push_back(nums[i]);
        backtrack(i+1,nums, subset , ans);
        subset.pop_back(); // to  exc lastelement element : condition for backtrack
}
    }
};