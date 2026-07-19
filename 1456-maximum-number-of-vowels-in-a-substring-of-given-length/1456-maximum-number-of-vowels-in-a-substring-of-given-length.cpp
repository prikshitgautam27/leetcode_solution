class Solution {
public:
    int maxVowels(string s, int k) {
        
int n=s.length();
int i=0;
int j=0;
int curvow=0;

int maxvowels=0;

   while(j<n){
       
            if(s[j]=='a' || s[j]=='e'|| s[j]=='i'||s[j]=='o'||s[j]=='u'){
                curvow++;
            }
            if(j-i+1==k){
                maxvowels=max(curvow,maxvowels);

            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u'){
                curvow--;
            }
            i++;
            }

       
j++;

   }

return maxvowels;
    }
};