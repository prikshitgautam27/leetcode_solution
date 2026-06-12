class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        
        vector<int>color(n,-1);
       

        

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfscheck(i, graph, color)== false){
                    return false;
                }
            }
        }

       return true; 
    }

    bool bfscheck(int node,vector<vector<int>>&graph,vector<int>&color ){
        
        queue<int>q;
        color[node]=0;
        q.push(node);

        while(!q.empty()){
            int frontnode= q.front();
            q.pop();

            for(auto& nei:graph[frontnode]){
                if(color[nei]==-1){
                    color[nei]= !color[frontnode];
                    q.push(nei);
                }
                else if(color[nei]==color[frontnode]){
                    return false;
                }
            }
        }
        return true;
    }
};