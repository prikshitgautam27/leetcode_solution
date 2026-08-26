class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<long long>>dp(n,vector<long long>(m,0));
        // base case ->obstacle in start
        if(obstacleGrid[0][0]==1) return 0;
       dp[0][0]=1;






        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;// obstacle is their , so now way ossible
                }
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];// i>0 prevent out of bound errors
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }

        }
        return dp[n-1][m-1];
    }
};