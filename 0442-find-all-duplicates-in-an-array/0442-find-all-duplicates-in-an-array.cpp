class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num:nums){
                    mp[num]++;
        }

        vector<int>res;
        for(auto m:mp){
            if(m.second>1) res.push_back(m.first);
        }
        return res;
    }
};