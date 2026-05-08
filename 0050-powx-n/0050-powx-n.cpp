class Solution {
public:
    double myPow(double x, int n) {
        


        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }

        double result = 1;
        double product = x;

        while(N>0){
            if(N%2==1)
            {
            result *= product;
            }
            product = product *product;
            N=N/2;
        }
        return result;
    }
};