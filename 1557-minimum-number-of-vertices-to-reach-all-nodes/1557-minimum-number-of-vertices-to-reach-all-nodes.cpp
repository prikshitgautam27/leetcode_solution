class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    // calculating the indegree
        vector<int>indegree(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            indegree[v]++;
        }
        // calculating the result from nodes having the indegree 0
        vector<int>res;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};