class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
       
unordered_set<int>s;
for(auto x:mp){
    s.insert(x.second);
}

return s.size()==mp.size();
    }
};