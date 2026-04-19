class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        int n=s.size();
        int prev2=1;// dp[0]=1 base case : if string is empty
        int prev1=1;// dp[1]=1 base case : if only 1 char is present 

        for(int i=2;i<=n;i++){
            int cur=0;
            // logic to handle 1
            if(s[i-1]!='0'){
                cur+= prev1;

            }
            // logic 2 handle 2
            int two=stoi(s.substr(i-2,2));
            if(two>=10 && two <= 26){
                cur+=prev2;

            }
            prev2=prev1;
            prev1=cur;




        }
        return prev1;
    }
};