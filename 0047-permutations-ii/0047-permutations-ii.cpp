class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
sort(nums.begin(),nums.end());
        vector<bool>vis(nums.size(),false);
        vector<vector<int>>ans;
        vector<int>list;
        pu(nums,ans,list,vis);

        return ans;

        

    }
    void pu(vector<int>& nums,vector<vector<int>>&ans,vector<int>&list,vector<bool>&vis){
// like if our list size is same as our nums array size
        if(nums.size()==list.size()){
            ans.push_back(list);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]){
                continue;
            }
        if(i>0 && nums[i]==nums[i-1] && !vis[i-1]){
            continue;
        }

        vis[i]=true;
        list.push_back(nums[i]);
        pu(nums,ans,list,vis);
        list.pop_back();
        vis[i]=false;
        


        
        }
    }

};