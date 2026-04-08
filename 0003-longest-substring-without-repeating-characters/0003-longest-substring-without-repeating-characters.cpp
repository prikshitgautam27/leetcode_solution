class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each character (ASCII 0-127)
        vector<int> lastIndex(128, -1);
        int maxLength = 0;
        int start = 0; // Left boundary of the sliding window

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            
            // If the character was seen before and is within the current window
            if (lastIndex[currentChar] >= start) {
                // Move the start of the window to one position past the previous occurrence
                start = lastIndex[currentChar] + 1;
            }

            // Update the last seen index of the character
            lastIndex[currentChar] = end;
            
            // Calculate the current window length and update the maximum
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
