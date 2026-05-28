class Solution {
public:
    bool isSubsequence(string s, string s2) {
        
        int n=s.length();
        int m= s2.length();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1; j++){
                if(s[i-1]==s2[j-1]){
                    t[i][j]= 1+t[i-1][j-1];
                    
                }
                else{
                    t[i][j]= max(t[i-1][j] , t[i][j-1]);
                    
                }
            }
        }
        int lcslength = t[n][m];
        if(lcslength==s.length()){
            return true;
        }
        return false;
    }
};




