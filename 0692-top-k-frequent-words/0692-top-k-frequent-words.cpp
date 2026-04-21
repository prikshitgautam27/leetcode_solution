class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;

for(int i=0;i<words.size();i++){
    freq[words[i]]++;
}
// converting freq {{'i',2},{}} to vector [('i',2),()]
vector<pair<string,int>>vec(freq.begin(),freq.end());
        // comparator to sort
    sort(vec.begin(),vec.end(),[](const auto&a,const auto&b){
        if(a.second==b.second) return a.first < b.first; 
        return a.second > b.second ;

    });



    // extracting top freq string
    vector<string>res;// res string vector
for(int i=0;i<k;i++){
res.push_back(vec[i].first);
}
return res;
    }
};