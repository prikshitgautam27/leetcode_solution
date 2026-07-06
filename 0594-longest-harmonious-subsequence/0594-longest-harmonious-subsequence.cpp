class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;
int maxlen=0;
        for(auto it:nums){
            freq[it]++;
        }

        for(auto it: freq){
            int num=it.first;
            int count=it.second;

            if(freq.count(num+1)){
                  maxlen=max(maxlen,count+freq[num+1]);

            }
        }
        return maxlen;
    }
};