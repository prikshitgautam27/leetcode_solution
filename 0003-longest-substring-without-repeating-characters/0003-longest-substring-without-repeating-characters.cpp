class Solution {
public:
    int lengthOfLongestSubstring(string s) { // Note: LeetCode uses 'lengthOfLongestSubstring'
        unordered_map<char, int> map;

        int mx = 0; // LeetCode sets empty string output to 0
        int i = 0, j = 0;
        int n = s.size();
        
        while (j < n) {
            map[s[j]]++; // 1. Calculation
            
            // Condition 1: All characters in the current window are unique
            if (map.size() == j - i + 1) {
                mx = max(mx, j - i + 1);
                j++;
            }
            // Condition 2: Window size is greater than unique map size (Duplicates exist!)
            else if (map.size() < j - i + 1) {
                while (map.size() < j - i + 1) {
                    map[s[i]]--;
                    if (map[s[i]] == 0) {
                        map.erase(s[i]);
                    }
                    i++; // Shrink window
                }
                j++;
            }
        }
        return mx;
    }
};
