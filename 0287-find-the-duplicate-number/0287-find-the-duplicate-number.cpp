class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>dup;
        for(int i=0;i<nums.size();i++){
            dup[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(dup[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};