class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>mset;
        
        for(int it : nums){
            if(mset.find(it)!=mset.end()){
                return true;
            }
            else{
                mset.insert(it);
            }
        }
        return false;
    }
};