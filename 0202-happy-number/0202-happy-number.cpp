
class Solution {
public:
    // Helper function to calculate the sum of squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        
        // If there's a cycle, the fast runner will eventually meet the slow runner.
        // If it's a happy number, the fast runner will reach 1 first.
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);          // Moves 1 step
            fastRunner = getNext(getNext(fastRunner)); // Moves 2 steps
        }
        
        return fastRunner == 1;
    }
};