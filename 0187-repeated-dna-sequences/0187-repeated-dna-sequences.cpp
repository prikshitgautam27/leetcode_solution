class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string>s_ans;
        if(s.length()<10){
return s_ans;
        }

        unordered_map<string ,int>freq;

        for(int i=0;i<=s.size()-10;i++){
                string sub=s.substr(i,10);
                freq[sub]++;

        if(freq[sub]==2){
            s_ans.push_back(sub);
        }

        }
        return s_ans;
    }
};