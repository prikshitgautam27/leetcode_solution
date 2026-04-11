class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numset(nums.begin(),nums.end());
        int lgstr=0;

        for(int num:numset){
                if(numset.find(num-1)==numset.end()){
                    int curnum=num;
                    int curstr=1;
                    while(numset.find(curnum+1)!=numset.end()){
                        curnum+=1;
                        curstr+=1;
                    }
                     lgstr=max(lgstr,curstr);
                }

            


        }
        return lgstr;

    }
};