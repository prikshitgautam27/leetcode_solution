1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> result;
5        sort(nums.begin(), nums.end());  // Step 1: Sort the array
6
7        int n = nums.size();
8        for (int i = 0; i < n - 2; i++) {
9            // Skip duplicate values for the first number
10            if (i > 0 && nums[i] == nums[i - 1]) continue;
11
12            int left = i + 1;
13            int right = n - 1;
14
15            while (left < right) {
16                int sum = nums[i] + nums[left] + nums[right];
17
18                if (sum == 0) {
19                    result.push_back({nums[i], nums[left], nums[right]});
20
21                    // Skip duplicates for left and right
22                    while (left < right && nums[left] == nums[left + 1]) left++;
23                    while (left < right && nums[right] == nums[right - 1]) right--;
24
25                    left++;
26                    right--;
27                }
28                else if (sum < 0) {
29                    left++;  // Need a bigger number
30                }
31                else {
32                    right--;  // Need a smaller number
33                }
34            }
35        }
36
37        return result;
38    }
39};