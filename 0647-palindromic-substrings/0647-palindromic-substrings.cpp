class Solution {
public:
    int countSubstrings(string s) {
        int totalCount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // 1. Odd length: center is a single character (e.g., "aba")
            totalCount += expand(s, i, i);
            
            // 2. Even length: center is between two characters (e.g., "abba")
            totalCount += expand(s, i, i + 1);
        }
        
        return totalCount;
    }

private:
    int expand(string s, int left, int right) {
        int count = 0;
        // Expand as long as pointers are in bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};
