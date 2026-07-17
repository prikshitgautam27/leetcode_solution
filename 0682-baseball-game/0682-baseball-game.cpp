class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res=0;
        stack<int>st;
        for(auto it:operations){
            
             if(it=="C"){
                st.pop();
            }
            else if(it=="+"){
                    int first=st.top();st.pop();
                    int second=st.top();
                    st.push(first);
                    st.push(first+second);
            }
            else if(it=="D"){
                    int first=st.top();
                    
                    st.push(2*first);
            }
            else{
        st.push(stoi(it));
            }
        }

        while(!st.empty()){
res+=st.top();
st.pop();
        }
        
        return res;
    }
};