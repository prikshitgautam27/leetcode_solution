class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;

for(int i=0;i<words.size();i++){
    freq[words[i]]++;
}
        // comparator to sort
   auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            if(a.second == b.second) {
                return a.first < b.first; // reverse lexicographic for min-heap
            }
            return a.second > b.second;   // higher freq has higher priority
        };

priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(comp)> pq(comp);

for(auto it: freq){
    pq.push(it);
    if(pq.size()>k){
        pq.pop();
    }

    vector<string>res;
    while(!pq.empty()){
        res.push_back(pq.top().first);
        pq.pop();
    }
}


  return res;
    }
};