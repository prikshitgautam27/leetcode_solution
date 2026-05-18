#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // -1 = unvisited, 0 = false, 1 = true
    vector<vector<int>> memo;

    bool dp(int i, int j, const string& s, const string& p) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (j == p.length()) {
            return i == s.length();
        }

        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
        bool result = false;

        if (j + 1 < p.length() && p[j + 1] == '*') {
            result = dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p));
        } else {
            result = first_match && dp(i + 1, j + 1, s, p);
        }

        return memo[i][j] = result;
    }

public:
    bool isMatch(string s, string p) {
        memo.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dp(0, 0, s, p);
    }
};
