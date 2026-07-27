class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string curstr="";
        int num=0;
        
        for(auto c:s){
            if(isdigit(c)){
                num=num*10 +(c-'0');

            }
            else if(c=='['){
                st.push({curstr,num});
                curstr="";
                num=0;
            }
            else if(c==']'){
                string laststr=st.top().first;
                int mult=st.top().second;
                st.pop();
                string expstr="";
                for(int i=0;i<mult;i++){
                    expstr +=curstr;
                }
                curstr=laststr+expstr;

            }
            else{
                curstr+=c;
            }
        }

        return curstr;
    }
};