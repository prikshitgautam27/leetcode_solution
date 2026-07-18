class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(char ch:stones){
            mp[ch]++;
        }
        int count=0;

        for(char it:jewels){
            if(mp.find(it)!=mp.end()){
                count+=mp[it];
            }
        }

        return count;
    }
};