class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>minh;
int n=nums.size();
        for(auto num:nums){
       minh.push({num.length(),num});
       if(minh.size()>k){
        minh.pop();
       }
        }
        return minh.top().second;
    }
};