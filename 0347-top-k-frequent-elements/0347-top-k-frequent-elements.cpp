class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequency machine
        unordered_map<int,int>fm;
        for(int i=0;i<nums.size();i++){
            fm[nums[i]]++;
        }

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;


for(auto & p:fm){
    min_heap.push({p.second,p.first});
    if(min_heap.size()>k){
        min_heap.pop();
    }


}

// heap stores pairs as {frequency, number}

        vector<int>res;
         while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
         }
        
 return res;
    }
};