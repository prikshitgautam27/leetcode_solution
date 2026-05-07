class Solution {
public:
    int hammingWeight(int n) {
        int count;

        while(n){
            count+=(n & 1);

            n = n>>1;
        }
        return count;
    }
};