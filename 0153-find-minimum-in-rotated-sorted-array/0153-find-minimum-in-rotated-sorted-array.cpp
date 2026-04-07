class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // 1. Changed i < j to low < high
        while (low < high) {
            // 2. Fixed formula: low + (high - low) / 2
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum must be in the right half
                low = mid + 1;
            } else {
                // Minimum is mid or in the left half
                high = mid;
            }
        }

        return nums[low];
    }
};
