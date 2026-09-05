class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int n=a.size();
        int m=b.size();
       int repeat=(m+n-1)/n;
string repeated="";
        for(int i=0;i<repeat;i++) repeated+=a;

//string::npos simply means “not found”.

//So repeated.find(b) != string::npos means “b exists inside repeated”.
        if(repeated.find(b)!= string::npos) return repeat;
        repeated+=a;
        if(repeated.find(b)!= string::npos) return repeat+1;

        return -1;
    }
};