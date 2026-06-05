class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n= s.length();
        int k= p.length();

        vector<int>ans;
        if(k>n) return ans;// empty

        unordered_map<char,int> m;
        for(int i=0;i<k;i++){
            m[p[i]]++;
        }

        int count= m.size();
        int i=0;
// expanding the window
        for(int j=0;j<n;j++){
            if(m.find(s[j]) !=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count --;
                }
            }

            if(j-i+1 == k){
                if(count ==0)
                ans.push_back(i);
            
            // expand window
            if(m.find(s[i]) != m.end()){
                if(m[s[i]]==0){
                    count++;
                }
                m[s[i]]++;
            }
            i++;
            
            }
            
        }



        return ans;
    }
};