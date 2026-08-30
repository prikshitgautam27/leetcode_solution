class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0;
        int j=s.length();

        while(l<j){
            if(isalpha(s[l]) && isalpha(s[j])){
            swap(s[l],s[j]);
            l++;
            j--;
            }

            if(!isalpha(s[l])){
                    l++;
            }
            if(!isalpha(s[j])){
                    j--;
            }
        }
        return s;
    }
};