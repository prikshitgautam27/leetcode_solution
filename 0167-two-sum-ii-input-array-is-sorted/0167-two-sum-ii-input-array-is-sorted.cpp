class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum=0;
        int i=0;
        int j=numbers.size()-1;

        while(i<=j){
             sum=numbers[i]+numbers[j];
            if(sum==target){
                return {i+1,j+1};
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};