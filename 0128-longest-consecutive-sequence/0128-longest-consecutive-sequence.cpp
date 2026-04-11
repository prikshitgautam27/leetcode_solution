class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Use a set for O(1) average lookups
        unordered_set<int> numset(nums.begin(), nums.end()); 
        int lgstr = 0; // Initialize result to 0

        for (int num : numset) {
            // Only start a sequence if 'num' is the beginning (no num-1)
            if (numset.find(num - 1) == numset.end()) {
                int curnum = num;
                int curstr = 1;

                while (numset.find(curnum + 1) != numset.end()) {
                    curnum += 1;
                    curstr += 1;
                }
                // Update max streak only when a full sequence is found
                lgstr = max(lgstr, curstr);
            }
        }
        return lgstr;
    }
};
