class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Calculate expected sum of 0 to n
        long long expectedSum = (long long)n * (n + 1) / 2;
        
        long long actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        return (int)(expectedSum - actualSum);
    }
};
