class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mp;
        //getting all the freq of string s
        for(char it:s){
            mp[it]++;
        }

        //
        for(char it:t){
            // check if already present , do a freq--;
            if(mp.find(it)!=mp.end() &&mp[it]>0){
                mp[it]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};