class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counts[26] = {0}; // Fixed array for O(1) space

        // Populate counts from the magazine
        for (char c : magazine) {
            counts[c - 'a']++;
        }

        // Check if ransomNote can be built
        for (char c : ransomNote) {
            if (--counts[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};