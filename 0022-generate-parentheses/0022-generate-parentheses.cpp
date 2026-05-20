class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: if the string length is 2*n, we found a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening bracket, add it
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // If we have more opening brackets than closing, we can add a closing bracket
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};