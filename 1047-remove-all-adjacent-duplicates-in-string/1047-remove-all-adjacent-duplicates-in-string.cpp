class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>st;
        string res="";
        for(auto it:s){
            
            if(st.empty()==false && st.top()==it){
                st.pop();
            }
            else{
                st.push(it);
            }

        }
        while(!st.empty()){
res.push_back(st.top());
st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};