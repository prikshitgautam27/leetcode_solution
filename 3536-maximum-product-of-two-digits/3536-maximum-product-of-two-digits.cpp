class Solution {
public:
    int maxProduct(int n) {
        int first=INT_MIN;
        int second=INT_MIN;

        while(n!=0){
            int num=n%10;
           if(num>first){
            second=first;
            first=num;
           }
           else if(num>second){
            second=num;
           }
            n=n/10;
        }
return first*second;
    }
};