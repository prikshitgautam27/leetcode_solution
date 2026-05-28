class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto it:points){
            
            int x=it[0], y= it[1];
            
            int dist= (x*x+y*y);
            
            maxh.push({dist,{x,y}});
            
            if(maxh.size()>k){
                maxh.pop();
            }
            
            
           
        }
        vector<vector<int>>res;
        while(!maxh.empty()){
            auto it= maxh.top();
            int dist= it.first;
            int x_cor=it.second.first;
            int y_cor=it.second.second;
            
            res.push_back({x_cor,y_cor});
            maxh.pop();
            
        }
        return res;
    }
};