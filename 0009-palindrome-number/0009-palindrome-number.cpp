class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself)
        // are not palindromes.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // For even lengths: x == revertedNumber
        // For odd lengths: x == revertedNumber / 10 (removes middle digit)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
