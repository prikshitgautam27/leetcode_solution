class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;   // store reversed bits
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;       // get last bit of n
            result = (result << 1) | bit; // shift result left, add bit
            n >>= 1;               // move to next bit
        }
        return result;
    }
};
