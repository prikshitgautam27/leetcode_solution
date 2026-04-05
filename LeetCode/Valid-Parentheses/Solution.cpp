1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;
5        for (auto it:s){
6            if(it=='('||it=='{'||it=='['){
7                st.push(it);}
8             else{
9                    if(st.empty()) return false;
10                    char ch=st.top();
11                    st.pop();
12                    if((it==')' and ch=='(') or (it=='}' and ch=='{') or (it==']' and ch=='[')){
13                        continue;
14                    }
15                    else return false;
16                }
17            }
18                    return st.empty();
19
20        }
21        
22    };